#pragma once
class EnemyManager
{
public:
	EnemyManager();
	~EnemyManager();
	//�� ���� �Լ�
	Enemy* AddRandomEnemy();

	void ReplaceEnemy(Enemy* Target);
public:
	list<Enemy*> GetEnemyList() { return oEnemyList; }
private:
	list<Enemy*> oEnemyList;
	list<Enemy*>::iterator itEnemyList;
	D3DXVECTOR3 vecTempPos, vecTempSize;

	Enemy* tempEnemy;
};