#include "stdafx.h"
#include "Player.h"

Player::Player(Vector3 position, Vector3 size, float rotation)
	:TextureRect(position,size,rotation)
{
	CBarrel = new Line(position, 100, 0, Red);
	CGaugeBar = new GaugeBar(Vector3(position.x+50, position.y + 300, position.z), Vector3(size.x + 200, size.y / 3*2, 1), 0);
	SetSRV(L"./_Textures/Player.png");
}

Player::~Player()
{
}

void Player::Fire()
{

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
}

void Player::Render()
{
	TextureRect::Render();
	CBarrel->Render();
	CGaugeBar->Render();
}
