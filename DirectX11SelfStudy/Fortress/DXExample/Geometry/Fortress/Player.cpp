#include "stdafx.h"
#include "Player.h"

Player::Player(Vector3 position, Vector3 size, float rotation,bool isPlayer)
	:TextureRect(position,size,rotation),
	isPlayer(isPlayer)
{
	FireSFX = new SoundSystem;
	FireSFX->CreateEffSound("./_Sounds/gen_1E.wav");
	isFire = false;
	if (isPlayer)
	{
		CBarrel = new Line(position, 100, 0, Red);
		CGaugeBar = new GaugeBar(Vector3(position.x + 100, position.y + 300, position.z), Vector3(size.x + 200, size.y / 3 * 2, 1), 0);
		CPjManager = new ProjectileManager;
		SetSRV(L"./_Textures/Player.png");
	}
	else
	{
		CBarrel = new Line(position, -100, 0, Red);
		CGaugeBar = new GaugeBar(Vector3(position.x - 100, position.y + 300, position.z), Vector3(size.x + 200, size.y / 3 * 2, 1), 0);
		CPjManager = new ProjectileManager;
		SetSRV(L"./_Textures/Enemy.png");
	}
}

Player::~Player()
{
	TextureRect::~TextureRect();
	SAFE_DELETE(CPjManager);
	SAFE_DELETE(CGaugeBar);
	SAFE_DELETE(CBarrel);
}

void Player::Fire()
{
	FireSFX->Play();
	//투사체를 미는 파워 전달 및 투사체 배열에 추가
	CPjManager->AddProjectile(fFirePower,CBarrel->GetLP());
}

void Player::MoveBarrel()
{
	if (Keyboard::Get()->Press(VK_UP))
	{
		if (isPlayer)
		{
			CBarrel->Rotation(1.0f);
		}
		else 
			CBarrel->Rotation(-1.0f);
	}
	else if (Keyboard::Get()->Press(VK_DOWN))
	{
		if (isPlayer)
		{
			CBarrel->Rotation(-1.0f);
		}
		else
			CBarrel->Rotation(1.0f);
	}
}

void Player::BulletUpdate()
{
	FireSFX->Update();
	//투사체
	for (Bomb* Target : CPjManager->GetProjectileList())
	{
		if (Target != nullptr)
		{
			Target->Update();
			if (Target->GetReadyDestroy())
			{
				CPjManager->RemoveProjectile(Target);
			}
		}
	}
}

void Player::Update()
{
	MoveBarrel();
	CBarrel->Update();
	CGaugeBar->Update();
	//게이지바
	static bool isPowerUP=true;
	if (Keyboard::Get()->Press(VK_SPACE))
	{//스페이스바를 눌렀을 경우
		if (isPowerUP)
		{
			fFirePower = fFirePower + 0.01f;
			if (fFirePower >= 1)
			{
				isPowerUP = false;
			}
		}
		else
		{
			fFirePower = fFirePower - 0.01f;
			if (fFirePower <= 0)
			{
				isPowerUP = true;
			}
		}
		CGaugeBar->SetBarSize(fFirePower);
	}
	if (Keyboard::Get()->Up(VK_SPACE))
	{
		isFire = true;
		Fire();
	}
	BulletUpdate();
}

void Player::Render()
{
	TextureRect::Render();
	CBarrel->Render();
	CGaugeBar->Render();
	for (Bomb* Target : CPjManager->GetProjectileList())
	{
		if (Target != nullptr)
		{
			Target->Render();
		}
	}
}
