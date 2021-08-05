#pragma once
class GameManager;

class SAMSpawner
{
public:
	SAMSpawner(Player* Target, BulletManager* EnemyBM);
	~SAMSpawner();
	
	void Update();
	void Render();

	//투사체 생성 함수
	void AddSAM(Vector3 SpawnPos);
	//투사체 제거 함수
	void RemoveSAM(SAM* Target);
	void SetEnemyBM(BulletManager* val) { EnemyBM = val; }
	void SetTarget(Player* val) { Target = val; }
	void SetGM(GameManager* val) { GM = val; }
public:
	list<SAM*> GetSAMList() { return oSAMList; }
private:
	list<SAM*> oSAMList;
	list<SAM*>::iterator itSAMList;
	SAM* temp;
private:
	Player* Target = nullptr;
	BulletManager* EnemyBM = nullptr;

	GameManager* GM = nullptr;
};