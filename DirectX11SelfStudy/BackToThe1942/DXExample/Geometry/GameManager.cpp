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
	1. �浹 ó��
	//�÷��̾�:�̻���
	//�Ѿ�:�� ����ü
	//�Ѿ�:�� mig
	//�� �Ѿ�:�÷��̾�
	*/

	//�÷��̾�� ���� ����ü �浹 ó��
	for (Bullet* tempBullet : EBM->GetProjectileList())
	{
		if (tempBullet != nullptr)
		{//��ü�� ������ ���
			if (Math::Intersect(player, tempBullet))
			{
				EBM->RemoveProjectile(tempBullet);
			}
		}
	}
	//�÷��̾��� ����ü�� ���� ����ü �浹 ó��
	for (Bullet* tempBullet : PBM->GetProjectileList())
	{
		if (tempBullet != nullptr)
		{
			for (Bullet* tempEBullet : EBM->GetProjectileList())
			{
				if (tempEBullet != nullptr)
				{//��ü�� ������ ���
					if (Math::Intersect(tempBullet, tempEBullet))
					{
						PBM->RemoveProjectile(tempBullet);
						EBM->RemoveProjectile(tempEBullet);
					}
				}
			}
		}
	}

	//�÷��̾��� ����ü�� ���� sam �浹 ó��
	for (Bullet* tempBullet : PBM->GetProjectileList())
	{
		if (tempBullet != nullptr)
		{
			for (SAM* tempSAM : SSM->GetSAMList())
			{
				if (tempSAM != nullptr)
				{//��ü�� ������ ���
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
