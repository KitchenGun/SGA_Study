#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy(Vector3 position, Vector3 size, float rotation)
	:TextureRect(position, size, rotation)
{
	SetSRV(L"./_Textures/Enemy.png");
	LB->SetLocalRect(Vector4(position.x - size.x / 2, position.y + size.y / 2, position.x + size.x / 2, position.y - size.y / 2));
}

Enemy::~Enemy()
{

}

void Enemy::Update()
{
	Move(Vector3(fSpeed, 0, 0));
	MoveLocalRect(Vector4(fSpeed, 0, fSpeed, 0));
}

void Enemy::SetPosition(Vector3 position)
{
}
