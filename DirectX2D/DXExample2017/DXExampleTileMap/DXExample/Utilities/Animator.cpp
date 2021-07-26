#include "stdafx.h"
#include "Animator.h"

AnimationClip::AnimationClip(wstring clipName, Texture2D* srcTex, UINT frameCount, Vector2 startPos, Vector2 endPos, bool bReverse)
	: clipName(clipName), 
	frameCount(frameCount), 
	bReverse(bReverse)
{
	//clip�̶� �ִϸ��̼� ������ ����
	//�ؽ��� ������
	srv = srcTex->GetSRV();

	float imageWidth = (float)srcTex->GetWidth();
	float imageHeight = (float)srcTex->GetHeight();
	
	//�̹��� ����
	Vector2 clipSize = Math::absVec2(endPos - startPos);
	Vector2 frameSize;
	//�ִϸ��̼����� ����� �̹����� ������� ũ��� �ڸ����ΰ�?
	frameSize.x = clipSize.x / frameCount;
	frameSize.y = clipSize.y;
	//�̹����� ȭ�Ҹ� �ؼ��̶�� ��
	Vector2 texelSize = Vector2(1.0f / imageWidth, 1.0f / imageHeight);
							//ȭ������� �������� �ؼ��������� ���� ����
	Vector2 texelStartPos = Vector2(startPos.x * texelSize.x, startPos.y * texelSize.y);
	texelFrameSize = Vector2(frameSize.x * texelSize.x, frameSize.y * texelSize.y);
	//�̹��� ������ŭ ���� ex ���� 10�� ����
	for (UINT i = 0; i < frameCount; i++)
	{
		Vector2 keyframe;
		keyframe.x = texelStartPos.x + texelFrameSize.x * i;//�̹����� ���� ��ǥ
		keyframe.y = texelStartPos.y;
		keyframes.push_back(keyframe);
	}
}

AnimationClip::~AnimationClip()
{
}

Animator::Animator(AnimationClip* animClip)
	: currentAnimClip(animClip)
{
	//�ڷᱸ���� ��������� Ű(�̸�)�� ���� ������(Ŭ��)�� �߰���
	animClips.insert(make_pair(animClip->GetClipName(), animClip));
}

Animator::Animator(vector<AnimationClip*> animClips)
	:currentAnimClip(animClips[0])
{
	for (AnimationClip* animClip : animClips)
	{
		this->animClips.insert(make_pair(animClip->GetClipName(), animClip));
	}
}

Animator::~Animator()
{

}

void Animator::Update()
{
	if (bStop) return;
	
	//cout << deltaTime << " " << playRate << endl;
	//�����ӿ��� ���������� �Ѿ�� �ð�
	if (deltaTime > playRate)//���� �ð� ���� �����Ͽ� �׸� ���� �� 
	{
		if (currentAnimClip->GetIsReverse() == false)//���� ���� 
		{
			currentFrameIndex++;
			if (currentFrameIndex >= currentAnimClip->GetFrameCount() && bLoop)//�ݺ��� ��ų �� �̹����� �ݺ��Ѵ�
				currentFrameIndex = 0;
			currentFrame = currentAnimClip->GetKeyframe(currentFrameIndex);//������ ��ǥ�� ���� ���������� ����ڴ�.
		}
		else
		{
			//�Ųٷ� �����°�
			currentFrameIndex--;
			if (currentFrameIndex <= 0 && bLoop)
				currentFrameIndex = currentAnimClip->GetLastFrameIndex();
			currentFrame = currentAnimClip->GetKeyframe(currentFrameIndex);
		}
		//��ŸŸ���� �ʱ�ȭ update�������� ��ü �Ǳ� ������ �ʱ�ȭ �ؾ��Ѵ�
		deltaTime = 0.0f;
	}
	else//�۵�ȯ��� ������� �����ϰ� �����ش�
		deltaTime += Time::Delta();
}

void Animator::Render(UINT slotIndex)
{
}

void Animator::AddAnimClip(AnimationClip* animClip)
{//�ִϸ��̼� Ŭ���߰�
	animClips.insert(make_pair(animClip->GetClipName(), animClip));
}

void Animator::SetCurrentAnimClip(wstring clipName)// Ŭ�� �̸��� �°� ����
{
	//���� Ŭ���� ���
	if (clipName == currentAnimClip->GetClipName()) return;
	//�ƴҰ�� Ž��   //end�� ������ ������ �̾߱��� ������ ����Ʈ
	//���� �̸��� ���� ��츸  �ٲ��ش�
	if (animClips.find(clipName) != animClips.end())
	{
		//Ŭ������ ��ü�� ����
		currentAnimClip = animClips.find(clipName)->second;
		//������ ó������ �����ؾ��ϱ� ������
		deltaTime = 0.0f;
		if (currentAnimClip->GetIsReverse())
			currentFrameIndex = currentAnimClip->GetLastFrameIndex();
		else
			currentFrameIndex = 0;
		currentFrame = currentAnimClip->GetKeyframe(currentFrameIndex);
	}
}
