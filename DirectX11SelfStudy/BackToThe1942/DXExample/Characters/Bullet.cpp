#include "stdafx.h"
#include "Bullet.h"
#include "Utilities/Animator.h"

Bullet::Bullet(Vector3 position, Vector3 size, float rotation)
	:
	AnimationRect(position, size, rotation)
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
	Move(Vector3(0, fSpeed*Time::Delta(), 0));
}

void Bullet::Move(Vector3 position)
{
	AnimationRect::Move(position);
}

void Bullet::SetAnimation()
{
	//�ؽ��� �ּ� �Է��Ͽ��� �ؽ��� �ڿ� ����
	texture = new Texture2D(L"./_Textures/Bullet.png");
	//idle
	animClips.push_back(new AnimationClip(L"Idle", texture, 4, { 0, 0 }, { (float)texture->GetWidth(),(float)texture->GetHeight() }));
	animator = new Animator(animClips);
}
