#pragma once
#include "../Global/Define/KGDefine.h"
#include "../Global/Utility/Base/CWndApp.h"

/*
����̽� ���ؽ�Ʈ (DC)��?
������� Ư�� �̹��� ���� ����ϱ� ���ؼ��� �ش� �̹����� �׸��� ���� ���� �������� �ʿ��ϸ� 
�ش� �������� ������ �ִ� Ư�� �ڿ��� ����̽� ���ؽ�Ʈ��� �Ѵ�
�� ����̽� ���ؽ�Ʈ ���� ������ ���� �����ν� �پ��� �̹����� ���� ���� ������ �� ����ϴ� ���� �����ϴ�
������ ���� ���� �ڿ�
*/

class Example02 :public CWndApp
{
public:
	Example02(HINSTANCE a_hInst,
		int a_nShowOpts,
		const SIZE &a_rstWndSize);
};