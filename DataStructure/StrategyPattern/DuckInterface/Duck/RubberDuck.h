#pragma once
#include "Duck.h"

class RubberDuck :public Duck
{
public:
	RubberDuck();
	virtual ~RubberDuck();

public:
	void Fly() override;
};