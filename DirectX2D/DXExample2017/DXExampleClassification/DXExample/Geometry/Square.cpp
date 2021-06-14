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
	
	VS->Create(L"./_Shaders/VertexColor.hlsl", "VS");
	PS->Create(L"./_Shaders/VertexColor.hlsl", "PS");

	IL->Create(VertexColor::descs, VertexColor::count, VS->GetBlob());

	WB = new WorldBuffer();
	D3DXMatrixIdentity(&world);

	D3DXMatrixIdentity(&S);
	D3DXMatrixIdentity(&R);
	D3DXMatrixIdentity(&T);

	D3DXMatrixScaling(&S, size.x, size.y, size.z);
	D3DXMatrixRotationZ(&R, (float)D3DXToRadian(rotation));
	D3DXMatrixTranslation(&T, position.x, position.y, position.z);

	world = S * R * T;

	WB->SetWorld(world);
	TransformVertices();

	CB = new ColorBuffer();

}

Square::~Square()
{
	SAFE_DELETE(CB);
	
	SAFE_DELETE(WB);
	
	SAFE_DELETE(IL);
	
	SAFE_DELETE(PS);
	SAFE_DELETE(VS);

	SAFE_DELETE(IB);
	SAFE_DELETE(VB);
}

void Square::Move(D3DXVECTOR3 position)
{
	this->position += position;
	D3DXMatrixTranslation(&T, this->position.x, this->position.y, this->position.z);

	world = S * R * T;
	WB->SetWorld(world);//내부에서 transpose해줌
	TransformVertices();
}

void Square::Update()
{
	D3D11_MAPPED_SUBRESOURCE subResource;
	DC->Map
	(
		VB->GetResource(),
		0,
		D3D11_MAP_WRITE_DISCARD,
		0,
		&subResource
	);

	for (VertexColor&v : vertices)
	{
		v.color = D3DXCOLOR(1, 0, 0, 1);
	}
	memcpy(subResource.pData, vertices.data(), sizeof(VertexColor)*vertices.size());
	DC->Unmap(VB->GetResource(), 0);
}

void Square::Render()
{
	VB->SetIA();
	IB->SetIA();
	IL->SetIA();
	DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	WB->SetVSBuffer(0);
	VS->SetShader();
	PS->SetShader();

	DC->DrawIndexed(IB->GetCount(), 0, 0);
}

void Square::TransformVertices()
{
	//D3DXVec3TransformNormal() //벡터 이동
	D3DXVec3TransformCoord//정점 이동   //충돌을 체크하기 위한 좌표저장
	(
		&r.LT,
		&vertices[1].position,
		&world
	);
	D3DXVec3TransformCoord//정점 이동
	(
		&r.RB,
		&vertices[2].position,
		&world
	);
}
