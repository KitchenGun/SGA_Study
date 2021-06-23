#pragma once



class Line
{
public:
	Line(Vector3 position, float length, float rotation,Color color);//����� �ʿ������ ���̷� ��ü��
	~Line();

	virtual void Update();
	void Render();

	void Rotation(float rotation);


	void SetColor(Color color);

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

	
	ColorBuffer* CB = nullptr;
};