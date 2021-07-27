#include "stdafx.h"
#include "Rockman.h"
#include "Utilities/Animator.h"

Rockman::Rockman(Vector3 position, Vector3 size, float rotation)
	:
	AnimationRect(position, size, rotation)
{
	SetAnimation();
}

Rockman::~Rockman()
{

}

void Rockman::Move(Vector3 position)
{
	AnimationRect::Move(position);

	if (position.x > 0)//���������� �̵��ϴ� ���
		animator->SetCurrentAnimClip(L"RunR");
	else if (position.x < 0)//�������� �̵��ϴ� ���
		animator->SetCurrentAnimClip(L"RunL");
}

void Rockman::SetAnimation()
{
	//�ؽ��� �ּ� �Է��Ͽ��� �ؽ��� �ڿ� ����
	texture = new Texture2D(L"./_Textures/�ϸ�.bmp");
	//�ִϸ��̼� ��ü�� ����µ� �¿�� ������ ����
													//�̹��� ����,���� ��	,����
	animClips.push_back(new AnimationClip(L"RunR", texture, 10, { 0, 0 }, { (float)texture->GetWidth(), (float)texture->GetHeight() / 2 }));
	animClips.push_back(new AnimationClip(L"RunL", texture, 10, { 0, (float)texture->GetHeight() / 2 }, { (float)texture->GetWidth(), (float)texture->GetHeight() }, true));
	animator = new Animator(animClips);
}
