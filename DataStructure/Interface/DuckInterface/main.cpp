#include "stdafx.h"
#include "Duck/Duck.h"
#include "Duck/RealDuck.h"
#include "Duck/RubberDuck.h"

int main()
{
	Duck *RealDuck =new REALDuck();
	Duck* ToyDuck = new RubberDuck();
	RealDuck->Display();
	RealDuck->Fly();

	ToyDuck->Display();
	ToyDuck->Fly();
}