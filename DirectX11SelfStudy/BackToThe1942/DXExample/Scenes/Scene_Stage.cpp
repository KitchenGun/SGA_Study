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
	PlayerBM = new BulletManager();
	animRect->SetPlayerAfterBurner(subAnimRect);
	animRect->SetPlayerBM(PlayerBM);
}

void Stage::Update()
{
	animRect->Update();
	subAnimRect->Move(animRect->GetPosition()+Vector3(0,-100,0));
	subAnimRect->Update();
	BulletUpdate();
	//Camera::Get()->Move(animRect->GetPosition() + Vector3(0, 200, 0));
}

void Stage::PreRender()
{
}

void Stage::Render()
{
	background->Render();
	animRect->Render();
	subAnimRect->Render();
	BulletRender();
}

void Stage::PostRender()
{
}

void Stage::BulletUpdate()
{
	for (Bullet* Target : PlayerBM->GetProjectileList())
	{
		if (Target != nullptr)
		{
			Target->Update();
			if (300<Target->GetPosition().y-animRect->GetPosition().y)
			{
				PlayerBM->RemoveProjectile(Target);
			}
		}
	}
}

void Stage::BulletRender()
{
	for (Bullet* Target : PlayerBM->GetProjectileList())
	{
		if (Target != nullptr)
		{
			Target->Render();
		}
	}
}
