#include "RubberDuck.h"

RubberDuck::RubberDuck()
{
	m_strDuckType = "RubberDuck";
	m_oFlyBehavior->SetFlyType(EFlyType::NONE);
}

RubberDuck::~RubberDuck()
{
}

void RubberDuck::Fly()
{
	m_oFlyBehavior->Fly();
}
