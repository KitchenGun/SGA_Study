#pragma once
#include "../stdafx.h"


class Duck 
{
public:
	Duck();
public:
	virtual void Fly();
	void Display();
public:
protected:
	std::string m_strDuckType;
};

