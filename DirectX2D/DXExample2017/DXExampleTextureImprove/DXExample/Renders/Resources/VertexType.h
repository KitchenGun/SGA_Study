#pragma once

struct VertexColor
{
	VertexColor() : position(0, 0, 0), color(0, 0, 0, 0) {}
	VertexColor(const Vector3 position, const Color &color)
		:
		position(position),
		color(color)
	{}
	
	Vector3 position;
	Color color;
	static D3D11_INPUT_ELEMENT_DESC descs[];
	static constexpr UINT count = 2;
};


struct VertexTexture
{
	VertexTexture() :position(0, 0, 0), uv(0, 0) {}

	Vector3 position;
	Vector2 uv;

	static D3D11_INPUT_ELEMENT_DESC descs[];
	//����
	//int a = 0;
	//const int b = a;
	//�Ұ���//������ ���������� ������ ���� ���� ������ �����ϸ� �������� 
	//int a;
	//const int b = a;
	static constexpr UINT count = 2;//const���� ���̴� ������ �ʱ�ȭ�� ���� ���� ���ͷ� ����� ����

};