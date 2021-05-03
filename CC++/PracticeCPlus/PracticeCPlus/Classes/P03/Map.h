#pragma once

#include "../Global/Define/KGDefine.h"


class CMap
{
public: //��ǥ
	struct Pos
	{
		int X;
		int Y;
	};
public://get//set
	Pos GetPlayerPos();
	void SetPlayerPos(Pos a_stPos);
	void SetNullPos();
	Pos GetBlockPos();
	Pos GetItemPos();
	char GetPos(Pos a_stPos);
public:
	//�� ���
	void PrintMap();
	//�ʱ�ȭ  ��ֹ� ���� -> ������ ���� -> �÷��̾� ��ġ ����
	void Reset();
	//��ֹ� ����
	void CreateBlock();
	//������ ����
	void CreateItem();
	//�÷��̾� ����
	void CreatePlayer();
public://���� �Լ�

	//���� ��ǥ ����
	Pos RandomPos(Pos& Position);

	//���� ���� ���� ��ȯ
	int RandomNum(int a_nRange);

public: //��ǥ ��

	static bool PosCheck(Pos a_stPosA,Pos a_stPosB)
	{
		if (a_stPosA.X == a_stPosB.X)
			if (a_stPosA.Y == a_stPosB.Y)
				return true;
		return false;
	}
	
private:
	//0~21 
	std::string m_sMap[5] = {
		"######################",
		"#                    #",
		"#                    #",
		"#                    #",
		"######################"
	};

	Pos Block = { 0,0 };
	Pos Item = { 0,0 };
	Pos Player = { 0,0 };
};