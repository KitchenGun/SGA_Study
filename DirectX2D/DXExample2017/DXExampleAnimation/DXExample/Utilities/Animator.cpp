#include "stdafx.h"
#include "Animator.h"

AnimationClip::AnimationClip(wstring clipName, Texture2D * srcTex, UINT frameCount, Vector2 startPos, Vector2 endPos, bool bReverse)
	:clipName(clipName),
	frameCount(frameCount),
	bReverse(bReverse)
{
	srv = srcTex->GetSRV();
	
	float imageWidth = (float)srcTex->GetWidth();
	float imageHeight = (float)srcTex->GetHeight();
	Vector2 clipSize = Math::absVec2(endPos - startPos);
	Vector2 frameSize;

	frameSize.x = clipSize.x / frameCount;
	frameSize.y = clipSize.y;

	Vector2 texelSize = Vector2(1.0f / imageWidth, 1.0f / imageHeight);

	Vector2 texelStartPos = Vector2(startPos.x*texelSize.x, startPos.y*texelSize.y);
	texelFrameSize = Vector2(frameSize.x*texelSize.x, frameSize.y*texelSize.y);
	for (UINT i = 0; i < frameCount; i++)
	{
		Vector2 keyframe;
		keyframe.x = texelStartPos.x + texelFrameSize.x*i;
		keyframe.y = texelStartPos.y + texelFrameSize.y*i;
		keyframes.push_back(keyframe);
	}
}

AnimationClip::~AnimationClip()
{
}

Animator::Animator(AnimationClip* animClip)
	:
	currentAnimClip(animClip)
{
	animClips.insert(make_pair(animClip->GetClipName(), animClip));
}

Animator::~Animator()
{
	if (bStop) return;
	if (deltaTime > playRate)
	{
		if (currentAnimClip->GetIsReverse() == false)
		{
			currentframeIndex++;
			if (currentFrameIndex >= currentAnimClip->GetFrameCount() && bLoop)
				currentFrameIndex = currentAnimClip->GetKeyframe(currentFrameIndex);
			currentFrame = currentAnimClip->GetKeyframe(currentFrameIndex);
		}
		deltaTime = 0.0f;
	}
	else
		deltaTime += Time::Delta();
}

void Animator::Update()
{

}

void Animator::Render(UINT slotIndex)
{

}

void Animator::AddAnimClip(AnimationClip * animClip)
{
	animClips.insert(make_pair(animClip->GetClipName(), animClip));
}

void Animator::SetCurrentAnimClip(wstring clipName)
{
	if (clipName == currentAnimClip->GetClipName()) return;

	if (animClips.find(clipName) != animClips.end())
	{
		currentAnimClip = animClips.find(clipName)->second;
		deltaTime = 0.0f;
		if (currentAnimClip->GetIsReverse())
			currentFrameIndex = currentAnimClip->GetLastFrameIndex();
		else
			currentFrameIndex = 0;
		currentFrame = currentAnimClip->GetKeyframe(currentframeIndex);
	}
}
