#pragma once
#include"P04.h"
#include"Member.h"

class CMapMemManager
{
public:
	//�߰�
	void InsertMember();
	//����
	void DeleteMember(CMember a_oMem);
	//�˻�
	void SearchMember(CMember a_oMem);
	//��ü ���
	void PrintAll();
	//�޴� ���
	void PrintMenu();
public:
	CMapMemManager();
	~CMapMemManager();

private:
	std::map<int,CMember> oMemList;
};