#include "stdafx.h"
#include "Ball.h"

Ball::Ball(Vector3 position, Vector3 size, int segments, Color color)
	:FilledCircle(position,size,segments,color)
{
	vecDir = Vector3(0.0f, -1.0f, 0.0f);
}

Ball::~Ball()
{

}

void Ball::Move(Vector3 position)
{
	this->position += position;
	D3DXMatrixTranslation(&T, this->position.x, this->position.y, this->position.z);

	world = S * T;
	WB->SetWorld(world);//내부에서 transpose해줌
	TransformVertices();
}

void Ball::Update()
{
	if (Math::CircleWallIntersect(this))
	{
		cout << "충돌"<<vecDir.x<<","<<vecDir.y << endl;
		
	}
	Move(vecDir);
}
