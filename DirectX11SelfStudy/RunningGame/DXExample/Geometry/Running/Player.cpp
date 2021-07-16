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
	static float fJumpFrame = 0;
	if (fJumpPower == 0)
	{
		fJumpFrame = 0;
	}
	
	//상승 상황 점프
	if (fJumpPower <= fMaxJumpSpeed)
	{
		fJumpPower = fMaxJumpSpeed - Math::Lerpf(0, fMaxJumpSpeed, fJumpFrame);
		fJumpFrame += 0.01f;
		Move({ 0,fJumpPower,0 });
		MoveLocalRect(Vector4(0, fJumpPower, 0, fJumpPower));
	}
	GroundIntersect = Math::GroundIntersect(this);
	if (GroundIntersect == true)
	{
		SetPosition(Vector3(150, 50, 0));
		fJumpPower = 0;
		isJump = false;
	}
	
}

void Player::Update()
{
	if(GroundIntersect)
	{
		nJumpCount = 0;
	}
	else
	{
		Move({ 0,GravatiyPower,0 });
		MoveLocalRect(Vector4(0, GravatiyPower, 0, GravatiyPower));
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

void Player::SetPosition(Vector3 position)
{
	this->position = position;
	D3DXMatrixTranslation(&T, this->position.x, this->position.y, this->position.z);

	world = S * R * T;
	WB->SetWorld(world);
	LB->SetLocalRect({ 100,100,200,0 });
}
