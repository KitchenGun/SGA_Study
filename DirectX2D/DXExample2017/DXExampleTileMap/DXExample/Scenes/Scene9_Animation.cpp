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
	background = new TextureRect(Vector3(0, 0, 0), Vector3(5390, 2022, 1), 0);
	mapTex = new Texture2D(L"./_Textures/Map.png");
	background->SetSRV(mapTex->GetSRV());
	animRect = new Rockman(Vector3(300, 300, 0), Vector3(100, 100, 1), 0);
}

void Scene9::Update()
{
	if (KeyPress_Left)
		animRect->Move(Vector3(-100 * Time::Delta(), 0, 0));
	else if (KeyPress_Right)
		animRect->Move(Vector3(100 * Time::Delta(), 0, 0));

	if (KeyPress_Up)
		animRect->Move(Vector3(0, 100 * Time::Delta(), 0));
	else if (KeyPress_Down)
		animRect->Move(Vector3(0, -100 * Time::Delta(), 0));
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
