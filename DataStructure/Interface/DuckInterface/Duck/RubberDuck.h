#pragma once
#include "Duck.h"

class RubberDuck :public Duck
{
public:
	RubberDuck();
	virtual ~RubberDuck();

public:
	void Fly() override;

	void FlyNoWay() override
	{
		std::cout << "고무오리는 날지 않는다"<<std::endl;
	}

public:
};