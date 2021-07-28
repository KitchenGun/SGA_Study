#include "stdafx.h"
#include "Scene10_TileMap.h"

Scene10::Scene10()
{
	
}

Scene10::~Scene10()
{
	SAFE_DELETE(background);
	SAFE_DELETE(mapTex);

	SAFE_DELETE(animRect);

}

void Scene10::Init()
{
	background = new TextureRect(Vector3(0, 0, 0), Vector3(800*3, 800*3, 1), 0);
	mapTex = new Texture2D(L"./_Textures/AtahoMap.png");
	background->SetSRV(mapTex->GetSRV());
	animRect = new Ataho(Vector3(300, 300, 0), Vector3(100, 100, 1), 0);
}

void Scene10::Update()
{
	
	animRect->Update();
	//카메라 객체에 전달 변화값 전달
	Camera::Get()->Move(animRect->GetPosition() + Vector3(100, 100, 0));
}

void Scene10::PreRender()
{
}

void Scene10::Render()
{
	background->Render();
	animRect->Render();
}

void Scene10::PostRender()
{
	
}
