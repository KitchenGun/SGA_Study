#pragma once

class Circle
{
public:
	Circle(Vector3 position, Vector3 size, int segments, Color color);
	~Circle();

	void SetColor(Color color);

	void Update();
	void Render();


private:
	//����
	vector<VertexColor> vertices;
	InputLayout* IL = nullptr;
	//buffer
	VertexBuffer *VB = nullptr;
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