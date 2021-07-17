#pragma once

struct CircleInfo //�𼭸� ��ǥ
{
	Vector3 POINT;
	float R;
};


class FilledCircle
{
public:
	FilledCircle(Vector3 position, Vector3 size, int segments, Color color);
	virtual ~FilledCircle();

	void SetColor(Color color);

	virtual void Update();
	void Render();
	

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
	ColorBuffer* CB = nullptr;
	WorldBuffer*WB = nullptr;
	Matrix world, S, T;
	Vector3 position, size;
	Color color;
	int segments;
	CircleInfo CI;


	bool bIntersect = false;


};