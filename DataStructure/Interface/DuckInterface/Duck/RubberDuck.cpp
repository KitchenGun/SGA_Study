#include "RubberDuck.h"

RubberDuck::RubberDuck()
{
	m_strDuckType = "RubberDuck";
}

RubberDuck::~RubberDuck()
{
}

void RubberDuck::Fly()
{
	FlyBehavior.Fly();
}
