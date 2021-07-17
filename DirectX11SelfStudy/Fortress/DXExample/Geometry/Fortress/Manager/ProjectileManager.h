#pragma once
class ProjectileManager
{
public:
	ProjectileManager();
	~ProjectileManager();
	//����ü ���� �Լ�
	void AddProjectile(float fFirePower, LinePoint LP);
	//����ü ���� �Լ�
	void RemoveProjectile(Bomb* Target);
public:
	list<Bomb*> GetProjectileList() { return oProjectileList; }
private:
	list<Bomb*> oProjectileList;
	list<Bomb*>::iterator itProjectileList;
	D3DXVECTOR3 vecTempPos, vecTempSize;

	Bomb* tempProjectile;
};