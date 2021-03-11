#include "stdafx.h"
#include "Execute.h"
#include "Graphics.h"

Execute::Execute()
{
	graphics = new Graphics();
	graphics->Initialize();
	graphics->CreateBackBuffer(static_cast<uint>(Settings::Get().GetWidth()), static_cast<uint>(Settings::Get().GetHeight()));
	//vertex_data 정점을 시계방향으로 찍어야함
	{
		vertices = new VertexTexture[4];
		vertices[0].position = D3DXVECTOR3(-0.5f, -0.5f, 0.0f);//0
		vertices[0].uv = D3DXVECTOR2(0.0f, 1.0f);

		vertices[1].position = D3DXVECTOR3(-0.5f, 0.5f, 0.0f);//1
		vertices[1].uv = D3DXVECTOR2(0.0f, 0.0f);

		vertices[2].position = D3DXVECTOR3(0.5f, -0.5f, 0.0f);//2
		vertices[2].uv = D3DXVECTOR2(1.0f, 1.0f);

		vertices[3].position = D3DXVECTOR3(0.5f, 0.5f, 0.0f);//3
		vertices[3].uv = D3DXVECTOR2(1.0f, 0.0f);
	}
	//vertex_buffer
	{
		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));
		desc.Usage = D3D11_USAGE_IMMUTABLE;
		desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		desc.ByteWidth = sizeof(VertexTexture) * 4;

		D3D11_SUBRESOURCE_DATA sub_data;//cpu 데이터를 gpu에 연결할수있다.
		ZeroMemory(&sub_data, sizeof(D3D11_SUBRESOURCE_DATA));
		sub_data.pSysMem = vertices;

		auto hr = graphics->GetDevice()->CreateBuffer(&desc, &sub_data, &vertex_buffer);
		assert(SUCCEEDED(hr));
	}
	//Index Data
	{
		indices = new uint[6]{ 0,1,2,2,1,3 };

	}
	//Index Buffer
	{
		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));
		desc.Usage = D3D11_USAGE_IMMUTABLE;//Gpu 읽기만 가능 CPU접근 불가능
		desc.BindFlags = D3D11_BIND_INDEX_BUFFER;
		desc.ByteWidth = sizeof(uint) * 6;

		D3D11_SUBRESOURCE_DATA sub_data;
		ZeroMemory(&sub_data, sizeof(D3D11_SUBRESOURCE_DATA));
		sub_data.pSysMem = indices;
		auto hr = graphics->GetDevice()->CreateBuffer(&desc, &sub_data, &index_buffer);
		assert(SUCCEEDED(hr));
	}
	//Vertex Shader
	{//함수로 hlsl을 컴파일 할 예정
		auto hr = D3DX11CompileFromFileA
		(
			"Texture.hlsl",
			nullptr,
			nullptr,
			"VS",
			"vs_5_0",
			0,
			0,
			nullptr,
			&vs_blob,
			nullptr,
			nullptr
		);
		assert(SUCCEEDED(hr));

		hr = graphics->GetDevice()->CreateVertexShader(vs_blob->GetBufferPointer(), vs_blob->GetBufferSize(), nullptr, &vertex_shader);
		assert(SUCCEEDED(hr));
	}
	//Input Layout  //hlsl과 정보가 다를 경우 터진다.
	{
		//D3D11_INPUT_ELEMENT_DESC layout_desc[]
		//{
		//	{"POSITION",0,DXGI_FORMAT_R32G32B32_FLOAT,0,0,D3D11_INPUT_PER_VERTEX_DATA,0 },
		//	{"COLOR",0,DXGI_FORMAT_R32G32B32A32_FLOAT,0,12,D3D11_INPUT_PER_VERTEX_DATA,0 },
		//};
		D3D11_INPUT_ELEMENT_DESC layout_desc[]
		{
			{"POSITION",0,DXGI_FORMAT_R32G32B32_FLOAT,0,0,D3D11_INPUT_PER_VERTEX_DATA,0 },
			{"TEXCOORD",0,DXGI_FORMAT_R32G32_FLOAT,0,12,D3D11_INPUT_PER_VERTEX_DATA,0 },
		};

		auto hr = graphics->GetDevice()->CreateInputLayout(layout_desc, 2, vs_blob->GetBufferPointer(), vs_blob->GetBufferSize(), &input_layout);
		assert(SUCCEEDED(hr));
	}
	//Pixel Shader
	{
		auto hr = D3DX11CompileFromFileA
		(
			"Texture.hlsl",
			nullptr,
			nullptr,
			"PS",
			"ps_5_0",
			0,
			0,
			nullptr,
			&ps_blob,
			nullptr,
			nullptr
		);
		assert(SUCCEEDED(hr));
		hr = graphics->GetDevice()->CreatePixelShader(ps_blob->GetBufferPointer(), ps_blob->GetBufferSize(), nullptr, &pixel_shader);
		assert(SUCCEEDED(hr));
	}
	//Create World View Projection  //단위행렬 항등행렬 만드는중
	{
		D3DXMatrixIdentity(&world);
		D3DXMatrixIdentity(&view);
		D3DXMatrixIdentity(&projection);

		//D3DXMatrixLookAtLH(&view, &D3DXVECTOR3(0, 0, 0), &D3DXVECTOR3(0, 0, 1), &D3DXVECTOR3(0, 1, 0));
		D3DXMatrixOrthoLH(&projection, Settings::Get().GetWidth(),Settings::Get().GetHeight(),0,1);
		//D3DXMatrixOrthoOffCenterLH(&view, 0, Settings::Get().GetWidth(), 0 ,Settings::Get().GetHeight(), 0, 1);
		//위에쪽과 다르게 y축이 달라진다

		//perspective	3d 원근감이 느껴짐
		//orthographic	2d 원금감이 없음

		std::cout << "View Matrix" << std::endl;
		std::cout << view._11 << " " << view._12 << " " << view._13 << " " << view._14 << std::endl;
		std::cout << view._21 << " " << view._22 << " " << view._23 << " " << view._24 << std::endl;
		std::cout << view._31 << " " << view._32 << " " << view._33 << " " << view._34 << std::endl;
		std::cout << view._41 << " " << view._42 << " " << view._43 << " " << view._44 << std::endl;
		
		std::cout << std::endl;

		std::cout << "Projection Matrix" << std::endl;
		std::cout << projection._11 << " " << projection._12 << " " << projection._13 << " " << projection._14 << std::endl;
		std::cout << projection._21 << " " << projection._22 << " " << projection._23 << " " << projection._24 << std::endl;
		std::cout << projection._31 << " " << projection._32 << " " << projection._33 << " " << projection._34 << std::endl;
		std::cout << projection._41 << " " << projection._42 << " " << projection._43 << " " << projection._44 << std::endl;

		std::cout << std::endl;
		//World
		{
			D3DXMATRIX S;
			D3DXMatrixScaling(&S, 500, 500, 1); //크기만 키움 누적 x
			std::cout << "Scaling Matrix" << std::endl;
			std::cout << S._11 << " " << S._12 << " " << S._13 << " " << S._14 << std::endl;
			std::cout << S._21 << " " << S._22 << " " << S._23 << " " << S._24 << std::endl;
			std::cout << S._31 << " " << S._32 << " " << S._33 << " " << S._34 << std::endl;
			std::cout << S._41 << " " << S._42 << " " << S._43 << " " << S._44 << std::endl;
			std::cout << std::endl;
			
			D3DXMATRIX T;
			D3DXMatrixTranslation(&T, 0, 0, 0);//위치만 이동 누적 x

			std::cout << "Translation Matrix" << std::endl;
			std::cout << T._11 << " " << T._12 << " " << T._13 << " " << T._14 << std::endl;
			std::cout << T._21 << " " << T._22 << " " << T._23 << " " << T._24 << std::endl;
			std::cout << T._31 << " " << T._32 << " " << T._33 << " " << T._34 << std::endl;
			std::cout << T._41 << " " << T._42 << " " << T._43 << " " << T._44 << std::endl;
			std::cout << std::endl;

			D3DXMATRIX R;
			D3DXMatrixRotationZ(&R, static_cast<float>(D3DXToRadian(45)));//위치만 이동 누적 x

			std::cout << "RotationZ Matrix" << std::endl;
			std::cout << R._11 << " " << R._12 << " " << R._13 << " " << R._14 << std::endl;
			std::cout << R._21 << " " << R._22 << " " << R._23 << " " << R._24 << std::endl;
			std::cout << R._31 << " " << R._32 << " " << R._33 << " " << R._34 << std::endl;
			std::cout << R._41 << " " << R._42 << " " << R._43 << " " << R._44 << std::endl;
			std::cout << std::endl;

			//스케일(S) * 자전회전(R) * 이동(T) * 공전(R) * 부모행렬(P)
			world = S */*  R */ T; //행렬을 교환법칙이 성립하지 않는다\
			//ctrl k c 사용하는법
		}
	}

	//Create Constant Buffer
	{
		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));
		desc.Usage = D3D11_USAGE_DYNAMIC;//동적 cpu - Write //gpu - Read
		desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;//상수버퍼라는 의미
		desc.ByteWidth = sizeof(TRANSFORM_DATA);
		desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		
		auto hr = graphics->GetDevice()->CreateBuffer(&desc, nullptr, &gpu_buffer);
		assert(SUCCEEDED(hr));
	}
	//Create Rasterizer State
	{
		D3D11_RASTERIZER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_RASTERIZER_DESC));
		desc.FillMode = D3D11_FILL_SOLID;//색을 채우는 방식
		desc.CullMode = D3D11_CULL_BACK;//cullmode  어떤 면을 보이지 않게 할것인가에 대한 정보
		desc.FrontCounterClockwise = false;//시계방향으로 도는것을 앞면으로 할것인가 아니면 반시계로 할것인가?
		//dx에서는 통상적으로 시계방향을 앞면으로 사용
		//true 반시계방향이 앞면 //false 시계방향이 앞면 
		//cliping
		//카메라에 보이지 않으면 그리고 데이터를 잘라내는것
		//culling
		//카메라에 보이지 않으면 그리기전에 데이터를 잘라내는것
		auto hr = graphics->GetDevice()->CreateRasterizerState(&desc, &rasterizer_state);
		assert(SUCCEEDED(hr));
	}
	//Create Shader Resource View
	{
		//auto hr = D3DX11CreateShaderResourceViewFromFileA
		//(
		//	graphics->GetDevice(),
		//	"Marco.png",
		//	nullptr,
		//	nullptr,
		//	&shader_resource[0],
		//	nullptr
		//);
		//assert(SUCCEEDED(hr));
		//hr = D3DX11CreateShaderResourceViewFromFileA
		//(
		//	graphics->GetDevice(),
		//	"BackGround.png",
		//	nullptr,
		//	nullptr,
		//	&shader_resource[1],
		//	nullptr
		//);
		//assert(SUCCEEDED(hr));
		auto hr = D3DX11CreateShaderResourceViewFromFileA
		(
			graphics->GetDevice(),
			"Marco.png",
			nullptr,
			nullptr,
			&shader_resource,
			nullptr
		);
		assert(SUCCEEDED(hr));
	}
	//Create Sampler State
	{
		D3D11_SAMPLER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_SAMPLER_DESC));
		desc.AddressU = D3D11_TEXTURE_ADDRESS_BORDER;
		desc.AddressV = D3D11_TEXTURE_ADDRESS_BORDER;
		desc.AddressW = D3D11_TEXTURE_ADDRESS_BORDER;
		//외각선
		desc.BorderColor[0] = 1;
		desc.BorderColor[1] = 0;
		desc.BorderColor[2] = 0;
		desc.BorderColor[3] = 1;
		//이전과 현재 데이터를 비교하는 방법을 정하는 플래그
		desc.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
		desc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;//min축소 mag확대 mip밉맵   //linear 선형   //pointer 도트 비선형
		desc.MaxAnisotropy = 16;
		desc.MaxLOD=std::numeric_limits<float>::max();
		desc.MinLOD = std::numeric_limits<float>::min();
		desc.MipLODBias = 0.0f;
		
		auto hr = graphics->GetDevice()->CreateSamplerState(&desc, &sampler_state);
		assert(SUCCEEDED(hr));

	}
	//Create Blend State
	{
		D3D11_BLEND_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BLEND_DESC));
		desc.AlphaToCoverageEnable = true;
		desc.IndependentBlendEnable = false;
		desc.RenderTarget[0].BlendEnable = false;
		
		desc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC1_ALPHA;
		desc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
		desc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;

		desc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
		desc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_INV_SRC_ALPHA;
		desc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;

		desc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;

		auto hr = graphics->GetDevice()->CreateBlendState(&desc, &blend_state);
		assert(SUCCEEDED(hr));

	}

}

