#pragma once

struct LinePoint
{
	Vector2 First;
	Vector2 Second;
};

class Line
{
public:
	Line(Vector3 position, float length, float rotation,Color color);//����� �ʿ������ ���̷� ��ü��
	~Line();

	virtual void Update();
	void Render();

	void Rotation(float rotation);

	void TransPoint();
	void SetColor(Color color);
	LinePoint GetLP() { return LP; }
protected:
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
	LinePoint LP;
	
	ColorBuffer* CB = nullptr;
};