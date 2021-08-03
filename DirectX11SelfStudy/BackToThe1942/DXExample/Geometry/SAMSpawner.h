#pragma once
class SAMSpawner
{
public:
	SAMSpawner(Player* Target, BulletManager* EnemyBM);
	~SAMSpawner();
	
	void Update();
	void Render();

	//����ü ���� �Լ�
	void AddProjectile(Vector3 SpawnPos);
	//����ü ���� �Լ�
	void RemoveProjectile(SAM* Target);
	void SetEnemyBM(BulletManager* val) { EnemyBM = val; }
	void SetTarget(Player* val) { Target = val; }
public:
	list<SAM*> GetProjectileList() { return oSAMList; }
private:
	list<SAM*> oSAMList;
	list<SAM*>::iterator itSAMList;
	D3DXVECTOR3 vecTempPos, vecTempSize;
	SAM* temp;
private:
	Player* Target = nullptr;
	BulletManager* EnemyBM = nullptr;
};