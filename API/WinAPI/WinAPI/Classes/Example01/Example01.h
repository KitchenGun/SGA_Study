#pragma once
#include "../Global/Define/KGDefine.h"
#include "../Global/Utility/Base/CWndApp.h"


class Example01 :public CWndApp
{
public:
	Example01(HINSTANCE a_hInst,
		int a_nShowOpts,
		const SIZE &a_rstWndSize);
};