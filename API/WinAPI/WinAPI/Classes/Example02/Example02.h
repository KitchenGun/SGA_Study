#pragma once
#include "../Global/Define/KGDefine.h"
#include "../Global/Utility/Base/CWndApp.h"

/*
디바이스 컨텍스트 (DC)란?
윈도우상에 특정 이미지 등을 출력하기 위해서는 해당 이미지를 그리기 위한 여러 정보들이 필요하며 
해당 정보들을 가지고 있는 특정 자원은 디바이스 컨텍스트라고 한다
즉 디바이스 컨텍스트 여러 정보를 설정 함으로써 다양한 이미지나 문자 등을 윈도우 상에 출력하는 것이 가능하다
윈도우 마다 고유 자원
*/
//구조체 방식 벡터 방식 맵 방식 
class Example02 :public CWndApp
{
public:
	//색상
	enum class EColor
	{
		NONE=-1,
		RED,
		GREEN,
		BLUE,
		MAX_VAL
	};

	struct STLineInfo
	{
		EColor m_eColor;
		POINT m_stStartPos;
		POINT m_stEndPos;
	};

public:
	//윈도우 메세지 처리
	virtual LRESULT HandleWndMsg(
		HWND a_hWnd,
		UINT a_nMsg,
		WPARAM a_wParams,
		LPARAM a_lParams)override;
public:
	Example02(HINSTANCE a_hInst,
		int a_nShowOpts,
		const SIZE &a_rstWndSize);
	virtual ~Example02(void);

protected:
	//초기화한다
	virtual void Init(void) override;
	//상태를 갱신하다
	virtual void Update(float a_fDeltaTime) override;
	//물체를 그린다
	virtual void DoRender(HDC a_hDC) override;
private:
	//마우스 이동 메세지를 처리한다
	LRESULT HandleMouseMoveMsg(WPARAM a_wParams, LPARAM a_lParams);
	//마우스 버튼 메세지 처리한다
	LRESULT HandleMouseBtnMsg(WPARAM a_wParams, LPARAM a_lParams,bool a_bIsBtnDown);
	virtual LRESULT HandlePaintMsg(WPARAM a_wParams, LPARAM a_lParams)override;
private:
	EColor m_eColor = EColor::RED;

	HPEN m_hRedPen = nullptr;
	HPEN m_hGreenPen = nullptr;
	HPEN m_hBluePen = nullptr;
	//배열 추가
	std::vector<STLineInfo> m_oLineInfoList;
	std::unordered_map<EColor, HPEN> m_oPenList;
};