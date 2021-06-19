#include "stdafx.h"
#include "SpawnManager.h"

SpawnManager::SpawnManager()
{
	for (int i = 0; i < 10 ; ++i)
	{
		oEnemyList.push_back(AddRandomEnemy());
	}
}

SpawnManager::~SpawnManager()
{
}

Enemy* SpawnManager::AddRandomEnemy()
{
	random_device rd;
	//크기 
	uniform_int_distribution<int> RNGSize(10, 200);
	vecTempSize.x = (float)RNGSize(rd);
	vecTempSize.y = (float)RNGSize(rd);
	//위치
	uniform_int_distribution<int> RNGX(200, WinMaxWidth-200);
	uniform_int_distribution<int> RNGY(200, WinMaxHeight-200);
	vecTempPos.x = (float)RNGX(rd);
	vecTempPos.y = (float)RNGY(rd);

	tempEnemy = new Enemy(vecTempPos, vecTempSize, 0);

	return tempEnemy;
}

void SpawnManager::ReplaceEnemy(Enemy* Target)
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
