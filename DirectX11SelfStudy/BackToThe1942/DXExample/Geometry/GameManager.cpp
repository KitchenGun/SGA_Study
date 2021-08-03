#include "stdafx.h"
#include "GameManager.h"

GameManager::GameManager(Player* player, BulletManager* playerBulletManager, BulletManager* enemyBulletManager, SAMSpawner* samSpawnManager)
	:player(player),
	PBM(playerBulletManager),
	EBM(enemyBulletManager),
	SSM(samSpawnManager)
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

}
