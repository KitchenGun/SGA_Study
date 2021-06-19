#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy(D3DXVECTOR3 position, D3DXVECTOR3 size, float rotation):Square(position, size, rotation)
{
	random_device rd;
	//����̵��� ��
	uniform_int_distribution<int> RNG0(0,1);
	isDirX = RNG0(rd);
	//�ӵ�
	uniform_int_distribution<int> RNG1(1, 10);
	if (RNG0(rd))
	{//��� ����
		nRNGSpeed = RNG1(rd);
	}
	else
	{//���� ����
		nRNGSpeed = RNG1(rd)*-1;
	}
	//����
	uniform_real_distribution<float> RNGColor(0, 1);
	r = RNGColor(rd);
	g = RNGColor(rd);
	b = RNGColor(rd);
}

Enemy::~Enemy()
{

}

void Enemy::Move(D3DXVECTOR3 position)
{
	this->position += position;
	D3DXMatrixTranslation(&T, this->position.x, this->position.y, this->position.z);

	world = S * R * T;
	WB->SetWorld(world);//���ο��� transpose����
	TransformVertices();
}

void Enemy::Action()
{
	if (Math::IsTouchEdge(this))
	{
		SetisTouchEdge(isTouchEdge?false:true);
	}
	if (isDirX)
	{
		if (!isTouchEdge)
		{
			Move({ (float)nRNGSpeed,0,0 });
		}
		else
		{
			Move({ (float)nRNGSpeed*-1,0,0 });
		}
	}
	else
	{
		if (!isTouchEdge)
		{
			Move({ 0, (float)nRNGSpeed,0 });
		}
		else
		{
			Move({ 0, (float)nRNGSpeed*-1,0 });
		}
	}
}

void Enemy::Update()
{
	
	Action();
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
		v.color = D3DXCOLOR(r, g, b, 1);
	}
	//���۳� ���� ����
	//��ü�� pData ����� ���۳� �������� ���ۿ� ���� �������Դϴ�.
	memcpy(subResource.pData, vertices.data(), sizeof(VertexColor)*vertices.size());
	DC->Unmap(VB->GetResource(), 0);
}

