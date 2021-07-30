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
	ImTextureID texId;//imgui����� �ڷ�������//�ڷ��� ������� �ּҸ� ��Ƴ���
	Vector2 imageSize;//�ؽ��� 2d ���ؼ� �޾ƿ�
	//�׸����� X,Y ������ Ƚ��
	UINT tileXCount;
	UINT tileYCount;
	//�� Ÿ���� ũ��
	Vector2 texelTileSize;
	//Vector2 UISize;
	
	Vector2 selectedStartUv;
};