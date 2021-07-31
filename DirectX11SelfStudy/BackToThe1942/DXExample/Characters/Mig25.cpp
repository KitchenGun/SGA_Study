#include "stdafx.h"
#include "Mig25.h"
#include "Utilities/Animator.h"

Mig25::Mig25(Vector3 position, Vector3 size, float rotation)
	:
	AnimationRect(position,size,rotation)
{
	SetAnimation();
}

Mig25::~Mig25()
{
	AnimationRect::~AnimationRect();
}

void Mig25::Update()
{
	Fire();
	Move(Vector3(0, fSpeed, 0)*Time::Delta());
}

void Mig25::Move(Vector3 position)
{
	AnimationRect::Move(position);
}

void Mig25::Fire()
{
	if (deltaTime > FireRate)//���� �ð� ���� ������ 
	{
		EnemyBM->AddProjectile(position + Vector3(0, -60, 0));
		deltaTime = 0.0f;
	}
	else//�۵�ȯ��� ������� �����ϰ� �����ش�
		deltaTime += Time::Delta();
}

void Mig25::SetAnimation()
{
	texture = new Texture2D(L"./_Textures/Mig25.png");
}
