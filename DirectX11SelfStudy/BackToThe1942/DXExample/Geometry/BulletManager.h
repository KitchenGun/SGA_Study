#pragma once
class BulletManager
{
public:
	BulletManager();
	~BulletManager();
	//투사체 생성 함수
	void AddProjectile(Vector3 FirePos);
	//투사체 제거 함수
	void RemoveProjectile(Bullet* Target);
public:
	list<Bullet*> GetProjectileList() { return oProjectileList; }
private:
	list<Bullet*> oProjectileList;
	list<Bullet*>::iterator itProjectileList;
	D3DXVECTOR3 vecTempPos, vecTempSize;

	Bullet* tempProjectile;
};