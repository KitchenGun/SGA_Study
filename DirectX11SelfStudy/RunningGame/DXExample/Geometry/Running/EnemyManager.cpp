#include "stdafx.h"
#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
	for (int i = 0; i < 3; ++i)
	{
		oEnemyList.push_back(AddRandomEnemy());
	}
}

EnemyManager::~EnemyManager()
{
}

Enemy* EnemyManager::AddRandomEnemy()
{
	random_device rd;
	//크기 
	uniform_int_distribution<int> RNGSize(10, 200);
	vecTempSize.x = (float)RNGSize(rd);
	vecTempSize.y = (float)RNGSize(rd);
	//위치
	uniform_int_distribution<int> RNGX(WinMaxWidth + 400, WinMaxWidth * 3);
	vecTempPos.x = (float)RNGX(rd);
	vecTempPos.y = (float)vecTempSize.y / 2;

	tempEnemy = new Enemy(vecTempPos, vecTempSize, 0);

	return tempEnemy;
}

void EnemyManager::ReplaceEnemy(Enemy* Target)
{
	for (itEnemyList = oEnemyList.begin(); itEnemyList != oEnemyList.end(); ++itEnemyList)
	{
		if (*itEnemyList == Target)
		{
			itEnemyList = oEnemyList.erase(itEnemyList);
			oEnemyList.push_back(AddRandomEnemy());
			break;
		}
	}
}
