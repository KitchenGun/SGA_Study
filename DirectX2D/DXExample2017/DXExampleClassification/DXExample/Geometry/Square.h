#pragma once


struct RectEdges
{
	D3DXVECTOR3 LT;
	D3DXVECTOR3 RB;
};

class Square
{
public:
	Square(D3DXVECTOR3 position, D3DXVECTOR3 size, float rotation);
	~Square();

	void Move(D3DXVECTOR3 position);

	void Update();
	void Render();

	RectEdges GetTransformedCoord() { return r; }

private:
	void TransformVertices();

	vector<VertexColor> vertices;
	vector<UINT> indices;
	InputLayout* IL = nullptr;

	VertexBuffer *VB = nullptr;
	IndexBuffer *IB = nullptr;

	VertexShader *VS = nullptr;
	PixelShader *PS = nullptr;

	WorldBuffer*WB=nullptr;
	D3DXMATRIX world, S, R, T;
	D3DXVECTOR3 position, size;
	float rotation;

	RectEdges r;
	ColorBuffer* CB = nullptr;
	bool bIntersect = false;


};