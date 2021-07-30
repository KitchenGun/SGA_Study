#include "stdafx.h"
#include "TileMap.h"
#include "TileSet.h"

TileMap::TileMap(Vector3 position, Vector3 size, float rotation)
	:position(position),size(size),rotation(rotation)
{
	tileSet = new TileSet();

	spacing = 40;
	//타일 한칸의 가로 세로 크기
	width = WinMaxWidth/spacing;
	height = WinMaxHeight/spacing;

	GenerateTileMap(width, height, spacing);
	//40픽셀씩으로 되어있는거임
	vertices.assign(4, VertexTextureColor());
	vertices[0].position = Vector3(0, 0, 0);
	vertices[0].uv = Vector2(0, 1);

	vertices[1].position = Vector3(0, (float)spacing, 0);
	vertices[1].uv = Vector2(0, 0);

	vertices[2].position = Vector3((float)spacing, 0, 0);
	vertices[2].uv = Vector2(1, 1);
	
	vertices[3].position = Vector3((float)spacing, (float)spacing, 0);
	vertices[3].uv = Vector2(1, 0);
	//검정색으로 출력됨
	vertices[0].color = Color(0, 0, 0, 1);
	vertices[1].color = Color(0, 0, 0, 1);
	vertices[2].color = Color(0, 0, 0, 1);
	vertices[3].color = Color(0, 0, 0, 1);

	indices = { 0,1,2,2,1,3 };

	VB = new VertexBuffer();
	IB = new IndexBuffer();

	VS = new VertexShader();
	PS = new PixelShader();

	IL = new InputLayout();

	VB->Create(vertices, D3D11_USAGE_DYNAMIC);
	IB->Create(indices, D3D11_USAGE_IMMUTABLE);

	shaderPath = L"./_Shaders/VertexTile.hlsl";
	VS->Create(shaderPath, "VS");
	PS->Create(shaderPath, "PS");
	
	IL->Create(VertexTextureColor::descs, VertexTextureColor::count, VS->GetBlob());

	WB = new WorldBuffer();
	D3DXMatrixIsIdentity(&world);

	//rs
	{
		D3D11_RASTERIZER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_RASTERIZER_DESC));

		desc.CullMode = D3D11_CULL_BACK;
		desc.FillMode = D3D11_FILL_SOLID;
		desc.FrontCounterClockwise = false;

		DEVICE->CreateRasterizerState(&desc, &RS);
	}
	//wireframe
	{
		D3D11_RASTERIZER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_RASTERIZER_DESC));

		desc.CullMode = D3D11_CULL_BACK;
		desc.FillMode = D3D11_FILL_WIREFRAME;
		desc.FrontCounterClockwise = false;

		DEVICE->CreateRasterizerState(&desc, &wireframeRS);
	}
	//원본파일 넣어줌
	srv = tileSet->tileSprite->GetSRV();
}

TileMap::~TileMap()
{
	SAFE_DELETE_ARRAY(tiles);
	SAFE_DELETE(tileSet);

	SAFE_RELEASE(wireframeRS);
	SAFE_RELEASE(RS);

	SAFE_DELETE(WB);

	SAFE_DELETE(IL);

	SAFE_DELETE(PS);
	SAFE_DELETE(VS);

	SAFE_DELETE(IB);
	SAFE_DELETE(VB);
}

void TileMap::SetShader(wstring shaderPath)
{
	if (VS)
	{
		VS->Clear();
		VS->Create(shaderPath, "VS");
	}
	if (PS)
	{
		PS->Clear();
		PS->Create(shaderPath, "PS");
	}
}

void TileMap::Update()
{
	if (Mouse::Get()->Press(0))
	{
		//마우스 클릭 위치를 받아옴
		Vector3 mPos = Mouse::Get()->GetPosition();
		Tile* tile = GetTile(mPos);
		if (tile)
		{
			//tileset에서 선택한 tile을 그려넣겠다.
			tile->uvStart = tileSet->selectedStartUv;
			tile->uvEnd = tileSet->selectedStartUv + tileSet->texelTileSize;
		}
	}
}