Execute::~Execute()
{
	SAFE_RELEASE(blend_state);
	SAFE_RELEASE(sampler_state);

	SAFE_RELEASE(shader_resource);
	//SAFE_RELEASE(shader_resource[0]);
	//SAFE_RELEASE(shader_resource[1]);

	SAFE_RELEASE(rasterizer_state);

	SAFE_RELEASE(gpu_buffer);

	SAFE_RELEASE(pixel_shader);
	SAFE_RELEASE(ps_blob);

	SAFE_RELEASE(input_layout);

	SAFE_RELEASE(vertex_shader);
	SAFE_RELEASE(vs_blob);

	SAFE_RELEASE(index_buffer);
	SAFE_DELETE_ARRAY(indices);

	SAFE_RELEASE(vertex_buffer);
	SAFE_DELETE_ARRAY(vertices);

	SAFE_DELETE(graphics);
}

void Execute::Update()
{
	//world._11 = 50;
	//world._22 = 50;
	
	//world._41 = 100;
	//world._42 = 100;

	//D3DXMATRIX			행 우선 행렬
	//GPU - shader - matrix	열 우선 행렬

	//1,0,0,0
	//0
	//0
	//0

	////매 프레임 마다 회전하기
	//{
	//	static float radian = 0.0f;
	//	radian += 0.01f;
	//	D3DXMATRIX P;
	//	D3DXMatrixRotationZ(&P, radian);
	//	
	//	world *= P;//부모에 종속됨
	//}
	//열과 행을 바꾸는 법 전치 행렬 Transpose					//기존의 행우선 행렬
	D3DXMatrixTranspose(&cpu_buffer.world,&world);			//cpu_buffer.world = world;
	D3DXMatrixTranspose(&cpu_buffer.view,&view);			//cpu_buffer.view = view;
	D3DXMatrixTranspose(&cpu_buffer.projection,&projection);//cpu_buffer.projection = projection;
						 
	D3D11_MAPPED_SUBRESOURCE mapped_subresource; //중재자
	graphics->GetDeviceContext()->Map
	(
		gpu_buffer,
		0,
		D3D11_MAP_WRITE_DISCARD,
		0,
		&mapped_subresource
	);

	//gpu buffer 갱신
	memcpy(mapped_subresource.pData, &cpu_buffer, sizeof(TRANSFORM_DATA));

	graphics->GetDeviceContext()->Unmap(gpu_buffer, 0);
}

