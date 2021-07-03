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

void Player::Update()
{
	Move();
}

Vector3 Player::GetVecDir()
{
	return vecDir;
}
