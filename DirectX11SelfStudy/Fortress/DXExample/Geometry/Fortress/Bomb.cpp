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
	Move();
	if (!bGroundIntersect)
	{
		Move(Vector3(0, fGravityPower, 0));
	}
}

void Bomb::Fire(float fPower)
{   //발사시 힘을 받음
	this->fPower = fPower;
	isFire = true;
	FireStartTime = clock();
	//dir값도 여기서 받아야함

}

void Bomb::Move()
{
	float angle = atan2(vec3MoveDir.y,vec3MoveDir.x);
	//포물선 공식 넣어서 수정중
	this->position = position+Vector3(fPower*cosf(angle)*(CurrentTime-FireStartTime/1000), fPower*sinf(angle),0);
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
