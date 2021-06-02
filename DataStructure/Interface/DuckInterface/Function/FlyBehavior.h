#pragma once

#include "../stdafx.h"

class IFlyable
{
public:
	IFlyable() {}
	virtual ~IFlyable() {}
public:
	virtual void FlyWithWing() {};
	virtual void FlyNoWay() {};
};	

class FlyWing:IFlyable
{
public:
	void Fly() 
	{
		FlyWithWing();
	}
private:
	virtual void FlyWithWing() override
	{
		std::cout << "ÆÛ´ö ÆÛ´ö"<<std::endl;
	}
	virtual void FlyNoWay() override
	{
	}
};

class NoFly :IFlyable
{
public:
	void Fly()
	{
		FlyNoWay();
	}
private:
	void FlyNoWay() override
	{
		std::cout << "do nothing"<<std::endl;
	}
	void FlyWithWing() override
	{
	}
};

