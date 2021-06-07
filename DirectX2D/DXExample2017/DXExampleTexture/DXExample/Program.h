#pragma once



struct VertexColor
{
	D3DXVECTOR3 position;
	D3DXCOLOR color;
};

struct VertexTexture
{
	D3DXVECTOR3 position;
	D3DXVECTOR2 uv;  //����ȭ �Ͽ��� 0~1 ������ ����� �ִ´� 0,0�� �»��  1,1�� ���ϴ�
	//���� �ε����� �����ϰ� uv������ �־��ָ�� 
};

struct TransformData
{
	D3DXMATRIX world;
	D3DXMATRIX view;
	D3DXMATRIX projection;
};

class Program
{
public:
	Program();
	~Program();

	void Update();
	void Render();
	void Action();

private:
	//VertexColor* vertices = nullptr;
	VertexTexture* vertices = nullptr;
	ID3D11Buffer* vertexBuffer = nullptr;
	ID3D11InputLayout* inputLayout = nullptr;

	UINT *indices = nullptr;
	ID3D11Buffer* indexBuffer = nullptr;

	ID3D11VertexShader* vertexShader;
	ID3DBlob* vsBlob;
	ID3D11PixelShader* pixelShader;
	ID3DBlob* psBlob;

	//dx �޼� ��ǥ�� 
	//D3DXMATRIX 4*4 ����� ���� ����� ������ Ŭ����  ��� �̵��� ���� �����ڵ��� ������ ����
	D3DXMATRIX world;			//���� ��ǥ
	D3DXMATRIX view;			//ī�޶� ��ȯ ī�޶� �����ؼ� ���� ����
	D3DXMATRIX projection;		//���� ��ȯ ���������� ��������
	//���� ���ú���
	int nTurnCount = 500;
	float fRotangle = 5.0f;
	D3DXMATRIX S, R, T;
	POINT pos;
	float angle = 0;
	//
	TransformData cpuBuffer;
	ID3D11Buffer *gpuBuffer=nullptr;

	ID3D11RasterizerState* rsState = nullptr;

	//���̴����� �� ����Ÿ�ٺ�
	ID3D11ShaderResourceView* SRV;
	ID3D11SamplerState* samplerState;

};