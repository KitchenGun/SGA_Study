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
	//가능
	//int a = 0;
	//const int b = a;
	//불가능//컴파일 시점에서는 문제가 되지 않음 하지만 빌드하면 문제가됨 
	//int a;
	//const int b = a;
	static constexpr UINT count = 2;//const와의 차이는 변수로 초기화를 막음 오직 리터럴 상수만 받음

};