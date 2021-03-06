#pragma once


struct RectEdges //모서리 좌표
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
	//정보
	vector<VertexColor> vertices;
	vector<UINT> indices;
	InputLayout* IL = nullptr;
	//buffer
	VertexBuffer *VB = nullptr;
	IndexBuffer *IB = nullptr;
	//쉐이더
	VertexShader *VS = nullptr;
	PixelShader *PS = nullptr;
	//상수버퍼 크기 회전 이동 관련 행렬
	WorldBuffer*WB=nullptr;
	D3DXMATRIX world, S, R, T;
	D3DXVECTOR3 position, size;
	float rotation;
	
	RectEdges r;
	ColorBuffer* CB = nullptr;
	bool bIntersect = false;


};