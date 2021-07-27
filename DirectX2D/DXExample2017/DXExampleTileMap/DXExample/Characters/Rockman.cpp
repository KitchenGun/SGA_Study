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

	if (position.x > 0)//오른쪽으로 이동하는 경우
		animator->SetCurrentAnimClip(L"RunR");
	else if (position.x < 0)//왼쪽으로 이동하는 경우
		animator->SetCurrentAnimClip(L"RunL");
}

void Rockman::SetAnimation()
{
	//텍스쳐 주소 입력하여서 텍스쳐 자원 제작
	texture = new Texture2D(L"./_Textures/록맨.bmp");
	//애니메이션 객체를 만드는데 좌우로 나눠서 제작
													//이미지 갯수,시작 점	,끝점
	animClips.push_back(new AnimationClip(L"RunR", texture, 10, { 0, 0 }, { (float)texture->GetWidth(), (float)texture->GetHeight() / 2 }));
	animClips.push_back(new AnimationClip(L"RunL", texture, 10, { 0, (float)texture->GetHeight() / 2 }, { (float)texture->GetWidth(), (float)texture->GetHeight() }, true));
	animator = new Animator(animClips);
}
