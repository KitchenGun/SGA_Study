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
	SAFE_DELETE(subAnimRect);
}

void Stage::Init()
{
	background = new TextureRect(Vector3(0, 0, 0), Vector3(224*3, 2144, 1), 0);
	mapTex = new Texture2D(L"./_Textures/Map.png");
	background->SetSRV(mapTex->GetSRV());
	animRect = new Player(Vector3(100, 100, 0), Vector3(100, 100, 1), 0);
	subAnimRect = new PlayerAfterBurner(Vector3(100, 100, 0), Vector3(100, 300, 1), 0);
	animRect->SetPlayerAfterBurner(subAnimRect);
}

void Stage::Update()
{
	animRect->Update();
	subAnimRect->Move(animRect->GetPosition()+Vector3(0,-100,0));
	subAnimRect->Update();
	Camera::Get()->Move(animRect->GetPosition() + Vector3(0, 200, 0));
}

void Stage::PreRender()
{
}

void Stage::Render()
{
	background->Render();
	animRect->Render();
	subAnimRect->Render();
}

void Stage::PostRender()
{
}
