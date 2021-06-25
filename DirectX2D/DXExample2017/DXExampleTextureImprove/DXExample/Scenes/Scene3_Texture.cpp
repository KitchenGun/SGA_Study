#include "stdafx.h"
#include "Scene3_Texture.h"

Scene3::Scene3()
{
}

Scene3::~Scene3()
{
	SAFE_DELETE(texture);
	SAFE_DELETE(circle);
}

void Scene3::Init()
{
	circle = new FilledCircle(Vector3(800, 600, 0), Vector3(100, 100, 1), 100, White);

	Vector3 size = Vector3(WinMaxWidth / 3, WinMaxHeight / 3, 0);
	texture = new TextureRect(size/2,size,0);
	texture->SetSRV(L"./_Textures/Image0.bmp");
	texture->SetShader(L"./_Shaders/VertexTexture.hlsl");

	RTT = new RenderTexture();
	RTT->Initialize();
}

void Scene3::Update()
{
	if (Keyboard::Get()->Down(VK_F12))
		RTT->SaveTexture(L"./ScreenShot.png");
	circle->Update();
	texture->Update();
}

void Scene3::PreRender()
{
	Graphics::Get()->SetViewport();
	RTT->RenderToTexture();
	{
		circle->Render();
		//texture->Render();
	}
	Graphics::Get()->SetBackBufferToRTV();
}

void Scene3::Render()
{
	circle->Render();
	texture->Render();
}
