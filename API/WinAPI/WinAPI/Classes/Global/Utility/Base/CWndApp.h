#pragma once

#include "../../Define/KGDefine.h"
#include "../Interface/IUpdatable.h"
#include "../Interface/IRenderable.h"

//������ ���ø����̼�

class CWndApp :public IUpdatable,public IRenderable
{
public://IUpdatable
	//���¸� �����Ѵ�
	virtual void Update(float a_fDeltaTime) override;
public://IRenderable
	//��ü�� �׸���
	virtual void Render(HDC a_hDC) final override;

public:
	//������ ũ�⸦ ��ȯ�Ѵ�
	SIZE GetWndSize(void) const;
	//������ �ڵ��� ��ȯ�Ѵ�
	HWND GetWndHandle(void) const;
	//�ν��Ͻ� �ڵ��� ��ȯ�Ѵ�
	HINSTANCE GetInstHandle(void) const;
	//���ø����̼��� ������Ų��
	static CWndApp *GetInst(void);
	//������ �޼����� ó���Ѵ�
	virtual LRESULT HandleWndMsg(
		HWND a_hWnd, 
		UINT a_nMsg, 
		WPARAM a_wParams, 
		LPARAM a_lParams);
	//���ø����̼� ����
	int Run(void);

protected:
	//�ʱ�ȭ
	virtual void Init(void);
	//�޼��� ������ ������Ų��
	int RunMsgLoop(void);
	//ũ�� �޼����� ó���Ѵ�
	virtual LRESULT HandleSizeMsg(WPARAM a_wParams, LPARAM a_lParams);
	//�׸��� �޼����� ó���Ѵ�
	virtual LRESULT HandlePaintMsg(WPARAM a_wParams, LPARAM a_lParams);
	//���� �޼����� ó���Ѵ�
	virtual LRESULT HandleDestroyMsg(WPARAM a_wParams, LPARAM a_lParams);
	//������ ����
	virtual HWND CreateWnd(WNDCLASS *a_pstOutWndClass);

protected:
	//������
	CWndApp(HINSTANCE a_hInst,
		int a_nShowOpts,
		const SIZE &a_rstWndSize);
	//�Ҹ���
	virtual ~CWndApp(void);

private:
	//����
	int m_nShowOpts = 0;
	SIZE m_stWndSize;
	WNDCLASS m_stWndCls;

	FILE *m_pstRStream = nullptr;
	FILE *m_pstWStream = nullptr;

	HWND m_hWnd = nullptr;
	HBITMAP m_hBitmap = nullptr;
	HINSTANCE m_hInst = nullptr;
};