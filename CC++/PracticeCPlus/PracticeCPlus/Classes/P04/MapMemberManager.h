#pragma once
#include"P04.h"
#include"Member.h"

class CMapMemManager
{
public:
	//추가
	void InsertMember();
	//삭제
	void DeleteMember(CMember a_oMem);
	//검색
	void SearchMember(CMember a_oMem);
	//전체 출력
	void PrintAll();
	//메뉴 출력
	void PrintMenu();
public:
	CMapMemManager();
	~CMapMemManager();

private:
	std::map<int,CMember> oMemList;
};