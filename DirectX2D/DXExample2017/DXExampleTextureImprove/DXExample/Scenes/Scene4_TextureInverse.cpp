#include "stdafx.h"
#include "Scene4_TextureInverse.h"

Scene4::Scene4()
{

}

Scene4::~Scene4()
{
	SAFE_DELETE(textureRect)
	SAFE_DELETE(RTT);
	SAFE_DELETE(square2);
	SAFE_DELETE(square);
}

void Scene4::Init()
{
	square = new Square({ 200,200,0 }, { 100,100,1 }, 0,Red);
	square2 = new Square({ 400,400,0 }, { 100,100,1 }, 0, Red);
	RTT = new RenderTexture();
	//rtv와 srv 생성
	RTT->Initialize();
	textureRect = new TextureRect({ WinMaxWidth*0.5f,WinMaxHeight*0.5f,0 }, { WinMaxWidth,WinMaxHeight,1 }, 0);
	textureRect->SetShader(L"./_Shaders/VertexTexture.hlsl");
}

void Scene4::Update()
{
	//입력
	if (Keyboard::Get()->Press('W'))
		square->Move({ 0,10,0 });
	else if (Keyboard::Get()->Press('S'))
		square->Move({ 0,-10,0 });
	if (Keyboard::Get()->Press('A'))
		square->Move({ -10,0,0 });
	else if (Keyboard::Get()->Press('D'))
		square->Move({ 10,0,0 });


	if (Math::Intersect(square, square2))
	{
		//square->SetIntersect(true);
		square2->SetIntersect(true);
		square2->SetColor(Cyan);
	}
	else
	{
		//square->SetIntersect(false);
		square2->SetIntersect(false);
		square2->SetColor(Red);
	}

	square->Update();
	square2->Update();
}

void Scene4::PreRender()
{
	Graphics::Get()->SetViewport();
	RTT->RenderToTexture();
	{
		square->Render();
		square2->Render();
	}
	Graphics::Get()->SetBackBufferToRTV();
}

void Scene4::Render()
{
	textureRect->SetSRV(RTT->GetSRV());
	textureRect->Render();
}
