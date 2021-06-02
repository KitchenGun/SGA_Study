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
		std::cout << "ÆÛ´ö ÆÛ´ö" << std::endl;
	}
public:
};