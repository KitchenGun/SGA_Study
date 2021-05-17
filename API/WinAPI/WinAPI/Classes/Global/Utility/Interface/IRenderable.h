#pragma once

#include "../../Define/KGDefine.h"

class IRenderable
{// public 인터페이스
public:
	//물체를 그린다
	virtual void Render(HDC a_hDC) = 0;
protected:
	//물체를 그리기전
	virtual void PreRender(HDC a_hDC) {}
	//물체를 그린다
	virtual void DoRender(HDC a_hDC) {}
	//물체를 그린후
	virtual void PostRender(HDC a_hDC) {}
};