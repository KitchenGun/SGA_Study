#include "stdafx.h"
#include "Ball.h"

Ball::Ball(Vector3 position, Vector3 size, int segments, Color color)
	:FilledCircle(position, size, segments, color)
{
	vecDir = Vector3(0.0f, 0.0f, 0.0f);
}

Ball::~Ball()
{
}

void Ball::Move(Vector3 position)
{
	this->position += 15 * position;
	D3DXMatrixTranslation(&T, this->position.x, this->position.y, this->position.z);

	world = S * T;
	WB->SetWorld(world);//내부에서 transpose해줌
	TransformVertices();
}

void Ball::Update()
{
	Math::CircleWallIntersect(this);
	Move(vecDir);
}

void Ball::Reset()
{
	vecDir = { 0,0,0 };
	this->position = { WinMaxWidth / 2,WinMaxHeight / 2,0 };
	D3DXMatrixTranslation(&T, this->position.x, this->position.y, this->position.z);

	world = S * T;
	WB->SetWorld(world);//내부에서 transpose해줌
	TransformVertices();
}
