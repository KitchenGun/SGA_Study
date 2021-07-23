#pragma once

class FilledCircle
{
public:
	FilledCircle(Vector3 position, Vector3 size, int segments, Color color);
	~FilledCircle();

	void SetColor(Color color);

	void Update();
	void Render();


private:
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

	bool bIntersect = false;


};