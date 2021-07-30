#include "stdafx.h"
#include "PlayerAfterBurner.h"
#include "Utilities/Animator.h"

PlayerAfterBurner::PlayerAfterBurner(Vector3 position, Vector3 size, float rotation)
	:
	AnimationRect(position, size, rotation)
{
	SetAnimation();
	animator->SetCurrentAnimClip(L"AfterBurnerOn");
	animator->bLoop = true;
}

PlayerAfterBurner::~PlayerAfterBurner()
{
	AnimationRect::~AnimationRect();
}

void PlayerAfterBurner::Update()
{
	AnimationRect::Update();
}

void PlayerAfterBurner::Move(Vector3 position)
{
	this->position = position;
	D3DXMatrixTranslation(&T, this->position.x, this->position.y, this->position.z);
	world = S * R * T;
	WB->SetWorld(world);

	if (position.y > 0)//�������� �̵��ϴ� ���
		animator->SetCurrentAnimClip(L"AfterBurnerOn");
	else if (position.y == 0)//�Ʒ������� �̵��ϴ� ���
		animator->SetCurrentAnimClip(L"AfterBurnerOff");

	animator->bLoop = false;
}

void PlayerAfterBurner::Render()
{
	if (isActive)
	{
		AnimationRect::Render();
	}
}

void PlayerAfterBurner::SetAnimation()
{
	//�ؽ��� �ּ� �Է��Ͽ��� �ؽ��� �ڿ� ����
	texture = new Texture2D(L"./_Textures/AfterBurner.png");
	//������ ����
	animClips.push_back(new AnimationClip(L"AfterBurnerOn", texture, 6, { 0, 0 }, { (float)texture->GetWidth() / 11 * 6, (float)texture->GetHeight() }));
	animClips.push_back(new AnimationClip(L"AfterBurnerOff", texture, 6, { (float)texture->GetWidth() / 11 * 5, 0 }, { (float)texture->GetWidth(), (float)texture->GetHeight() }));
	animator = new Animator(animClips);
}
