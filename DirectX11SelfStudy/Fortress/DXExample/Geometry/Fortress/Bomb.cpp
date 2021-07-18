#include "stdafx.h"
#include "Bomb.h"

Bomb::Bomb(Vector3 position, Vector3 size, int segments, Color color)
	:FilledCircle(position,size,segments,color)
{

}

Bomb::~Bomb()
{
}

void Bomb::Update()
{
	CurrentTime = clock();
	cout << (CurrentTime - FireStartTime) / 1000 << endl;
	if ((CurrentTime - FireStartTime) / 1000 > 3)
	{
		isNeedDestroy = true;
	}
	else
	{
		isNeedDestroy = false;
	}
	if (Math::GroundIntersect(this))
	{
		if (fPower > 0)
		{
			fPower -= 0.1f;
			cout << fPower << endl;
		}
		else
		{
			fPower = 0;
		}
	}
	Move();
}

void Bomb::Fire(float fPower)
{   //발사시 힘을 받음
	this->fPower = fPower;
	FireStartTime = clock();
}

void Bomb::Move()
{
	float angle = atan2(vec3MoveDir.y, vec3MoveDir.x);
	float tempTime = (float)(CurrentTime - FireStartTime) / 1000;
	if (fPower != 0)
	{
		vec3MoveDir = Vector3(fPower * 15 * cosf(angle), fPower * 15 * sinf(angle) - tempTime * 0.5f, 0);
		this->position += Vector3(fPower * 15 * cosf(angle), fPower * 15 * sinf(angle) - tempTime * 0.5f, 0);
	}
	else
	{
		this->position.y = size.x;
	}
	D3DXMatrixTranslation(&T, this->position.x, this->position.y, this->position.z);
	world = S * T;
	WB->SetWorld(world);
	TransformVertices();
}

