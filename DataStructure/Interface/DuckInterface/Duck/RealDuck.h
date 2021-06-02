#pragma once
#include "Duck.h"

class REALDuck:public Duck
{
public:
	REALDuck();
	virtual ~REALDuck();

public:
	void Fly() override;
private:
	FlyWing FlyBehavior;
};