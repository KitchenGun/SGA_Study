#include "stdafx.h"
#include "Player.h"

Player::Player(D3DXVECTOR3 position, D3DXVECTOR3 size, float rotation) : Square(position,size,rotation)
{

}

Player::~Player()
{

}

void Player::PlayerCtrl()
{
	//����
	if (Keyboard::Get()->Press('W'))
	{
		if (Math::TouchEdge(this) != Direction::TOP&&Math::TouchEdge(this) != Direction::TL&&Math::TouchEdge(this) != Direction::TR)
		{
			this->Move({ 0,10,0 });
			isMoveVertical = true;
		}
	}
	else if (Keyboard::Get()->Press('S'))
	{
		if (Math::TouchEdge(this) != Direction::BOTTOM&&Math::TouchEdge(this) != Direction::BR&&Math::TouchEdge(this) != Direction::BL)
		{
			this->Move({ 0,-10,0 });
			isMoveVertical = true;
		}
	}
	else
	{
		isMoveVertical = false;
	}
	//�¿�
	if (isMoveVertical)
	{

		if (Keyboard::Get()->Press('A'))
		{
			if (Math::TouchEdge(this) != Direction::LEFT&&Math::TouchEdge(this) != Direction::TL&&Math::TouchEdge(this) != Direction::BL)
			{
				this->Move({ -(10 / (float)sqrt(2)),0,0 });
			}
		}
		else if (Keyboard::Get()->Press('D'))
		{
			if (Math::TouchEdge(this) != Direction::RIGHT&&Math::TouchEdge(this) != Direction::BR&&Math::TouchEdge(this) != Direction::TR)
			{
				this->Move({ (10 / (float)sqrt(2)),0,0 });
			}
		}
	}
	else
	{
		if (Keyboard::Get()->Press('A'))
		{
			if (Math::TouchEdge(this) != Direction::LEFT&&Math::TouchEdge(this) != Direction::TL&&Math::TouchEdge(this) != Direction::BL)
			{
				this->Move({ -10,0,0 });
			}
		}
		else if (Keyboard::Get()->Press('D'))
		{
			if (Math::TouchEdge(this) != Direction::RIGHT&&Math::TouchEdge(this) != Direction::BR&&Math::TouchEdge(this) != Direction::TR)
			{
				this->Move({ 10,0,0 });
			}
		}
	}
}

void Player::Move(D3DXVECTOR3 position)
{
	this->position += position;
	D3DXMatrixTranslation(&T, this->position.x, this->position.y, this->position.z);

	world = S * R * T;
	WB->SetWorld(world);//���ο��� transpose����
	TransformVertices();
}

void Player::Update()
{
	PlayerCtrl();
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
