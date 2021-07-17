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
	Move();
	if (bGroundIntersect)
	{
		Move(Vector3(0, fGravityPower, 0));
	}
}

void Bomb::Fire(float fPower)
{   //발사시 힘을 받음
	this->fPower = fPower;
	//dir값도 여기서 받아야함
}

void Bomb::Move()
{
	this->position += (vec3MoveDir*fPower);
	D3DXMatrixTranslation(&T, this->position.x, this->position.y, this->position.z);

	world = S * T;
	WB->SetWorld(world);//내부에서 transpose해줌
	TransformVertices();
}

void Bomb::Move(Vector3 val)
{
	this->position += val;
	D3DXMatrixTranslation(&T, this->position.x, this->position.y, this->position.z);

	world = S * T;
	WB->SetWorld(world);//내부에서 transpose해줌
	TransformVertices();
}
