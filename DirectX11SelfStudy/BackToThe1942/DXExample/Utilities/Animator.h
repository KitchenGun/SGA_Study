#pragma once

class AnimationClip
{
public:
	AnimationClip(wstring clipName, Texture2D* srcTex, UINT frameCount, Vector2 startPos, Vector2 endPos, bool bReverse = false);
	~AnimationClip();

	ID3D11ShaderResourceView* GetSRV() { return srv; }
	Vector2 GetKeyframe(UINT index) { return keyframes[index]; }//�׾Ƶ� Ű �������� �ε����� ���ؼ� ������ ������ ȹ��
	Vector2 GetTexelFrameSize() { return texelFrameSize; }
	UINT GetFrameCount() { return frameCount; }
	UINT GetLastFrameIndex() { return keyframes.size()-1; } //������ ���� �޴� ���̴� �׷��� ������ -1�ϴ� ���̴�.
	bool GetIsReverse() { return bReverse; }

	wstring GetClipName() { return clipName; }

private:
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
	Animator(vector<AnimationClip*> animClips);
	~Animator();

	void Update();
	void Render(UINT slotIndex = 0);

	Vector2 GetCurrentFrame() { return currentFrame; }
	Vector2 GetTexelFrameSize() { return currentAnimClip->GetTexelFrameSize(); }

	void AddAnimClip(AnimationClip* animClip);
	void SetCurrentAnimClip(wstring clipName,bool GetCurIndex = false);

	bool bLoop = true;
	float playRate = 1.0f / 10.0f;//���ϵ鿡 ���缭 �����ؾ��� �и� Ŀ���� �� ������ ����� �ȴ�
	bool bStop = false;

private:
	//�ڷᱸ�� map�� �ٸ��� �ߺ� ������ ��� ���ϰ� map�� ���Ͽ� �����Ͱ� ������ ������ Ž���ɷ��� ������
	unordered_map<wstring, AnimationClip*> animClips;
	AnimationClip* currentAnimClip = nullptr;

	float deltaTime = 0.0f;
	int currentFrameIndex = 0;
	Vector2 currentFrame = Vector2(0, 0);
	Vector2 TexelFrameSize = Vector2(0, 0);
};