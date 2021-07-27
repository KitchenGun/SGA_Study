#include "stdafx.h"
#include "Scene9_Animation.h"

Scene9::Scene9()
{
	
}

Scene9::~Scene9()
{
	SAFE_DELETE(background);
	SAFE_DELETE(mapTex);

	SAFE_DELETE(animRect);

}

void Scene9::Init()
{
	background = new TextureRect(Vector3(0, 0, 0), Vector3(800*3, 800*3, 1), 0);
	mapTex = new Texture2D(L"./_Textures/AtahoMap.png");
	background->SetSRV(mapTex->GetSRV());
	animRect = new Ataho(Vector3(300, 300, 0), Vector3(100, 100, 1), 0);
}

void Scene9::Update()
{
	
	animRect->Update();
	//카메라 객체에 전달 변화값 전달
	Camera::Get()->Move(animRect->GetPosition() + Vector3(100, 100, 0));
}

void Scene9::PreRender()
{
}

void Scene9::Render()
{
	background->Render();
	animRect->Render();
}

void Scene9::PostRender()
{
	
}
