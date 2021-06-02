#pragma once

#include "../stdafx.h"

enum class EFlyType
{
	NONE=0,
	FLYWING,
};

class IFlyable
{
public:
	IFlyable() {}
	virtual ~IFlyable() {}
public:
	virtual void FlyWithWing() {};
	virtual void FlyNoWay() {};
};	

class FlyBehavior:IFlyable
{
public:
	FlyBehavior(EFlyType a_eFlyType)
		:
		eFlyType(a_eFlyType)
	{

	}

public:
	void Fly() 
	{
		switch (eFlyType)
		{
		case EFlyType::NONE:
			FlyNoWay();
			break;
		case EFlyType::FLYWING:
			FlyWithWing();
			break;
		default:
			break;
		}
	}
	void SetFlyType(EFlyType a_eFlyType)
	{
		eFlyType = a_eFlyType;
	}
private:
	void FlyWithWing() override
	{
		std::cout << "ÆÛ´ö ÆÛ´ö"<<std::endl;
	}
	void FlyNoWay() override
	{
		std::cout << "do nothing" << std::endl;
	}
private:
	EFlyType eFlyType;
};



