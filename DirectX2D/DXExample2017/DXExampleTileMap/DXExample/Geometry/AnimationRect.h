#pragma once

class Animator;
class AnimationClip;

class AnimationRect
{
public:
	AnimationRect(Vector3 position, Vector3 size, float rotation);
	~AnimationRect();

	void Update();
	void Render();

	void Move(Vector3 position);
	Vector3 GetPosition() { return position; }
private:
	vector<VertexTexture> vertices;
	vector<UINT> indices;
	InputLayout* IL = nullptr;

	VertexBuffer* VB = nullptr;
	IndexBuffer* IB = nullptr;

	VertexShader* VS = nullptr;
	PixelShader* PS = nullptr;

	WorldBuffer* WB = nullptr;
	Matrix world, S, R, T;
	Vector3 position, size;
	float rotation;

	Animator* animator = nullptr;
	AnimationClip* runR = nullptr;
	AnimationClip* runL = nullptr;
	Texture2D* rockman = nullptr;

	ID3D11BlendState* BS;
	ID3D11SamplerState* SS;
};