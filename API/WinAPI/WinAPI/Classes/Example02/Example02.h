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
//����ü ��� ���� ��� �� ��� 
class Example02 :public CWndApp
{
public:
	struct STLineInfo
	{
		POINT m_stStartPos;
		POINT m_stEndPos;
	};

public:
	//������ �޼��� ó��
	virtual LRESULT HandleWndMsg(
		HWND a_hWnd,
		UINT a_nMsg,
		WPARAM a_wParams,
		LPARAM a_lParams)override;
public:
	Example02(HINSTANCE a_hInst,
		int a_nShowOpts,
		const SIZE &a_rstWndSize);

protected:
	//��ü�� �׸���
	virtual void DoRender(HDC a_hDC) override;
private:
	//���콺 �̵� �޼����� ó���Ѵ�
	LRESULT HandleMouseMoveMsg(WPARAM a_wParams, LPARAM a_lParams);
	//���콺 ��ư �޼��� ó���Ѵ�
	LRESULT HandleMouseBtnMsg(WPARAM a_wParams, LPARAM a_lParams,bool a_bIsBtnDown);
	virtual LRESULT HandlePaintMsg(WPARAM a_wParams, LPARAM a_lParams)override;
private:
	
	//�迭 �߰�
	std::vector<STLineInfo> m_oLineInfoList;
};