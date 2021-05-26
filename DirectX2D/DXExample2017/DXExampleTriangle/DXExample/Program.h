#pragma once


struct VertexColor
{
	D3DXVECTOR3 position;
	D3DXCOLOR color;
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

	ID3D11VertexShader* vertexShader;
	ID3DBlob* vsBlob;
	ID3D11PixelShader* pixelShader;
	ID3DBlob* psBlob;
};