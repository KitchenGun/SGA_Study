#include "stdafx.h"
#include "Scene_Stage.h"

Stage::Stage()
{
}

Stage::~Stage()
{
	SAFE_DELETE(background);
	SAFE_DELETE(mapTex);

	SAFE_DELETE(animRect);
}

void Stage::Init()
{
	background = new TextureRect(Vector3(0, 0, 0), Vector3(224*3, 2144, 1), 0);
	mapTex = new Texture2D(L"./_Textures/Map.png");
	background->SetSRV(mapTex->GetSRV());
	//animRect = new Ataho(Vector3(300, 300, 0), Vector3(100, 100, 1), 0);
}

void Stage::Update()
{
}

void Stage::PreRender()
{
}

void Stage::Render()
{
	background->Render();
}

void Stage::PostRender()
{
}
