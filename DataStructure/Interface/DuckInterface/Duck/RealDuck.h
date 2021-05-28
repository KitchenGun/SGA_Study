#pragma once
#include "Duck.h"

class REALDuck:public Duck
{
public:
	REALDuck();
	virtual ~REALDuck();

public:
	void Fly() override;

	virtual void FlyWithWing() override
	{
		std::cout << "�۴� �۴�";
	}
	virtual void FlyNoWay() override
	{
		std::cout << "do nothing";
	}
public:
};