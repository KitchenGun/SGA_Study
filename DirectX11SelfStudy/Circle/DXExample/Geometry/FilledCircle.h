#pragma once

struct CircleEdges //모서리 좌표
{
	Vector3 POINT;
	float RADIUS;
};

class FilledCircle
{
public:
	FilledCircle(Vector3 position, Vector3 size, int segments, Color color);
	~FilledCircle();

	void SetColor(Color color);

	void Move();

	void Update();
	void Render();
	CircleEdges GetTransformedCoord() { return ce; }

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
	ColorBuffer* CB = nullptr;
	WorldBuffer*WB = nullptr;
	Matrix world, S, T;
	Vector3 position, size;
	Color color;
	int segments;
	CircleEdges ce;
	bool bIntersect = false;


};