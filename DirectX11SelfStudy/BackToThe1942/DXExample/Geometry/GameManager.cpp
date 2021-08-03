#include "stdafx.h"
#include "GameManager.h"

GameManager::GameManager(Player* player, BulletManager* playerBulletManager, BulletManager* enemyBulletManager, SAMSpawner* samSpawnManager, MIGSpawner* migSpawnManager)
	:player(player),
	PBM(playerBulletManager),
	EBM(enemyBulletManager),
	SSM(samSpawnManager),
	MSM(migSpawnManager)
{
}

GameManager::~GameManager()
{
	SAFE_DELETE(player);
}

void GameManager::Update()
{
	/*
	1. 충돌 처리
	//플레이어:미사일
	//총알:적 투사체
	//총알:적 mig
	//적 총알:플레이어
	2. 미그기 스폰
	특정 y축일 경우에 스폰
	3. 플레이어의 이동 제한
	*/

	//플레이어와 적의 투사체 충돌 처리
	for (Bullet* tempBullet : EBM->GetProjectileList())
	{
		if (tempBullet != nullptr)
		{//객체가 존재할 경우
			if (Math::Intersect(player, tempBullet))
			{
				EBM->RemoveProjectile(tempBullet);
			}
		}
	}

	//플레이어의 투사체와 적의 투사체 충돌 처리
	for (Bullet* tempBullet : PBM->GetProjectileList())
	{
		if (tempBullet != nullptr)
		{
			for (Bullet* tempEBullet : EBM->GetProjectileList())
			{
				if (tempEBullet != nullptr)
				{//객체가 존재할 경우
					if (Math::Intersect(tempBullet, tempEBullet))
					{
						PBM->RemoveProjectile(tempBullet);
						EBM->RemoveProjectile(tempEBullet);
					}
				}
			}
		}
	}

	//플레이어의 투사체와 적의 sam 충돌 처리
	for (Bullet* tempBullet : PBM->GetProjectileList())
	{
		if (tempBullet != nullptr)
		{
			for (SAM* tempSAM : SSM->GetSAMList())
			{
				if (tempSAM != nullptr)
				{//객체가 존재할 경우
					if (Math::Intersect(tempBullet, tempSAM))
					{
						PBM->RemoveProjectile(tempBullet);
						SSM->RemoveSAM(tempSAM);
					}
				}
			}
		}
	}
	
	//플레이어와 적 전투기 충돌 처리
	for (Mig25* temp : MSM->GetMIGList())
	{
		if (temp != nullptr)
		{//객체가 존재할 경우
			if (Math::Intersect(player, temp))
			{
				MSM->RemoveMIG(temp);
			}
		}
	}

	//플레이어의 투사체와 적의 전투기 충돌 처리
	for (Bullet* tempBullet : PBM->GetProjectileList())
	{
		if (tempBullet != nullptr)
		{
			for (Mig25* temp : MSM->GetMIGList())
			{
				if (temp != nullptr)
				{//객체가 존재할 경우
					if (Math::Intersect(tempBullet, temp))
					{
						PBM->RemoveProjectile(tempBullet);
						MSM->RemoveMIG(temp);
					}
				}
			}
		}
	}

	//미그기 스폰
	if (player->GetPosition().y >= 0)
	{
		if (deltaTime > SpawnRate)
		{
			MSM->AddMIG(player->GetPosition());
			deltaTime = 0.0f;
		}
		else
			deltaTime += Time::Delta();
	}

}
