#pragma once
#include"P04.h"
#include"Member.h"

class CVecMemManager
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
	CVecMemManager();
	~CVecMemManager();

private:
	std::vector<CMember> oMemList;
};



