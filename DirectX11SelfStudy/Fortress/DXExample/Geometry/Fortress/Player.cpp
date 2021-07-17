#include "stdafx.h"
#include "Player.h"

Player::Player(Vector3 position, Vector3 size, float rotation)
	:TextureRect(position,size,rotation)
{
	CBarrel = new Line(position, 100, 0, Red);
	CGaugeBar = new GaugeBar(Vector3(position.x+100, position.y + 300, position.z), Vector3(size.x + 200, size.y / 3*2, 1), 0);
	CPjManager = new ProjectileManager;
	SetSRV(L"./_Textures/Player.png");
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
	//����ü�� �̴� �Ŀ� ���� �� ����ü �迭�� �߰�
	CPjManager->AddProjectile(fFirePower,CBarrel->GetLP());
}

void Player::MoveBarrel()
{
	if (Keyboard::Get()->Press(VK_UP))
	{
		CBarrel->Rotation(1.0f);
	}
	else if (Keyboard::Get()->Press(VK_DOWN))
	{
		CBarrel->Rotation(-1.0f);
	}
}

void Player::Update()
{
	MoveBarrel();
	CBarrel->Update();
	CGaugeBar->Update();
	//��������
	static bool isPowerUP=true;
	if (Keyboard::Get()->Press(VK_SPACE))
	{//�����̽��ٸ� ������ ���
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
		Fire();
	}
	//����ü
	for (Bomb* Target : CPjManager->GetProjectileList())
	{
		if (Target != nullptr)
		{
			Target->Update();
		}
	}
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
