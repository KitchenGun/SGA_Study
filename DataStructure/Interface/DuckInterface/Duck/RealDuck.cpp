#include "RealDuck.h"

REALDuck::REALDuck()
{
	FlyWing o_flyable;
	m_strDuckType="RealDuck";
}

REALDuck::~REALDuck()
{
}

void REALDuck::Fly()
{
	FlyWithWing();
}
