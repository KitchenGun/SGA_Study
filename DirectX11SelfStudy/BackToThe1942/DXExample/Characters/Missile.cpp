#include "stdafx.h"
#include "Missile.h"
#include "Utilities/Animator.h"


Missile::Missile(Vector3 position, Vector3 size, float rotation, bool isPlayer)
	:
	Bullet(position, size, rotation, isPlayer)
{
	SetAnimation();
	animator->SetCurrentAnimClip(L"Idle");
	fSpeed = 200.0f;
	MoveDir = Vector3(0, -1, 0);

	//float angle = atan2(this->position.y - Target->GetPosition().y, this->position.x - Target->GetPosition().x);
	//MoveDir = Vector3(-cosf(angle), -sinf(angle), 0);
}

Missile::~Missile()
{
	Bullet::~Bullet();
}

void Missile::SetAnimation()
{
	texture = new Texture2D(L"./_Textures/Missile.png");
	animClips.push_back(new AnimationClip(L"Idle", texture, 1, { 0, 0 }, { (float)texture->GetWidth(),(float)texture->GetHeight() }));
	animator = new Animator(animClips);
}

void Missile::Update()
{
	Rotation();
	Move(MoveDir*fSpeed*Time::Delta());
	//if (deltaTime > FireRate)//일정 시간 마다 실행함 
	//{
	//	Rotation();
	//	deltaTime = 0.0f;
	//}
	//else//작동환경과 상관없이 일정하게 맞춰준다
	//	deltaTime += Time::Delta();
}

void Missile::Move(Vector3 position)
{
	Bullet::Move(position);
}

void Missile::Rotation()
{
	float angle = atan2(this->position.y - Target->GetPosition().y, this->position.x - Target->GetPosition().x);
	MoveDir = Vector3(-cosf(angle), -sinf(angle), 0);
	angle += D3DXToDegree(90);

	this->rotation = angle;
	D3DXMatrixRotationZ(&R, angle);//(float)D3DXToRadian(this->rotation));

	world = S * R * T;
	WB->SetWorld(world);//내부에서 transpose해줌
	TransformVertices();
}
