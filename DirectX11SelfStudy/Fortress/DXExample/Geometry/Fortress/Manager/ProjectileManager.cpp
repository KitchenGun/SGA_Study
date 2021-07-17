#include "stdafx.h"
#include "ProjectileManager.h"

ProjectileManager::ProjectileManager()
{
}

ProjectileManager::~ProjectileManager()
{
	SAFE_DELETE(tempProjectile);
	for (Bomb* temp : oProjectileList)
	{
		SAFE_DELETE(temp);
	}
}

void ProjectileManager::AddProjectile(float fFirePower,LinePoint LP)
{
	tempProjectile = new Bomb(Vector3(LP.Second.x, LP.Second.y,0), Vector3(50,50,1), 100, Red);
	tempProjectile->SetMoveDir(Vector2(LP.Second.x - LP.First.x, LP.Second.y - LP.First.y));
	tempProjectile->Fire(fFirePower);
	oProjectileList.push_back(tempProjectile);
}

void ProjectileManager::RemoveProjectile(Bomb* Target)
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
