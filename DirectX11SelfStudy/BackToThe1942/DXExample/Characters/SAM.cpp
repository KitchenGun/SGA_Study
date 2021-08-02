#include "stdafx.h"
#include "SAM.h"
#include "Utilities/Animator.h"

SAM::SAM(Vector3 position, Vector3 size, float rotation)
	:
	AnimationRect(position, size, rotation)
{
	SetAnimation();
	animator->SetCurrentAnimClip(L"RotationL");
	animator->bLoop = false;
}

SAM::~SAM()
{
	AnimationRect::~AnimationRect();
}

void SAM::Update()
{
	Rotation();
	AnimationRect::Update();
	Fire();
}

void SAM::SetAnimation()
{
	//�ؽ��� �ּ� �Է��Ͽ��� �ؽ��� �ڿ� ����
	texture = new Texture2D(L"./_Textures/SAM.png");
	animClips.push_back(new AnimationClip(L"RotationL", texture, 6, { 0, 0 }, { (float)texture->GetWidth()/11*6,(float)texture->GetHeight()},true));
	animClips.push_back(new AnimationClip(L"RotationR", texture, 6, { (float)texture->GetWidth() / 11 * 5, 0 }, { (float)texture->GetWidth(),(float)texture->GetHeight() }));
	animator = new Animator(animClips);
}

void SAM::Rotation()
{
	fangle = atan2(Target->GetPosition().y - position.y, Target->GetPosition().x-position.x);
	//Ÿ���� ���� ���� ���
	if (D3DXToDegree(fangle) > 90)
	{
		animator->SetCurrentAnimClip(L"RotationL",false);
	}
	else if (D3DXToDegree(fangle) > 0 && D3DXToDegree(fangle) < 90)
	{
		animator->SetCurrentAnimClip(L"RotationR", false);
	}
	else//Ÿ���� �ؿ� ���� ���
	{
		if (-16 < D3DXToDegree(fangle) && D3DXToDegree(fangle) <= 0)
		{
			animator->SetCurrentAnimClip(L"RotationR", false);
			animator->SetIndex(5);
		}
		else if (-32 < D3DXToDegree(fangle) && D3DXToDegree(fangle) <= -16)
		{
			animator->SetCurrentAnimClip(L"RotationR", false);
			animator->SetIndex(4);
		}
		else if (-48 < D3DXToDegree(fangle) && D3DXToDegree(fangle) <= -32)
		{
			animator->SetCurrentAnimClip(L"RotationR", false);
			animator->SetIndex(3);
		}
		else if (-64 < D3DXToDegree(fangle) && D3DXToDegree(fangle) <= -48)
		{
			animator->SetCurrentAnimClip(L"RotationR", false);
			animator->SetIndex(2);
		}
		else if (-80 < D3DXToDegree(fangle) && D3DXToDegree(fangle) <= -64)
		{
			animator->SetCurrentAnimClip(L"RotationR", false);
			animator->SetIndex(1);
		}
		else if (-96 < D3DXToDegree(fangle) && D3DXToDegree(fangle) <= -80)
		{
			animator->SetCurrentAnimClip(L"RotationR", false);
			animator->SetIndex(0);
		}
		else if (-112 < D3DXToDegree(fangle) && D3DXToDegree(fangle) <= -96)
		{
			animator->SetCurrentAnimClip(L"RotationL", false);
			animator->SetIndex(5);
		}
		else if (-128 < D3DXToDegree(fangle) && D3DXToDegree(fangle) <= -112)
		{
			animator->SetCurrentAnimClip(L"RotationL", false);
			animator->SetIndex(4);
		}
		else if (-144 < D3DXToDegree(fangle) && D3DXToDegree(fangle) <= -128)
		{
			animator->SetCurrentAnimClip(L"RotationL", false);
			animator->SetIndex(3);
		}
		else if (-160 < D3DXToDegree(fangle) && D3DXToDegree(fangle) <= -144)
		{
			animator->SetCurrentAnimClip(L"RotationL", false);
			animator->SetIndex(2);
		}
		else if (-176 < D3DXToDegree(fangle) && D3DXToDegree(fangle) <= -160)
		{
			animator->SetCurrentAnimClip(L"RotationL", false);
			animator->SetIndex(1);
		}
		else if (D3DXToDegree(fangle) <= -176)
		{
			animator->SetCurrentAnimClip(L"RotationL", false);
			animator->SetIndex(0);
		}
	}
}

void SAM::Fire()
{
	if (deltaTime > FireRate)//���� �ð� ���� ������ 
	{
		EnemyBM->AddMissileProjectile(position,Target);
		deltaTime = 0.0f;
	}
	else//�۵�ȯ��� ������� �����ϰ� �����ش�
		deltaTime += Time::Delta();
}
