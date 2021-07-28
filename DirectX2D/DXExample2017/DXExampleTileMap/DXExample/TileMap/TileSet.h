#pragma once

class TileSet
{
public:
	friend class TileMap;

	TileSet();
	~TileSet();

	void GUI();

private:
	Texture2D* tileSprite;
	ImTextureID texId;//imgui����� �ڷ�������
	Vector2 imageSize;
	UINT tileXCount;
	UINT tileYCount;

	Vector2 texelTileSize;
	Vector2 UISize;
	Vector2 selectedStartUv;
};