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
		std::cout << "�������� ���� �ʴ´�"<<std::endl;
	}

public:
};