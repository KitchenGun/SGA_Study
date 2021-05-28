#pragma once
#include "../stdafx.h"


class Duck :public IFlyable
{
public:
	Duck();
public:
	virtual void Fly();
	void Display();
public:
	

protected:
	IFlyable* m_oflyBehavior;
	std::string m_strDuckType;
};

