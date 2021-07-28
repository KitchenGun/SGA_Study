#include "stdafx.h"
#include "Player.h"
#include "Utilities/Animator.h"

Player::Player(Vector3 position, Vector3 size, float rotation)
	:
AnimationRect(position, size, rotation)
{
}

Player::~Player()
{
}

void Player::Update()
{
}

void Player::Move(Vector3 position)
{
}

void Player::Input()
{
}

void Player::SetAnimation()
{
}
