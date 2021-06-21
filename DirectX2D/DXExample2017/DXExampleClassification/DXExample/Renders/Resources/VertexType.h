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