void TileMap::Render()
{
	VB->SetIA();
	IB->SetIA();
	IL->SetIA();
	DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	VS->SetShader();

	if (Keyboard::Get()->Down(VK_01))
		DC->RSSetState(RS);
	else if (Keyboard::Get()->Down(VK_02))
		DC->RSSetState(wireframeRS);

	PS->SetShader();

	if (srv)
		DC->PSSetShaderResources(0, 1, &srv);

	for (UINT y = 0; y < height; y++)
	{
		for (UINT x = 0; x < width; x++)
		{
			Tile& tile = tiles[y][x];
			{
				D3D11_MAPPED_SUBRESOURCE subResource;

				DC->Map(VB->GetResource(), 0, D3D11_MAP_WRITE_DISCARD, 0, &subResource);
				{
					vertices[0].uv = Vector2(tile.uvStart.x, tile.uvEnd.y);
					vertices[1].uv = tile.uvStart;
					vertices[2].uv = tile.uvEnd;
					vertices[3].uv = Vector2(tile.uvEnd.x, tile.uvStart.y);

					memcpy(subResource.pData, vertices.data(), sizeof(VertexTextureColor) * vertices.size());
				}
				DC->Unmap(VB->GetResource(), 0);

				D3DXMatrixTranslation(&world, tile.pos.x + position.x, tile.pos.y + position.y, 0);
				WB->SetWorld(world);
				WB->SetVSBuffer(0);

				DC->DrawIndexed(IB->GetCount(), 0, 0);
			}
		}
	}
}

void TileMap::GUI()
{
	tileSet->GUI();

	static bool bOpen = true;
	if (ImGui::Begin("TileMap", &bOpen))
	{
		if (ImGui::Button("Save", ImVec2(50, 30)))
			SaveTileMap();

		if (ImGui::Button("Load", ImVec2(50, 30)))
			LoadTileMap();
	}
	ImGui::End();
}

void TileMap::GenerateTileMap(UINT width, UINT height, UINT spacing)
{
	if (width == 0 || height == 0 || spacing == 0)
	{//값이 제대로 넘어오지 않으면 리턴
		ASSERT(false);
		return;
	}
	//준 공간 만큼 타일의 위치를 저장
	tiles = new Tile*[height];  //각 요소 마다 접근
	for (UINT y = 0; y < height ; y++)
	{
		tiles[y] = new Tile[width];
		for (UINT x = 0; x < width ; x++)
		{
			//position정해주는거임
			tiles[y][x].pos.x = (float)(x*spacing);
			tiles[y][x].pos.y = (float)(y*spacing);
			tiles[y][x].pos.z = 0.0f;

			tiles[y][x].color = Color(0.0f, 0.0f, 0.0f, 0.0f);
			tiles[y][x].uvStart = Vector2(0.0f, 0.0f);
			tiles[y][x].uvEnd = Vector2(0.0f, 0.0f);
		}
	}
}

Tile * TileMap::GetTile(Vector3 worldMousePos)
{
	//마우스 위치가지고 타일 위치 받아오기
	UINT x = ((int)worldMousePos.x + (int)Camera::Get()->GetPosition().x - WinMaxWidth / 2) / spacing;
	UINT y = ((int)worldMousePos.y + (int)Camera::Get()->GetPosition().y - WinMaxHeight / 2) / spacing;

	if (x >= width || y > height || x < 0, y < 0)
		return nullptr;
	return &tiles[y][x];
}

void TileMap::SaveTileMap(const wstring & path)
{
	if (path.length() < 1)
	{
		function<void(wstring)> func = bind(&TileMap::SaveTileMap, this, placeholders::_1);
		Path::SaveFileDialog(L"", Path::TileMapFilter, L"./", func, handle);
	}
	else
	{
		if (!tiles) return;
		FileStream* out = new FileStream(String::ToString(path), FILE_STREAM_WRITE);
		out->Write(width);
		out->Write(height);

		for (UINT y = 0; y < height; y++)
		{
			for (UINT x = 0; x < width; x++)
			{
				out->Write(tiles[y][x]);
			}
		}
		SAFE_DELETE(out);
	}
}

void TileMap::LoadTileMap(const wstring & path)
{
	if (path.length() < 1)
	{
		function<void(wstring)> func = bind(&TileMap::LoadTileMap, this, placeholders::_1);
		Path::OpenFileDialog(L"", Path::TileMapFilter, L"./", func, handle);
	}
	else
	{
		if (!tiles) return;

		FileStream* in = new FileStream(String::ToString(path), FILE_STREAM_READ);
		width = in->Read<UINT>();
		height = in->Read<UINT>();

		for (UINT y = 0; y < height; y++)
		{
			for (UINT x = 0; x < width; x++)
			{
				tiles[y][x] = in->Read<Tile>();
			}
		}

		SAFE_DELETE(in);
	}
}
