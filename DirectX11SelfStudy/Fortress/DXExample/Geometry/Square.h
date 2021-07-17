#pragma once


struct RectEdges //�𼭸� ��ǥ
{
	Vector3 LT;
	Vector3 RB;
};

class Square
{
public:
	Square(Vector3 position, Vector3 size, float rotation,Color color);
	~Square();

	void Move(Vector3 position);

	virtual void Update();
	void Render();

	void SetColor(Color color);
	RectEdges GetTransformedCoord() { return r; }

	void SetIntersect(bool bIntersect) { this->bIntersect = bIntersect; }

protected:
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
	WorldBuffer*WB=nullptr;
	Matrix world, S, R, T;
	Vector3 position, size;
	float rotation;
	Color color;
	
	RectEdges r;
	ColorBuffer* CB = nullptr;
	bool bIntersect = false;

};