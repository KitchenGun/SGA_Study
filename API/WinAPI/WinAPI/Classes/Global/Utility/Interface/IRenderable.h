#pragma once

#include "../../Define/KGDefine.h"

class IRenderable
{// public �������̽�
public:
	//��ü�� �׸���
	virtual void Render(HDC a_hDC) = 0;
protected:
	//��ü�� �׸�����
	virtual void PreRender(HDC a_hDC) {}
	//��ü�� �׸���
	virtual void DoRender(HDC a_hDC) {}
	//��ü�� �׸���
	virtual void PostRender(HDC a_hDC) {}
};