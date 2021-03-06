#include "stdafx.h"
#include "Player.h"

Player::Player(Vector3 position, Vector3 size, int segments, Color color)
	:FilledCircle(position, size, segments, color)
{

}

Player::~Player()
{
}

void Player::Move()
{
	if (!isEnemy)
	{
		if (Mouse::Get()->GetPosition().x > WinMaxWidth / 2)
		{
			vecDir.x = Mouse::Get()->GetMoveValue().x;
			vecDir.y = Mouse::Get()->GetMoveValue().y;
			this->position = Mouse::Get()->GetPosition();
			D3DXMatrixTranslation(&T, this->position.x, this->position.y, this->position.z);

			world = S * T;
			WB->SetWorld(world);//���ο��� transpose����
			TransformVertices();
		}
	}
	else
	{
		if (this->position.x + vecDir.x < 0 || this->position.x + vecDir.x > WinMaxWidth/2)
		{
			this->position.y += vecDir.y;
			D3DXMatrixTranslation(&T, this->position.x, this->position.y, this->position.z);
		}
		else 
		{
			this->position += vecDir;
			D3DXMatrixTranslation(&T, this->position.x, this->position.y, this->position.z);
		}
		world = S * T;
		WB->SetWorld(world);//���ο��� transpose����
		TransformVertices();
	}
}

void Player::Update()
{
	Move();
}

void Player::Reset()
{
	if (!isEnemy)
	{
		this->position = { WinMaxWidth / 3 * 2,WinMaxHeight / 2,0 };
		D3DXMatrixTranslation(&T, this->position.x, this->position.y, this->position.z);

		world = S * T;
		WB->SetWorld(world);//���ο��� transpose����
		TransformVertices();
	}
	else
	{
		this->position = { WinMaxWidth / 4,WinMaxHeight / 2,0 };
		D3DXMatrixTranslation(&T, this->position.x, this->position.y, this->position.z);

		world = S * T;
		WB->SetWorld(world);//���ο��� transpose����
		TransformVertices();
	}
}


