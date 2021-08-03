#include "stdafx.h"
#include "Scene_Intro.h"

Intro::Intro()
{
}

Intro::~Intro()
{
	SAFE_DELETE(background);
	SAFE_DELETE(mapTex);

	SAFE_DELETE(animRect);
	SAFE_DELETE(subAnimRect);
}

void Intro::Init()
{
	background = new TextureRect(Vector3(0, 0, 0), Vector3(224 * 3, 2144 * 3, 1), 0);
	mapTex = new Texture2D(L"./_Textures/Map.png");
	background->SetSRV(mapTex->GetSRV());
	animRect = new Player(Vector3(100, 100, 0), Vector3(100, 100, 1), 0);
	subAnimRect = new PlayerAfterBurner(Vector3(100, 100, 0), Vector3(100, 300, 1), 0);
}

void Intro::Update()
{
}

void Intro::PreRender()
{
}

void Intro::Render()
{
}

void Intro::PostRender()
{
}
