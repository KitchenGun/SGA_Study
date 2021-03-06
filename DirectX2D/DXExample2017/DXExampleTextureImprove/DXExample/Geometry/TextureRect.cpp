#include "stdafx.h"
#include "TextureRect.h"

TextureRect::TextureRect(Vector3 position, Vector3 size, float rotation)
	:
	position(position),
	size(size),
	rotation(rotation)
{
	//정점 정보 입력
	vertices.assign(4, VertexTexture());
	vertices[0].position = Vector3(-0.5f, -0.5f, 0.0f);
	vertices[0].uv = Vector2(0.0f, 1.0f);

	vertices[1].position = Vector3(-0.5f, 0.5f, 0.0f);
	vertices[1].uv = Vector2(0.0f, 0.0f);

	vertices[2].position = Vector3(0.5f, -0.5f, 0.0f);
	vertices[2].uv = Vector2(1.0f, 1.0f);

	vertices[3].position = Vector3(0.5f, 0.5f, 0.0f);
	vertices[3].uv = Vector2(1.0f, 0.0f);

	indices = { 0,1,2,2,1,3 };

	//클래스화 한 객체 생성
	VB = new VertexBuffer();
	IB = new IndexBuffer();

	VS = new VertexShader();
	PS = new PixelShader();

	IL = new InputLayout();

	WB = new WorldBuffer();

	//객체에서 함수 호출
	VB->Create(vertices, D3D11_USAGE_DYNAMIC);
	IB->Create(indices, D3D11_USAGE_IMMUTABLE);

	VS->Create(L"./_Shaders/VertexTexture.hlsl", "VS");
	PS->Create(L"./_Shaders/VertexTexture.hlsl", "PS");

	IL->Create(VertexTexture::descs, VertexTexture::count, VS->GetBlob());

	D3DXMatrixIdentity(&world);

	D3DXMatrixIdentity(&S);
	D3DXMatrixIdentity(&R);
	D3DXMatrixIdentity(&T);

	D3DXMatrixScaling(&S, size.x, size.y, size.z);
	D3DXMatrixRotationZ(&R, (float)D3DXToRadian(rotation));
	D3DXMatrixTranslation(&T, position.x, position.y, position.z);

	world = S * R * T;

	WB->SetWorld(world);
	//기존의 colorbuffer대신 사용
	SB = new SelectBuffer();
	//blur 기능 생성자
	BB = new BlurBuffer();
	LB = new LocalBuffer();
	//좌상단 우상단 좌표
	LB->SetLocalRect({ 100,100,400,400 });
}

TextureRect::~TextureRect()
{
	SAFE_DELETE(LB);
	SAFE_DELETE(BB);
	SAFE_DELETE(SB);

	SAFE_DELETE(WB);

	SAFE_DELETE(IL);

	SAFE_DELETE(PS);
	SAFE_DELETE(VS);

	SAFE_DELETE(IB);
	SAFE_DELETE(VB);
}

void TextureRect::SetSRV(wstring path)
{
	//텍스쳐가 쉐이더에 접근 할 수 있게 함
	ViewFactory::GenerateSRV(path, &srv);
}

void TextureRect::SetShader(wstring shaderPath)
{
	//vs와ps객체에 함수 호출// 실행중간에 교체할수있도록 함수화 하였음
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

void TextureRect::Move(Vector3 position)
{
	this->position += position;
	D3DXMatrixTranslation(&T, this->position.x, this->position.y, this->position.z);

	world = S * R * T;
	WB->SetWorld(world);
}

void TextureRect::MoveLocalRect(Vector4 localMove)
{	//정점정보를 전달하여 이동을 처리함
	LB->MoveLocalRect(localMove);
}

void TextureRect::Update()
{
	if (Keyboard::Get()->Down(VK_00))
	{
		BB->SetCount(1);
	}
	else if (Keyboard::Get()->Down(VK_01))//1번 누르면 selection값이 바뀜
	{
		SB->SetSelection(1);
		BB->SetCount(2);
	}
	else if(Keyboard::Get()->Down(VK_02))
	{
		SB->SetSelection(2);
		BB->SetCount(4);
	}
	else if(Keyboard::Get()->Down(VK_03))
	{
		SB->SetSelection(3);
		BB->SetCount(8);
	}
	else if (Keyboard::Get()->Down(VK_04))
	{
		SB->SetSelection(4);
		BB->SetCount(32);
	}

}

void TextureRect::Render()
{
	VB->SetIA();
	IB->SetIA();
	IL->SetIA();
	//기본 도형 형성 방법 지정
	DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	WB->SetVSBuffer(0);
	VS->SetShader();

	PS->SetShader();
	if (srv)
	{
		DC->PSSetShaderResources(0, 1, &srv);
	}
	SB->SetPSBuffer(0);//ps단계에서 사용하는 첫번째 값이여서 0으로 입력해도됨
	//블러효과위해서 추가함
	BB->SetPSBuffer(1);
	LB->SetPSBuffer(2);
	//인덱스 버퍼를 이용해서 그리기
	DC->DrawIndexed(IB->GetCount(), 0, 0);
}
