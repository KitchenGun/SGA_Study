#pragma once
#include "Duck.h"

class REALDuck:public Duck
{
public:
	REALDuck();
	virtual ~REALDuck();

public:
	void Fly() override;
	void FlyWithWing() override
	{
		std::cout << "�۴� �۴�" << std::endl;
	}
public:
};