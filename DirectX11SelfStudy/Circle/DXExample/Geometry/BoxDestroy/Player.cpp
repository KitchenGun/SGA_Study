#include "stdafx.h"
#include "Player.h"

Player::Player(D3DXVECTOR3 position, D3DXVECTOR3 size, float rotation, Color color) : Square(position, size, rotation, color)
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
}
