#include "stdafx.h"
#include "Scene5_Blur.h"

Scene5::Scene5()
{
}

Scene5::~Scene5()
{
	SAFE_DELETE(texture);
}

void Scene5::Init()
{

	Vector3 size = Vector3(WinMaxWidth, WinMaxHeight, 0);
	texture = new TextureRect(size / 2, size, 0);
	texture->SetSRV(L"./_Textures/Image0.bmp");
	texture->SetShader(L"./_Shaders/Blur.hlsl");

}



void Scene5::Update()
{
	if (Keyboard::Get()->Press('W'))
		texture->MoveLocalRect({ 0,-10,0,-10 });
	else if (Keyboard::Get()->Press('S'))
		texture->MoveLocalRect({ 0,10,0,10 });
	if (Keyboard::Get()->Press('A'))
		texture->MoveLocalRect({ -10,0,-10, 0 });
	else if (Keyboard::Get()->Press('D'))
		texture->MoveLocalRect({ 10,0,10,0 });
	texture->Update();
}

void Scene5::PreRender()
{
}

void Scene5::Render()
{
	texture->Render();
}
