#pragma once
class BoxManager
{
public:
	BoxManager();
	~BoxManager();
	//�� ���� �Լ�
	Square* AddEnemy();
	void Remove(Square* Target);

public:
	list<Square*> GetEnemyList() { return oEnemyList; }
private:
	list<Square*> oEnemyList;
	list<Square*>::iterator itEnemyList;
	Vector3 vecTempPos = Vector3(0.0f,0.0f,0.0f);

	Square *tempEnemy;
};
