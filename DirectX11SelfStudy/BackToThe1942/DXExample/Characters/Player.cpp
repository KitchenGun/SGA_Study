#include "stdafx.h"
#include "Player.h"
#include "Utilities/Animator.h"

Player::Player(Vector3 position, Vector3 size, float rotation)
	:
AnimationRect(position, size, rotation)
{
	SetAnimation();
	animator->SetCurrentAnimClip(L"FlyIdle");
	animator->bLoop = false;
}

Player::~Player()
{
	AnimationRect::~AnimationRect();
}

void Player::Update()
{
	Input();
	if (!isVerticalDirInput)
	{
		afterBurner->SetIsActive(false);
	}
	AnimationRect::Update();
}

void Player::Move(Vector3 position)
{
	AnimationRect::Move(position);
	
	switch (PlayerState)
	{
		case State::Idle:
		{
			animator->SetCurrentAnimClip(L"FlyIdle");
			break;
		}
		case State::Forward:
		{
			afterBurner->SetIsActive(true);
			animator->SetCurrentAnimClip(L"FlyIdle");
			break;
		}
		case State::Backward:
		{
			//animator->SetCurrentAnimClip(L"FlyIdle");
			afterBurner->SetIsActive(false);
			if (position.x < 0)
			{
				animator->SetCurrentAnimClip(L"FlyL");
			}
			else if (position.x > 0)
			{
				animator->SetCurrentAnimClip(L"FlyR", true);
			}
			else
			{
				animator->SetCurrentAnimClip(L"FlyIdle");
			}
			break;
		}
		case State::Left:
		{
			if (!isHorizontalDirInput)
			{
				animator->SetCurrentAnimClip(L"RFlyL", true);
			}
			else
			{
				animator->SetCurrentAnimClip(L"FlyL");
			}
			break;
		}
		case State::Right:
		{
			if (!isHorizontalDirInput)
			{
				animator->SetCurrentAnimClip(L"RFlyR", true);
			}
			else
			{
				animator->SetCurrentAnimClip(L"FlyR");
			}
			break;
		}
		default:
			break;
	}
}


void Player::Input()
{
	TempMovePos = Vector3(0, 0, 0);
	if (KeyPress_Left)
	{
		TempMovePos += Vector3(-100 * Time::Delta(), 0, 0);
		isHorizontalDirInput = true;
		PlayerState = State::Left;
	}
	else if (KeyPress_Right)
	{
		TempMovePos += Vector3(100 * Time::Delta(), 0, 0);
		isHorizontalDirInput = true;
		PlayerState = State::Right;
	}
	else
	{
		isHorizontalDirInput = false;
	}

	if (KeyPress_Up)
	{
		TempMovePos += Vector3(0, 100 * Time::Delta(), 0);
		isVerticalDirInput = true;
		PlayerState = State::Forward;
	}
	else if (KeyPress_Down)
	{
		TempMovePos += Vector3(0, -100 * Time::Delta(), 0);
		isVerticalDirInput = true;
		PlayerState = State::Backward;
	}
	else
	{
		isVerticalDirInput = false;
	}
	if (isVerticalDirInput&&isHorizontalDirInput)
	{
		TempMovePos=TempMovePos/ sqrt(2);
	}
	Move(TempMovePos);

	if (Keyboard::Get()->Press(VK_SPACE))
	{
		if (deltaTime > FireRate)//일정 시간 마다 실행함 
		{
			playerBM->AddProjectile(position + Vector3(0, 60, 0),true);
			deltaTime = 0.0f;
		}
		else//작동환경과 상관없이 일정하게 맞춰준다
			deltaTime += Time::Delta();
	}
}

void Player::SetAnimation()
{
	//텍스쳐 주소 입력하여서 텍스쳐 자원 제작
	texture = new Texture2D(L"./_Textures/Player.png");
	//idle
	animClips.push_back(new AnimationClip(L"FlyIdle", texture, 1, { (float)texture->GetWidth() / 7 * 3, 0 }, { (float)texture->GetWidth() / 7 * 4,(float)texture->GetHeight() }));
	//좌우												  
	animClips.push_back(new AnimationClip(L"FlyL", texture, 4, { 0, 0 }, { (float)texture->GetWidth() / 7 * 4,(float)texture->GetHeight() }, true));
	animClips.push_back(new AnimationClip(L"FlyR", texture, 4, { (float)texture->GetWidth() / 7 * 3, 0 }, { (float)texture->GetWidth(),(float)texture->GetHeight() }));
	//좌우 리버스
	animClips.push_back(new AnimationClip(L"RFlyL", texture, 4, { 0, 0 }, { (float)texture->GetWidth() / 7 * 4,(float)texture->GetHeight() }));
	animClips.push_back(new AnimationClip(L"RFlyR", texture, 4, { (float)texture->GetWidth() / 7 * 3, 0 }, { (float)texture->GetWidth(),(float)texture->GetHeight() },true));
	animator = new Animator(animClips);
}
