#include "stdafx.h"
#include "Missile.h"
#include "Utilities/Animator.h"

Missile::Missile(Vector3 position, Vector3 size, float rotation)
	:
	Bullet(position, size, rotation)
{
	SetAnimation();
	animator->SetCurrentAnimClip(L"Idle");
	fSpeed = -200.0f;
	MoveDir = Vector3(0, fSpeed, 0);
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
	Move(MoveDir*Time::Delta());
}

void Missile::Move(Vector3 position)
{
	Bullet::Move(position);
}
