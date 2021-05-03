#pragma once

#include "../Global/Define/KGDefine.h"


class CMap
{
public: //좌표
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
	//맵 출력
	void PrintMap();
	//초기화  장애물 생성 -> 아이템 생성 -> 플레이어 위치 생성
	void Reset();
	//장애물 생성
	void CreateBlock();
	//아이템 생성
	void CreateItem();
	//플레이어 생성
	void CreatePlayer();
public://랜덤 함수

	//랜덤 좌표 생성
	Pos RandomPos(Pos& Position);

	//랜덤 범위 숫자 반환
	int RandomNum(int a_nRange);

public: //좌표 비교

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