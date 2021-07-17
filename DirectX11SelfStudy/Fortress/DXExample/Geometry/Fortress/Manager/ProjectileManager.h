#pragma once
class ProjectileManager
{
public:
	ProjectileManager();
	~ProjectileManager();
	//투사체 생성 함수
	void AddProjectile(float fFirePower, LinePoint LP);
	//투사체 제거 함수
	void RemoveProjectile(Bomb* Target);
public:
	list<Bomb*> GetProjectileList() { return oProjectileList; }
private:
	list<Bomb*> oProjectileList;
	list<Bomb*>::iterator itProjectileList;
	D3DXVECTOR3 vecTempPos, vecTempSize;

	Bomb* tempProjectile;
};