#pragma once
#include "../Global/Define/KGDefine.h"
/*
Ŭ������?
��ü�� �����ϱ� ���� Ʋ�� �ǹ��ϸ� ���α׷��� �������� Ŭ������ ������ �Լ��� �׷�ȭ ���ѳ��� ���̴�.
�� ����ü�� �Ϲ����� ����ü�� ���� ���� �׷�ȭ ��ų���ִ� �Ͱ� �޸� Ŭ������ �Լ� ���� �׷�ȭ ��Ű�� ���� �����ϴ�.

ex
class CPlayer
{
	int m_nHP;
	int m_nATK;

	//���� 
	void Attack(CPlayer *a_pOtherPlayer);
};

CPlayer oPlayerA;
CPlayer oPlayerB;

oPlayerA.Attack(&oPlayerB);
*/
namespace E03Space
{
	void E03(const int argc, const char **args);
}