#pragma once
class TileSet;

struct Tile//Ÿ�� ����ü
{
	Vector3 pos;
	Vector2 uvStart;
	Vector2 uvEnd;
	Color color;
};

class TileMap
{
public:
	friend class TileSet;//Ÿ�� �¿��� ��ǥ�� �������� ���ؼ�
public:
	TileMap(Vector2 position, Vector3 size, float rotation);
	~TileMap();

private:
	UINT width, height;
	UINT vertexCount;
	UINT indexCount;

	vector<VertexTextureColor> vertices;
	vector<UINT> indices;
	Tile** tiles;						//???�� ���������� ���� ���� �𸣰���
	UINT spacing;
	InputLayout* IL = nullptr;
};