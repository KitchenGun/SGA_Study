#include "stdafx.h"
#include "Bullet.h"
#include "Utilities/Animator.h"

Bullet::Bullet(Vector3 position, Vector3 size, float rotation,bool isPlayer)
	:
	AnimationRect(position, size, rotation),
	isPlayer(isPlayer)
{
	SetAnimation();
	animator->SetCurrentAnimClip(L"Idle");
	animator->bLoop = true;
}

Bullet::~Bullet()
{
	AnimationRect::~AnimationRect();
}

void Bullet::Update()
{
	AnimationRect::Update();
	if (isPlayer)
	{
		Move(Vector3(0, fSpeed*Time::Delta(), 0));
	}
	else
	{
		Move(Vector3(0, -(fSpeed*2*Time::Delta()), 0));
	}
}

void Bullet::Move(Vector3 position)
{
	AnimationRect::Move(position);
}

void Bullet::SetAnimation()
{
	//텍스쳐 주소 입력하여서 텍스쳐 자원 제작
	texture = new Texture2D(L"./_Textures/Bullet.png");
	//idle
	animClips.push_back(new AnimationClip(L"Idle", texture, 4, { 0, 0 }, { (float)texture->GetWidth(),(float)texture->GetHeight() }));
	animator = new Animator(animClips);
}
