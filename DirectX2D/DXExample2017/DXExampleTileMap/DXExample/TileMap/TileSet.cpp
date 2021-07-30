#include "stdafx.h"
#include "TileSet.h"

TileSet::TileSet()//애니메이션과 유사한 방식으로 이미지를 자름
{
	tileSprite = new Texture2D(L"./_Textures/TileMap.jpg");
	texId = tileSprite->GetSRV();
	imageSize = Vector2((float)tileSprite->GetWidth(), (float)tileSprite->GetHeight());

	tileXCount = 10;
	tileYCount = 18;
	//uv처럼 정규화 시킴
	//UISize = Vector2(1 / (float)tileXCount, 1 / (float)tileYCount);
	texelTileSize = Vector2(1 / (float)tileXCount, 1 / (float)tileYCount);
}

TileSet::~TileSet()
{
	SAFE_DELETE(tileSprite);
}

void TileSet::GUI()
{
	static bool bOpen = true;
	//창띄우겠다
	ImGui::Begin("TileSprite", &bOpen);
	{
		int index = 0;
		//순서대로 돌린다
		for (UINT y = 0; y < tileYCount; y++)
		{
			for (UINT x = 0; x < tileXCount; x++)
			{
				//아이디 추가
				index++;
				ImGui::PushID(index);
				//ImGui::PushID(x + (y * tileXCount));
				//이미지 버튼											n*0.1,n*0.1
				if (ImGui::ImageButton(texId, ImVec2(40, 40), ImVec2(x * texelTileSize.x, y * texelTileSize.y), 
					ImVec2(texelTileSize.x + (x * texelTileSize.x), texelTileSize.y + (y * texelTileSize.y))))
				{
					//ui의 이미지를 눌렀을 경우에 작동함
					selectedStartUv = Vector2(x * texelTileSize.x, y * texelTileSize.y);
				}
				ImGui::PopID();
				if (index % 4 != 0) //한줄에 몇개를 넣을지 
					ImGui::SameLine();
			}
		}
	}
	ImGui::End();
}
