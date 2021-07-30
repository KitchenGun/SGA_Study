#include "stdafx.h"
#include "Scene10_TileMap.h"

Scene10::Scene10()
{
	
}

Scene10::~Scene10()
{
	SAFE_DELETE(tileMap);

}

void Scene10::Init()
{
	Camera::Get()->Move(Vector3(WinMaxWidth / 2, WinMaxHeight / 2, 0));
	tileMap = new TileMap(Vector3(0, 0, 0), Vector3(1, 1, 1), 0);
}

void Scene10::Update()
{
	tileMap->Update();
}

void Scene10::PreRender()
{
}

void Scene10::Render()
{
	tileMap->Render();
}

void Scene10::PostRender()
{
	tileMap->GUI();
}
