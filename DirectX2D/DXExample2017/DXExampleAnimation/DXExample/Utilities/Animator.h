#pragma once

class AnimationClip
{
public:
	AnimationClip(wstring clipName, Texture2D* srcTex, UINT frameCount, Vector2 startPos, Vector2 endPos, bool bReverse = false);
	~AnimationClip();
	ID3D11ShaderResourceView* GetSRV() { return srv; }
	Vector2 GetKeyframe(UINT index) { return keyframes[index]; }
	Vector2 GetTexelFrameSize() { return texelFrameSize; }
	UINT GetLastFrameIndex() { return keyframes.size() - 1; }
	bool GetIsReverse() { return bReverse; }
	wstring GetClipName() { return clipName; }

private :
	wstring clipName = L"";
	vector<Vector2> keyframes;
	UINT frameCount = 0;
	ID3D11ShaderResourceView* srv = nullptr;

	Vector2 texelFrameSize;

	bool bReverse = false;
};

class Animator
{
public:
	Animator(AnimationClip* animClip);
	~Animator();

	void Update();
	void Render(UINT slotIndex = 0);

	Vector2 GetCurrentFrame() { return currentFrame; }
	Vector2 GetTexelFrameSize() { return currentAnimClip->GetTexelFrameSize(); }

	void AddAnimClip(AnimationClip* animClip);
	void SetCurrentAnimClip(wstring clipName);

	bool bLoop = true;
	float playRaye = 1.0f / 15.0f;
	bool bStop = false;
private :
	unordered_map<wstring, AnimationClip*> animClips;
	AnimationClip* currentAnimClip = nullptr;
	Vector2 currentFrame = Vector2(0, 0);
	Vector2 TexelFrameSize = Vector2(0, 0);
};