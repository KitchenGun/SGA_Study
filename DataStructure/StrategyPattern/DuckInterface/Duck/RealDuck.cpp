#include "RealDuck.h"

REALDuck::REALDuck()
{
	m_strDuckType="RealDuck";
	m_oFlyBehavior->SetFlyType(EFlyType::FLYWING);
}

REALDuck::~REALDuck()
{
}

void REALDuck::Fly()
{
	m_oFlyBehavior->Fly();
}