void Execute::Render()
{
	uint stride = sizeof(VertexTexture);
	uint offset = 0;

	graphics->Begin();
	{
		//삼각형 그리기
		{
			//IA
			//정보전달
			graphics->GetDeviceContext()->IASetVertexBuffers(0, 1, &vertex_buffer, &stride, &offset);
			graphics->GetDeviceContext()->IASetIndexBuffer(index_buffer, DXGI_FORMAT_R32_UINT, 0);
			graphics->GetDeviceContext()->IASetInputLayout(input_layout);
			//삼각형을 그리라는 것을 전달
			graphics->GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

			//VS
			graphics->GetDeviceContext()->VSSetShader(vertex_shader, nullptr, 0);//정점의 갯수만큼 호출
			graphics->GetDeviceContext()->VSSetConstantBuffers(0, 1, &gpu_buffer);

			//RS
			graphics->GetDeviceContext()->RSSetState(rasterizer_state);

			//PS
			graphics->GetDeviceContext()->PSSetShader(pixel_shader, nullptr, 0);
			graphics->GetDeviceContext()->PSSetShaderResources(0, 1, &shader_resource);
			graphics->GetDeviceContext()->PSSetSamplers(0,1,&sampler_state);

			//OM
			graphics->GetDeviceContext()->OMSetBlendState(blend_state, nullptr, 0xffffffff);
			graphics->GetDeviceContext()->DrawIndexed(6, 0, 0);//그려주는 함수를 호출해야 그려진다.

		}
	}
	graphics->End();
}
//
