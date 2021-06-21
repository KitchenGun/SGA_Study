#pragma once



class Line
{
public:
	Line(Vector3 position, float length, float rotation,Color color);
	~Line();

	void Update();
	void Render();

	void SetColor(Color color);

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
	WorldBuffer*WB=nullptr;
	Matrix world, S, R, T;
	Vector3 position;
	float rotation;
	float length;
	Color color;
	
	ColorBuffer* CB = nullptr;
};