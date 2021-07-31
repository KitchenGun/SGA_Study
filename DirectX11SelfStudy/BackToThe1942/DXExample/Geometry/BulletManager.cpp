#include "stdafx.h"
#include "BulletManager.h"

BulletManager::BulletManager()
{
}

BulletManager::~BulletManager()
{
	SAFE_DELETE(tempProjectile);
	for (Bullet* temp : oProjectileList)
	{
		SAFE_DELETE(temp);
	}
}

void BulletManager::AddProjectile(Vector3 FirePos, bool isPlayer)
{
	if (isPlayer)
	{
		tempProjectile = new Bullet(FirePos, Vector3(25, 50, 1), 0,true);
	}
	else
	{
		tempProjectile = new Bullet(FirePos, Vector3(25, 50, 1), 0);
	}
	oProjectileList.push_back(tempProjectile);
}

void BulletManager::RemoveProjectile(Bullet * Target)
{
	for (itProjectileList = oProjectileList.begin(); itProjectileList != oProjectileList.end(); ++itProjectileList)
	{
		if (*itProjectileList == Target)
		{
			itProjectileList = oProjectileList.erase(itProjectileList);
			break;
		}
	}
}
