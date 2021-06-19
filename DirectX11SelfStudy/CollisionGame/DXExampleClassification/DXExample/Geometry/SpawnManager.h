#pragma once
class SpawnManager
{
public:
	SpawnManager();
	~SpawnManager();
	//적 생성 함수
	Enemy* AddRandomEnemy();

	void ReplaceEnemy(Enemy* Target);
public:
	list<Enemy*> GetEnemyList() { return oEnemyList; }
private:
	list<Enemy*> oEnemyList;
	list<Enemy*>::iterator itEnemyList;
	D3DXVECTOR3 vecTempPos, vecTempSize;

	Enemy *tempEnemy;
};

