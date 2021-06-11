#include "stdafx.h"
#include "Square.h"

Square::Square(D3DXVECTOR3 position, D3DXVECTOR3 size, float rotation)
	:position(position),
	size(size),
	rotation(rotation)
{
	vertices.assign(4, VertexColor());
	vertices[0].position = D3DXVECTOR3(-0.5f, -0.5f, 0.0f);
	vertices[0].color = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);

	vertices[1].position = D3DXVECTOR3(-0.5f, 0.5f, 0.0f);
	vertices[1].color = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
	
	vertices[2].position = D3DXVECTOR3(0.5f, -0.5f, 0.0f);
	vertices[2].color = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
	
	vertices[3].position = D3DXVECTOR3(0.5f, 0.5f, 0.0f);
	vertices[3].color = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);

	indices = { 0,1,2,2,1,3 };
	VB = new VertexBuffer();
	IB = new IndexBuffer();

	VS = new VertexShader();
	PS = new PixelShader();

	IL = new InputLayout();

	VB->Create(vertices, D3D11_USAGE_DYNAMIC);
	IB->Create(indices, D3D11_USAGE_IMMUTABLE);
}

Square::~Square()
{
}

void Square::Move(D3DXVECTOR3 position)
{
}

void Square::Update()
{
}

void Square::Render()
{
}

void Square::TransformVertices()
{
}
