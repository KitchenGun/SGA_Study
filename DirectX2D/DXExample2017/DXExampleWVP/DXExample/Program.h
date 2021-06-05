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
	void Action();

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

	//dx 왼손 좌표계 
	//D3DXMATRIX 4*4 행렬의 연산 기능을 포함한 클래스  행렬 이동을 위한 연산자들을 가지고 있음
	D3DXMATRIX world;			//월드 좌표
	D3DXMATRIX view;			//카메라 변환 카메라를 원점해서 만든 공간
	D3DXMATRIX projection;		//투영 변환 원근투영과 직교투영

	int nTurnCount = 500;
	float fRotangle = 5.0f;
	float fSpeed = 250.0f;
	D3DXMATRIX S, R, T;
	POINT pos;
	float angle = 0;

	TransformData cpuBuffer;
	ID3D11Buffer *gpuBuffer=nullptr;
};