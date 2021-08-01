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
	test1 = new SAM(Vector3(100, 100, 0), Vector3(100, 100, 1), 0);

	EnemyBM = new BulletManager();
	PlayerBM = new BulletManager();
	animRect->SetPlayerAfterBurner(subAnimRect);
	animRect->SetPlayerBM(PlayerBM);
	test1->SetTarget(animRect);
}

void Stage::Update()
{
	animRect->Update();
	subAnimRect->Move(animRect->GetPosition()+Vector3(0,-100,0));
	subAnimRect->Update();
	test1->Update();
	BulletUpdate(PlayerBM);
	BulletUpdate(EnemyBM);
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
	test1->Render();
	BulletRender(PlayerBM);
	BulletRender(EnemyBM);
}

void Stage::PostRender()
{
}

void Stage::BulletUpdate(BulletManager* BM)
{
	for (Bullet* Target : BM->GetProjectileList())
	{
		if (Target != nullptr)
		{
			Target->Update();
			if (300<Target->GetPosition().y-animRect->GetPosition().y)
			{
				BM->RemoveProjectile(Target);
			}
		}
	}
}

void Stage::BulletRender(BulletManager* BM)
{
	for (Bullet* Target : BM->GetProjectileList())
	{
		if (Target != nullptr)
		{
			Target->Render();
		}
	}
}
