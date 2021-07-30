#include "stdafx.h"
#include "TileSet.h"

TileSet::TileSet()//�ִϸ��̼ǰ� ������ ������� �̹����� �ڸ�
{
	tileSprite = new Texture2D(L"./_Textures/TileMap.jpg");
	texId = tileSprite->GetSRV();
	imageSize = Vector2((float)tileSprite->GetWidth(), (float)tileSprite->GetHeight());

	tileXCount = 10;
	tileYCount = 18;
	//uvó�� ����ȭ ��Ŵ
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
	//â���ڴ�
	ImGui::Begin("TileSprite", &bOpen);
	{
		int index = 0;
		//������� ������
		for (UINT y = 0; y < tileYCount; y++)
		{
			for (UINT x = 0; x < tileXCount; x++)
			{
				//���̵� �߰�
				index++;
				ImGui::PushID(index);
				//ImGui::PushID(x + (y * tileXCount));
				//�̹��� ��ư											n*0.1,n*0.1
				if (ImGui::ImageButton(texId, ImVec2(40, 40), ImVec2(x * texelTileSize.x, y * texelTileSize.y), 
					ImVec2(texelTileSize.x + (x * texelTileSize.x), texelTileSize.y + (y * texelTileSize.y))))
				{
					//ui�� �̹����� ������ ��쿡 �۵���
					selectedStartUv = Vector2(x * texelTileSize.x, y * texelTileSize.y);
				}
				ImGui::PopID();
				if (index % 4 != 0) //���ٿ� ��� ������ 
					ImGui::SameLine();
			}
		}
	}
	ImGui::End();
}
