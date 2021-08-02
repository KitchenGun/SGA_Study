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
	MoveDir = Vector3(0, 0, 0);
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
	//AnimationRect::Update();

	Rotation();
	Move(MoveDir*fSpeed*Time::Delta());
}

void Missile::Move(Vector3 position)
{
	Bullet::Move(position);
}

void Missile::Rotation()
{
	float VecLength = this->position.x * Target->GetPosition().y - this->position.y * Target->GetPosition().x;
	if (this->position.x * Target->GetPosition().y - this->position.y * Target->GetPosition().x > 0)
	{
		//앵글값 더하고
		fangle -= D3DXToRadian(10.0f);
	}
	else if (this->position.x * Target->GetPosition().y - this->position.y * Target->GetPosition().x < 0)
	{
		//앵글값을 뺀다
		fangle += D3DXToRadian(10.0f);
	}
	float angle = atan2(this->position.y - Target->GetPosition().y, this->position.x - Target->GetPosition().x);
	MoveDir = Vector3(-cosf(angle), -sinf(angle), 0);
	this->rotation = fangle;
	D3DXMatrixRotationZ(&R, (float)D3DXToRadian(this->rotation));

	world = S * R * T;
	WB->SetWorld(world);//내부에서 transpose해줌
}
