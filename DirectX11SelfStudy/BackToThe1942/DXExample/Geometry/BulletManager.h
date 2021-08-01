#pragma once
class BulletManager
{
public:
	BulletManager();
	~BulletManager();
	//����ü ���� �Լ�
	void AddProjectile(Vector3 FirePos, bool isPlayer = false);
	void AddMissileProjectile(Vector3 FirePos, float fAngle, bool isPlayer = false);
	//����ü ���� �Լ�
	void RemoveProjectile(Bullet* Target);
public:
	list<Bullet*> GetProjectileList() { return oProjectileList; }
private:
	list<Bullet*> oProjectileList;
	list<Bullet*>::iterator itProjectileList;
	D3DXVECTOR3 vecTempPos, vecTempSize;

	Bullet* tempProjectile;
};