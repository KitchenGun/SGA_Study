#include "E02.h"

//#define E02_FUNC_OVERLOADING 1
//#define E02_REFERENCE 2
#define E02_INLINE_FUNC	3

namespace E02Space
{
#if E02_FUNC_OVERLOADING
	/*
	extern "C"를 특정 영역에 명시하면 해당 영역은 c++의 규칙이 아닌   c의 규칙에 따라 컴파일을 수행하는 것이 가능하다
	즉 해당 영역에서는 네임 맹글링이 적용되지 않기 때문에 함수 오버로딩 불가능

	네임 맹글링이란
	C++컴파일러는 특정 함수등을 컴파일 할때 해당 함수등의 이름을 변경하는 단계를 수행하며 해당 단계를 네임 맹글링이라고 한다
	즉 동일한 이름 함수라도 네임 맹글링 규칙에 따라 서로 다른 함수의 이름이 만들어지기 때문에 오버로딩이 가능하다
	*/
	extern "C"
	{

	}
	int GetSumValue(int a_nLhs, int a_nRhs)
	{
		return a_nLhs + a_nRhs;
	}
	int GetSumValue(int a_nLhs, int a_nMhs, int a_nRhs)
	{
		return a_nLhs + a_nMhs + a_nRhs;
	}

#elif E02_REFERENCE
	/*
	레퍼런스를 사용하면 포인터와 마찬가지로 다른 지역에 존재하는 변수에 접근 및 제어하는 것이 가능하다.
	배열은 포인터를 사용하여 넘기는 것이 편하다. 불가능 한것은 아님
	*/
	void SwapByRef(int &a_nLhs, int &a_nRhs)
	{
		int nTemp = a_nLhs;
		a_nLhs = a_nRhs;
		a_nRhs = nTemp;
	}
#elif E02_INLINE_FUNC
	/*
	인라인 함수는 강제적인 것이 아니라 컴파일러에게 요청하는 것이기 때문에 컴파일러에 의해서 
	해당 함수가 많은 명령을 수행하고 있다면 이 요청이 거부당할수있다.
	*/
	//배열의 합계 및 평균반환
	inline void GetSumAndAverage(int *a_pnValues, int a_nSize, int &a_rnOutSum, float &a_rfOutAverage)
	{
		int nSumValue = 0;
		for (int i = 0; i < a_nSize; ++i)
		{
			nSumValue += a_pnValues[i];
		}
		a_rnOutSum = nSumValue;
		a_rfOutAverage = nSumValue / (float)a_nSize;
	}
	

#endif // E02_FUNC_OVERLOADING


	void E02(const int argc, const char ** args)
	{
	#if E02_FUNC_OVERLOADING
		int nLhs = 10;
		int nMhs = 20;
		int nRhs = 30;

		printf("%d+%d=%d\n", nLhs, nRhs, GetSumValue(nLhs, nRhs));
		printf("%d+%d+%d=%d\n", nLhs, nMhs, nRhs, GetSumValue(nLhs, nMhs, nRhs));
	#elif E02_REFERENCE
		int nValue = 0;
		int &rnValue = nValue;//선언과 동시에 변수를 줘야함 이후에 
		
		
		//쓰면 안되는 코드 
		int &&rnRValue = 0;
		rnRValue = 10;
		/*
		레퍼런스가 특정 변수에 별칭을 부여할수있는 시점은 해당 래퍼런스가 선언되는 순간이기 때문이다 
		따라서 이미 선언이 완료된 레퍼런스에 다른 변수를 할당할 경우 이는 새로운 별칭을 부여하는 것이 아니라
		해당변수의 값을 레퍼런스에 할당하는 것이다.
		*/
		rnValue = 10;
		rnValue = nValue;//주소값을 전달하는 것이 아닌 레퍼런스 변수에 값을 넣는 것이다.
		std::cout << "결과" << std::endl;
		printf("value %d %p \n", nValue, &nValue);
		printf("Ref value %d %p \n", rnValue, &rnValue);

		int nLhs = 10;
		int nRhs = 20;

		printf("\n 값 교환전\n");
		printf("%d ,%d\n", nLhs, nRhs);

		SwapByRef(nLhs, nRhs);

		printf("\n 값 교환후\n");
		printf("%d ,%d\n", nLhs, nRhs);

	#elif E02_INLINE_FUNC
		E02Space::GetSumValue(10, 20);
		/*
		random device를 사용하면 난수를 생성하는 것이 가능하며 
		uniform_int_distribution를 사용하면 정수형 난수를 생성하는 것이 가능하다
		만약 실수형 난수를 생성하고 싶으면 uniform_real_distribution을 사용하면 된다
		*/
		std::random_device oRandom;
		std::uniform_int_distribution<int> oUniform(0, 100);
		std::uniform_real_distribution<float> oUniformReal(0.0f, 10.0f);
		int anValues[10] = { 0 };
		float afValues[10] = { 0.0f };

		const int nSize = sizeof(anValues) / sizeof(anValues[0]);

		for (int i = 0; i < nSize; ++i)
		{
			anValues[i] = oUniform(oRandom);
			afValues[i] = oUniformReal(oRandom);
		}
		printf("정수 배열 요소");
		for (int i = 0; i < nSize; ++i)
		{
			printf("%d ",anValues[i]);
		}
		printf("실수형 요소");
		for (int i = 0; i < nSize; ++i)
		{
			printf("%.2f ", afValues[i]);
		}

		int nSum = 0;
		float fAverage = 0.0f;
		GetSumAndAverage(anValues, nSize, nSum, fAverage);
		printf("\n\n합계 %d \n", nSum);
		printf("평균 %f \n", fAverage);

	#endif // E02_FUNC_OVERLOADING
	}
	
}
