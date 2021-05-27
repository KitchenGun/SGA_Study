#pragma once

#include "../stdafx.h"

class IFlyable
{
public:
	virtual void FlyWithWing() = 0;
	virtual void FlyNoWay() = 0;
};

class FlyWing:IFlyable
{
public:
	virtual void FlyWithWing()
	{
		std::cout << "ÆÛ´ö ÆÛ´ö";
	}
public:
	void Fly()
	{
		FlyWithWing();
	}
};

class NoFly :IFlyable
{
public:
	virtual void FlyNoWay()
	{
		std::cout << "do nothing";
	}
public:
	void Fly()
	{
		FlyNoWay();
	}
};

