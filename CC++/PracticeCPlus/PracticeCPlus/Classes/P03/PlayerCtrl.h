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
	//입력 처리
	void InputKey(char a_chInput);
	//충돌 처리
	void CheckPos();
public:
	//체력 계산
	void Hit(int a_nDamage);
	//아이템 획득
	void TakeItem();
public://생성자
	Player(CMap a_cMap);
private:
	CMap m_oMap;
	CMap::Pos m_stPlayerPos = {0,0};
	int m_HP;
	bool isDie = false;
};