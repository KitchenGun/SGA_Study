#include "stdafx.h"
#include "Execute.h"
#include "Graphics.h"

Execute::Execute()
{
	graphics = new Graphics();
	graphics->Initialize();
	graphics->CreateBackBuffer(static_cast<uint>(Settings::Get().GetWidth()), static_cast<uint>(Settings::Get().GetHeight()));
	//vertex_data
	{
		vertices = new VertexColor[3];
		vertices[0].position = D3DXVECTOR3(-0.5f, -0.5f, 0.0f);
		vertices[0].color = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);

		vertices[1].position = D3DXVECTOR3(0.5f, 0.5f, 0.0f);
		vertices[1].color = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);

		vertices[2].position = D3DXVECTOR3(0.5f, -0.5f, 0.0f);
		vertices[2].color = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
	}
	//vertex_buffer
	{
		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));
		desc.Usage = D3D11_USAGE_IMMUTABLE;
		desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		desc.ByteWidth = sizeof(VertexColor) * 3;

		D3D11_SUBRESOURCE_DATA sub_data;//cpu 데이터를 gpu에 연결할수있다.
		ZeroMemory(&sub_data, sizeof(D3D11_SUBRESOURCE_DATA));
		sub_data.pSysMem = vertices;

		auto hr = graphics->GetDevice()->CreateBuffer(&desc, &sub_data, &vertex_buffer);
		assert(SUCCEEDED(hr));
	}
}

Execute::~Execute()
{
	SAFE_RELEASE(vertex_buffer);

	SAFE_DELETE_ARRAY(vertices);
	SAFE_DELETE(graphics);
}

void Execute::Update()
{
}

void Execute::Render()
{
	uint stride = sizeof(VertexColor);
	uint offset = 0;

	graphics->Begin();
	{
		//삼각형 그리기
		{
			//정보전달
			graphics->GetDeviceContext()->IAGetVertexBuffers(0, 1, &vertex_buffer, &stride, &offset);
			//TODO : Input layout
			//삼각형을 그리라는 것을 전달
			graphics->GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		}
	}
	graphics->End();
}
//
