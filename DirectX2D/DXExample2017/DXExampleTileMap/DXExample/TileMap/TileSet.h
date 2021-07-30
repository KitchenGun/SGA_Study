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
	ImTextureID texId;//imgui사용자 자료정의형//자료형 상관없이 주소만 담아놨음
	Vector2 imageSize;//텍스쳐 2d 통해서 받아옴
	//그림에서 X,Y 나누는 횟수
	UINT tileXCount;
	UINT tileYCount;
	//한 타일의 크기
	Vector2 texelTileSize;
	//Vector2 UISize;
	
	Vector2 selectedStartUv;
};