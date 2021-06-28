#pragma once
class SelectBuffer : public ShaderBuffer
{
public:
	SelectBuffer()
		:ShaderBuffer(&data, sizeof(Struct))
	{

	}

	void SetSelection(int selection)
	{
		data.selection = selection;
	}

	struct Struct
	{//������ �е�
		int selection = 1;
		Vector3 dummy;//������°��̶� 16����Ʈ�� �����ذ��� ���� �ʿ����
	};

private:
	Struct data;
};

class TextureRect
{
public:
	TextureRect(Vector3 position, Vector3 size, float rotation);
	~TextureRect();

	void SetSRV(ID3D11ShaderResourceView* SRV) { this->srv = SRV; }
	void SetSRV(wstring path);
	
	void SetShader(wstring shaderPath);
	
	void Move(Vector3 position);

	void Update();
	void Render();
	

private:
	vector<VertexTexture> vertices;
	vector<UINT> indices;
	InputLayout*IL = nullptr;

	VertexBuffer*VB = nullptr;
	IndexBuffer*IB = nullptr;

	VertexShader* VS = nullptr;
	PixelShader* PS = nullptr;
	WorldBuffer* WB = nullptr;
	Matrix world, S, R, T;
	Vector3 position, size;
	float rotation;

	ID3D11ShaderResourceView* srv = nullptr;
	SelectBuffer* SB = nullptr;

};