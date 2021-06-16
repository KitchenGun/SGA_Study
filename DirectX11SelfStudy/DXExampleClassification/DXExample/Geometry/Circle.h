#pragma once

struct CircleInfo //�� ��ǥ
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

	RectEdges GetTransformedCoord() { return r; }

private:
	void TransformVertices();
	//����
	vector<VertexColor> vertices;
	vector<UINT> indices;
	InputLayout* IL = nullptr;
	//buffer
	VertexBuffer *VB = nullptr;
	IndexBuffer *IB = nullptr;
	//���̴�
	VertexShader *VS = nullptr;
	PixelShader *PS = nullptr;
	//������� ũ�� ȸ�� �̵� ���� ���
	WorldBuffer*WB = nullptr;
	D3DXMATRIX world, S, R, T;
	D3DXVECTOR3 position, size;
	float rotation;

	RectEdges r;
	ColorBuffer* CB = nullptr;
	bool bIntersect = false;


};