#include "stdafx.h"
#include "Player.h"

Player::Player(Vector3 position, Vector3 size, float rotation)
	:TextureRect(position, size, rotation)
{
	
}

Player::~Player()
{

}

void Player::Jump()
{
	static float fJumpFrame=0;
	if (fJumpPower == 0)
	{
		fJumpFrame = 0;
	}

	//상승 상황 점프
	if (fJumpPower <= fMaxJumpSpeed)
	{
		if (fJumpPower >= 0)
		{
			fJumpPower = fMaxJumpSpeed - Math::Lerpf(0, fMaxJumpSpeed, fJumpFrame);
			fJumpFrame += 0.01f;
			Move({ 0,fJumpPower,0 });
			MoveLocalRect(Vector4(0, fJumpPower, 0, fJumpPower));
		}
		else
		{
			fJumpFrame = 0;
			fJumpPower = 0;
			isJump = false;
		}
	}
	
}

void Player::Update()
{
	GroundIntersect = Math::GroundIntersect(this);

	if (!GroundIntersect)
	{
		Move({ 0, -2, 0});
		MoveLocalRect(Vector4(0, -2, 0, -2));
	}
	else
	{
		nJumpCount = 0;
	}

	if (Keyboard::Get()->Down(VK_SPACE)&&nJumpCount < nMaxJumpCount)
	{
		nJumpCount++;
		isJump=true;
		fJumpPower = 0;
		cout << "점프" << endl;
	}

	if (isJump)
	{
		Jump();
	}
}
