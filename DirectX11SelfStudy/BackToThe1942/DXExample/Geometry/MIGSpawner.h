#pragma once
class MIGSpawner
{
public:
	MIGSpawner(BulletManager* EnemyBM);
	~MIGSpawner();

	void Update();
	void Render();

	//투사체 생성 함수
	void AddMIG(Vector3 SpawnPos);
	//투사체 제거 함수
	void RemoveMIG(Mig25* Target);
	void SetEnemyBM(BulletManager* val) { EnemyBM = val; }
public:
	list<Mig25*> GetMIGList() { return oMIGList; }
private:
	list<Mig25*> oMIGList;
	list<Mig25*>::iterator itMIGList;
	Mig25* temp;
private:
	BulletManager* EnemyBM = nullptr;
};