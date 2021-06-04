#pragma once


struct VertexColor
{
	D3DXVECTOR3 position;
	D3DXCOLOR color;
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

private:
	VertexColor* vertices = nullptr;
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

	TransformData cpuBuffer;
	ID3D11Buffer *gpuBuffer=nullptr;
};