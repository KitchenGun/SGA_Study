#pragma once
class TileSet;

struct Tile//Ÿ�� ��ĭ�� ���� ����ü
{
	Vector3 pos;
	Vector2 uvStart;
	Vector2 uvEnd;
	Color color;
};

class TileMap
{
public:
	TileMap(Vector3 position, Vector3 size, float rotation);
	~TileMap();

	void SetSRv(ID3D11ShaderResourceView* SRV) { this->srv = srv; }
	void SetShader(wstring shaderPath);

	void Update();
	void Render();

	Vector3 GetPosition() { return position; }

	void GUI();
private:
	void GenerateTileMap(UINT width, UINT height, UINT spacing);
	Tile* GetTile(Vector3 worldMousePos);
private:
	UINT width, height;
	UINT vertexCount;
	UINT indexCount;

	vector<VertexTextureColor> vertices;
	vector<UINT> indices;
	Tile** tiles;						//2���� �迭�̶� ���� ������
	UINT spacing;
	InputLayout* IL = nullptr;

	VertexBuffer* VB = nullptr;
	IndexBuffer* IB = nullptr;

	VertexShader* VS = nullptr;
	PixelShader* PS = nullptr;

	WorldBuffer* WB = nullptr;
	Matrix world;
	Vector3 position, size;
	float rotation;

	ID3D11ShaderResourceView* srv = nullptr;

	wstring shaderPath = L"";

	ID3D11RasterizerState* RS = nullptr;
	ID3D11RasterizerState* wireframeRS = nullptr;

	class TileSet* tileSet;

};