#pragma once

struct CircleInfo //원 좌표
{
	D3DXVECTOR3 POINT;
	float RADIUS;
};

class Circle
{
public:
	Circle(D3DXVECTOR3 position, D3DXVECTOR3 size, float rotation);
	~Circle();

	void Move(D3DXVECTOR3 position);

	void Update();
	void Render();

	CircleInfo GetTransformedCoord() { return CI; }

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
	WorldBuffer*WB = nullptr;
	D3DXMATRIX world, S, R, T;
	D3DXVECTOR3 position, size;
	float rotation;

	CircleInfo CI;
	ColorBuffer* CB = nullptr;
	bool bIntersect = false;


};