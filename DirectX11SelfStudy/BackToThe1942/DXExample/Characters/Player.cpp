#include "stdafx.h"
#include "Player.h"
#include "Utilities/Animator.h"

Player::Player(Vector3 position, Vector3 size, float rotation)
	:
AnimationRect(position, size, rotation)
{
	SetAnimation();
	animator->SetCurrentAnimClip(L"FlyIdle");
}

Player::~Player()
{
	AnimationRect::~AnimationRect();
	SAFE_DELETE(textureY);
	SAFE_DELETE(textureX);
}

void Player::Update()
{
	Input();
	AnimationRect::Update();
}

void Player::Move(Vector3 position)
{
	AnimationRect::Move(position);
	//if (position.y > 0)//�������� �̵��ϴ� ���
	//	animator->SetCurrentAnimClip(L"AfterBurnerOn");
	//else if (position.y < 0)//�Ʒ������� �̵��ϴ� ���
	//	animator->SetCurrentAnimClip(L"AfterBurnerOff");
	//if (!isAxisDirInput)
	//{
	if (position.x > 0)//���������� �̵��ϴ� ���
	{
		animator->SetCurrentAnimClip(L"FlyR");
		animator->bLoop = false;
	}
	else if (position.x < 0)//�������� �̵��ϴ� ���
	{
		animator->SetCurrentAnimClip(L"FlyL");
		animator->bLoop = false;
	}
}


void Player::Input()
{
	if (KeyPress_Left)
	{
		if (isAxisDirInput)
		{
			this->Move(Vector3(-100 / sqrt(2)* Time::Delta(), 0, 0));
		}
		else
		{
			this->Move(Vector3(-100 * Time::Delta(), 0, 0));

		}
	}
	else if (KeyPress_Right)
	{
		if (isAxisDirInput)
		{
			this->Move(Vector3(100 / sqrt(2)* Time::Delta(), 0, 0));
		}
		else
		{
			this->Move(Vector3(100 * Time::Delta(), 0, 0));
		}
	}
	if (KeyPress_Up)
	{
		this->Move(Vector3(0, 100 * Time::Delta(), 0));
		isAxisDirInput = true;
	}
	else if (KeyPress_Down)
	{
		this->Move(Vector3(0, -100 * Time::Delta(), 0));
		isAxisDirInput = true;
	}
	else
	{
		isAxisDirInput = false;
	}
}

void Player::SetAnimation()
{
	//�ؽ��� �ּ� �Է��Ͽ��� �ؽ��� �ڿ� ����
	texture = new Texture2D(L"./_Textures/Player.png");
	textureY = new Texture2D(L"./_Textures/AfterBurner.png");
	//������ ����
	//animClips.push_back(new AnimationClip(L"AfterBurnerOn", textureY, 6, { 0, 0 }, { (float)textureY->GetWidth() / 11*6, 0 }));
	//animClips.push_back(new AnimationClip(L"AfterBurnerOff", textureY, 6, { (float)textureY->GetWidth() / 11 * 6, 0 }, { (float)textureY->GetWidth(), 0}));
	//idle
	animClips.push_back(new AnimationClip(L"FlyIdle", texture, 1, { (float)texture->GetWidth() / 7 * 3, 0 }, { (float)texture->GetWidth() / 7 * 4,(float)texture->GetHeight() }));
	//�¿�												  
	animClips.push_back(new AnimationClip(L"FlyL", texture, 4, { 0, 0 }, { (float)texture->GetWidth() / 7 * 4,(float)texture->GetHeight() }, true));
	animClips.push_back(new AnimationClip(L"FlyR", texture, 4, { (float)texture->GetWidth() / 7 * 3, 0 }, { (float)texture->GetWidth(),(float)texture->GetHeight() }));
	animator = new Animator(animClips);
}
