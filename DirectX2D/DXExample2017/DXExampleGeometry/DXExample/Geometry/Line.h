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
	//정보
	vector<VertexColor> vertices;
	InputLayout* IL = nullptr;
	//buffer
	VertexBuffer *VB = nullptr;
	//쉐이더
	VertexShader *VS = nullptr;
	PixelShader *PS = nullptr;
	//상수버퍼 크기 회전 이동 관련 행렬
	WorldBuffer*WB=nullptr;
	Matrix world, S, R, T;
	Vector3 position;
	float rotation;
	float length;
	Color color;
	
	ColorBuffer* CB = nullptr;
};