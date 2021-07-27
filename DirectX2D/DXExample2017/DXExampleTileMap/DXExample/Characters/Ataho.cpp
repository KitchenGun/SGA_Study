#include "stdafx.h"
#include "Ataho.h"
#include "Utilities/Animator.h"

Ataho::Ataho(Vector3 position, Vector3 size, float rotation)
	:
AnimationRect(position, size, rotation)
{
	SetAnimation();
}

Ataho::~Ataho()
{
}

void Ataho::Update()
{
	Input();
	AnimationRect::Update();
}

void Ataho::Move(Vector3 position)
{
	AnimationRect::Move(position);
	if (position.y > 0)//�������� �̵��ϴ� ���
		animator->SetCurrentAnimClip(L"RunF");
	else if (position.y < 0)//�Ʒ������� �̵��ϴ� ���
		animator->SetCurrentAnimClip(L"RunB");
	if (!isAxisDirInput)
	{
		if (position.x > 0)//���������� �̵��ϴ� ���
			animator->SetCurrentAnimClip(L"RunR");
		else if (position.x < 0)//�������� �̵��ϴ� ���
			animator->SetCurrentAnimClip(L"RunL");
	}
}

void Ataho::Input()
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
		isAxisDirInput = false;
}

void Ataho::SetAnimation()
{
	//�ؽ��� �ּ� �Է��Ͽ��� �ؽ��� �ڿ� ����
	texture = new Texture2D(L"./_Textures/Ataho.png");
	//����
	animClips.push_back(new AnimationClip(L"RunB", texture, 5, { 0, 0 }, { (float)texture->GetWidth() / 2, (float)texture->GetHeight() / 2 }));
	animClips.push_back(new AnimationClip(L"RunF", texture, 5, { 0, (float)texture->GetHeight() / 2 }, { (float)texture->GetWidth() / 2, (float)texture->GetHeight() }, true));
	//�¿�												  
	animClips.push_back(new AnimationClip(L"RunL", texture, 5, { (float)texture->GetWidth() / 2, 0 }, { (float)texture->GetWidth(), (float)texture->GetHeight() / 2 }));
	animClips.push_back(new AnimationClip(L"RunR", texture, 5, { (float)texture->GetWidth() / 2, (float)texture->GetHeight() / 2 }, { (float)texture->GetWidth(), (float)texture->GetHeight() }, true));
	animator = new Animator(animClips);
}
