#include "E08.h"

namespace E08Space
{
	void E08(const int argc, const char ** args)
	{
		/*
		auto 키워드를 사용하면 특정 지역 변수의 자료형을 컴파일러에 자동으로 지정하게 만드는 것이 가능하다
		즉 자료형의 이름이 길 경우 auto 키워드를 사용하면 타이핑에 대한 개발 기간을 단축하는 것이 가능하다

		단 해당 키워드를 사용했을 경우 변수에는 반드시 초기화 값을 명시해줘야한다
		이는 컴파일러가 초기화 값의 자료형을 기반으로 auto로 명시된자료형을 결정하기 때문이다
		*/
		auto nValA = 0;
		auto fValB = 0.0f;
		auto pszStr = "Hello";


		int anVals[5] = { 1,2,3,4,5 };

		//
		printf("일반적인 for문 결과\n");
		for (int i = 0; i < 5; i++)
		{
			printf("%d ", anVals[i]);
		}
		printf("\n범위기반 for 결과\n");
		/*
		범위기반 for문은 기존 반복문을 구성할때 잘못된 범위를 명시함으로써 발생하는 실수를 줄이기 위해 새롭게 등장한 반복문이다 
		즉 해당 반복문을 사용하면 반복에 대한 범위를 내부적으로 판단해서 동작하기때문에 잘못된 범위를 명시하는 실수를 방지하는 것이 가능하다

		단 해당 반복문은 반복을 한번씩 진행할때 마다 특정 컬렉션에 있는 요소를 사본에 복사하는 개념으로 동작하기 때문에 
		만약 해당 반복문 내부에서 원본 요소의 값을 변경하기 위해서는 레퍼런스를 사용해야한다
		*/
		for (int &rnVal : anVals)
		{
			rnVal *= 2;
		}

		for (int nVal : anVals)
		{
			printf("%d ", nVal);
		}
	
	}
}
