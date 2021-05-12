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

class Example02 :public CWndApp
{
public:
	Example02(HINSTANCE a_hInst,
		int a_nShowOpts,
		const SIZE &a_rstWndSize);
};