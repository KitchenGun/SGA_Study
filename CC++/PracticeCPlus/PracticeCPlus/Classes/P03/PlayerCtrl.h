#pragma once
#include "../Global/Define/KGDefine.h"
#include "Map.h"

class Player
{
public://get//set
	bool GetIsDie();
	void SetPlayerPos(CMap::Pos a_stPos);
	int GetHP();
public:
	//�Է� ó��
	void InputKey(char a_chInput);
	//�浹 ó��
	void CheckPos();
public:
	//ü�� ���
	void Hit(int a_nDamage);
	//������ ȹ��
	void TakeItem();
public://������
	Player(CMap a_cMap);
private:
	CMap m_oMap;
	CMap::Pos m_stPlayerPos = {0,0};
	int m_HP;
	bool isDie = false;
};