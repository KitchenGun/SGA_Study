#include "stdafx.h"
#include "BoxManager.h"

BoxManager::BoxManager()
{
	for (int i = 0; i < 10; ++i)
	{
		oEnemyList.push_back(AddEnemy());
	}

}

BoxManager::~BoxManager()
{
}

Square * BoxManager::AddEnemy()
{
	vecTempPos.x += 110;
	vecTempPos.y = WinMaxHeight;
	
	tempEnemy = new Square(vecTempPos, Vector3(100, 100, 1), 0, Blue);
	
	return tempEnemy;
}

void BoxManager::Remove(Square* Target)
{
	for (itEnemyList = oEnemyList.begin(); itEnemyList != oEnemyList.end(); ++itEnemyList)
	{
		if (*itEnemyList == Target)
		{
			itEnemyList = oEnemyList.erase(itEnemyList);
			if (oEnemyList.size() == 0)
			{
				MessageBox(handle, L"Win", L"Result", MB_OK);
			}
			break;
		}
	}
}
