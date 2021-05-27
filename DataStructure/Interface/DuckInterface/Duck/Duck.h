#pragma once

#include "../stdafx.h"


class Duck :public IFlyable
{
public:
	Duck();
public:
	void Fly();
	void Display();
protected:
	IFlyable* flyBehavior;
	std::string m_strDuckType;
};

