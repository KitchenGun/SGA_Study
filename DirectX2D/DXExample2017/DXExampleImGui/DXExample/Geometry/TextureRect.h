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

	void SetOutline(bool bOutline)
	{
		data.bOutline = bOutline;
	}

	struct Struct
	{//������ �е�
		int selection = 1;															//4����Ʈ
		Vector2 texturSize = { WinMaxWidth,WinMaxHeight };//���ǿ� ���ÿ� �ʱ�ȭ		//8����Ʈ
		bool bOutline = false;													//1����Ʈ
		bool dummy[3];																//3����Ʈ
	};

private:
	Struct data;
};

class BlurBuffer : public ShaderBuffer
{
public:
	BlurBuffer()
		:ShaderBuffer(&data, sizeof(Struct))
	{
	}

	void SetCount(int count)
	{
		data.count = count;
	}
	struct Struct
	{
		UINT count;
		Vector3 dummy;
	};
private:
	Struct data;
};

class LocalBuffer : public ShaderBuffer
{
public:
	LocalBuffer()
		: ShaderBuffer(&data, sizeof(Struct))
	{}

	void MoveLocalRect(Vector4 moveLocalRect)
	{
		data.localRect += moveLocalRect;
	}

	void SetLocalRect(Vector4 localRect)
	{
		data.localRect = localRect;
	}

	Vector4 GetLocalRect()
	{
		return data.localRect;
	}

	struct Struct
	{
		Vector4 localRect;
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
	//��ȿ�� �̵� �Լ�
	void MoveLocalRect(Vector4 localMove);

	void Update();
	void Render();
	
	void GUI(int ordinal);

private:
	//��� ��ü �Լ�
	void ChangeImageFunc(const wstring& path = L"");
	void ChangeShaderFunc(const wstring& path = L"");
	void SaveTextAsFile(const string& text,const wstring& path = L"");

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
	ID3D11ShaderResourceView* nullView = nullptr;


	SelectBuffer* SB = nullptr;
	BlurBuffer* BB = nullptr;
	LocalBuffer* LB = nullptr;
	//���
	wstring texturePath = L"";
	wstring shaderPath = L"";
	char text[255] = "";
};