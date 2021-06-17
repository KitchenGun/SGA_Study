#include "stdafx.h"
#include "Circle.h"

Circle::Circle(D3DXVECTOR3 position, D3DXVECTOR3 size, float rotation)
	:position(position),
	size(size),
	rotation(rotation)
{
	//���� ���� �Է�
	vertices.assign(361, VertexColor());
	indices.assign(361,sizeof(UINT));
	for (int i = 0; i <= 360; ++i)
	{
		vertices[i].position = D3DXVECTOR3(0.5f*(float)cos(D3DXToRadian(i)), 0.5f*(float)sin(D3DXToRadian(i)), 0.0f);
		vertices[i].color = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
		indices[i]=i;
	}

	//Ŭ����ȭ �� ��ü ����
	VB = new VertexBuffer();
	IB = new IndexBuffer();

	VS = new VertexShader();
	PS = new PixelShader();

	IL = new InputLayout();

	WB = new WorldBuffer();
	CB = new ColorBuffer();
	//��ü���� �Լ� ȣ��
	VB->Create(vertices, D3D11_USAGE_DYNAMIC);
	IB->Create(indices, D3D11_USAGE_IMMUTABLE);

	VS->Create(L"./_Shaders/VertexColor.hlsl", "VS");
	PS->Create(L"./_Shaders/VertexColor.hlsl", "PS");

	IL->Create(VertexColor::descs, VertexColor::count, VS->GetBlob());

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


}

Circle::~Circle()
{
	SAFE_DELETE(CB);

	SAFE_DELETE(WB);

	SAFE_DELETE(IL);

	SAFE_DELETE(PS);
	SAFE_DELETE(VS);

	SAFE_DELETE(IB);
	SAFE_DELETE(VB);
}

void Circle::Move(D3DXVECTOR3 position)
{
	this->position += position;
	D3DXMatrixTranslation(&T, this->position.x, this->position.y, this->position.z);

	world = S * R * T;
	WB->SetWorld(world);//���ο��� transpose����
	TransformVertices();
}

void Circle::Update()
{
	//���ؽ� ���۸� ����
	D3D11_MAPPED_SUBRESOURCE subResource;
	DC->Map
	(
		VB->GetResource(),
		0,
		D3D11_MAP_WRITE_DISCARD,
		0,
		&subResource
	);
	//����ȯ
	for (VertexColor&v : vertices)
	{
		v.color = D3DXCOLOR(1, 0, 0, 1);
	}
	//���۳� ���� ����
	//��ü�� pData ����� ���۳� �������� ���ۿ� ���� �������Դϴ�.
	memcpy(subResource.pData, vertices.data(), sizeof(VertexColor)*vertices.size());
	DC->Unmap(VB->GetResource(), 0);
}

void Circle::Render()
{
	VB->SetIA();
	IB->SetIA();
	IL->SetIA();
	//�⺻ ���� ���� ��� ����
	DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);
	WB->SetVSBuffer(0);
	VS->SetShader();
	PS->SetShader();
	//�ε��� ���۸� �̿��ؼ� �׸���
	DC->DrawIndexed(IB->GetCount(), 0, 0);
}

void Circle::TransformVertices()
{
	//D3DXVec3TransformNormal() //���� �̵�   //������ ��Ŀ� ���� 3D ���� ������ ��ȯ �Ѵ�.
	D3DXVec3TransformCoord//���� �̵�   //�浹�� üũ�ϱ� ���� ��ǥ����
	(//������ ��Ŀ� ���� 3D ���͸� ��ȯ ��, �� ����� w = 1 �� ���� �Ѵ�.
		&r.LT,
		&vertices[1].position,
		&world
	);
	D3DXVec3TransformCoord//���� �̵�
	(
		&r.RB,
		&vertices[2].position,
		&world
	);
}
