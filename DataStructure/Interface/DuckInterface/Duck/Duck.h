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
	void FlyNoWay() override
	{
	}
	void FlyWithWing() override
	{
	}
protected:
	std::string m_strDuckType;
};

