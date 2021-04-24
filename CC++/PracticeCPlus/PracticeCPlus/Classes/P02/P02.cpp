#include "P02.h"
#include "Calculator.h"

namespace  P02Space
{
	void P02(const int argc, const char** args)
	{
		std::string sFomulaInput;
		printf("수식 입력 : ");
		std::cin >> sFomulaInput;
		CCalculator calculator(sFomulaInput);
		calculator.Transform();
		calculator.PrintResult();
	}
	
}
