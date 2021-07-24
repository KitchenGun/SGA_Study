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
	static constexpr UINT count = 2;//const���� ���̴� ������ �ʱ�ȭ�� ���� ���� ���ͷ� ����� ����//������ ����

};

struct VertexTextureColor
{
	VertexTextureColor() : position(0, 0, 0), color(0, 0, 0, 1), uv(0, 0) {}

	VertexTextureColor(const Vector3& position, const Color& color, const Vector2& uv)
		:position(position),
		color(color),
		uv(uv)
	{}

	Vector3 position;
	Color color;
	Vector2 uv;

	static D3D11_INPUT_ELEMENT_DESC descs[];
	static constexpr UINT count = 3;
};

struct VertexTile
{
	VertexTile() : position(0, 0, 0), uv(0, 0),tileUv(0,0),isTiled(false) {}
	VertexTile(const Vector3& position, const Vector2& uv, const Vector2& tileUv,const bool& isTiled)
		:position(position),
		uv(uv),
		tileUv(tileUv),
		isTiled(isTiled)
	{}

	Vector3 position;
	Vector2 uv;
	Vector2 tileUv;
	bool isTiled;
	static D3D11_INPUT_ELEMENT_DESC descs[];
	static constexpr UINT count = 4;
};