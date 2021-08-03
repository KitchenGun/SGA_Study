#pragma once
class SAMSpawner
{
public:
	SAMSpawner(Player* Target, BulletManager* EnemyBM);
	~SAMSpawner();
	
	void Update();
	void Render();

	//투사체 생성 함수
	void AddProjectile(Vector3 SpawnPos);
	//투사체 제거 함수
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