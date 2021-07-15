#include <iostream>
#include "Observer/Target.h"


int main()
{
	Target* a = new Target;

	int temp;
	while (true)
	{
		std::cin >> temp;
		a->SetInt(temp);
	}
}


