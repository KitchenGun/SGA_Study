#include "E07.h"

#define E07_TEMPLATE_FUNC	1
#define E07_TEMPLATE_CLS	2


namespace E07Space
{
#if E07_TEMPLATE_FUNC
	struct STData
	{
		int m_nVal;
		float m_fVal;

	};

	/*
	모든 템플릿 함수 또는 클래스는 template 키워드로 명시를 해줘야하며 template 함수 또는 클래스는 자료형을 대체할 형식인자가 필요하다 
	형식 인자는 typename 또는 클래스 키워드를 통해서 선언하는 것이 가능하며 해당 인자의 개수는 필요한 만큼 지정하는 것이 가능하다
	*/
	template <typename T>
	//값을 교환해 준다
	void Swap(T &a_rtLhs, T &a_rtRhs)
	{
		T tTemp = a_rtLhs;
		a_rtLhs = a_rtRhs;
		a_rtRhs = tTemp;
	}
	/*
	템플릿의 형식 인자에는 자료형 뿐만 아니라 상수도 명시하는 것이 가능하다
	해당 상수를 활용해서 배열등의 동작 할당 코드를 작성하는 것이 가능하다
	*/
	//배열을 생성한다
	template <typename T,int SIZE =5>
	T* MakeArr(int a_nSize = SIZE)
	{
		return new T[a_nSize];
	}
	
	/*
	c++ 템플릿은 특정 자료형일 경우 기존의 템플릿이 아니라 별도의 템플릿으로 동작하는 특수화 기능을 제공합니다
	단 함수 템플릿은 템플릿의 부분 특수화 기능 제공하지 않으며 템플릿의 완전 특수화만 지원합니다
	즉 템플릿의 부분 특수화란 템플릿의 형식 인자가 2개 이상일 경우 
	해당 인자의 자료형을 모두 지정하는 것이 아니라 일부만 지정 할수있는 기능을 의미한다
	*/
	//값을 교환한다
	//템플릿의 완전 특수화 같은 경우 템플릿이 아닌 함수와 결과적으로 동일한 원형을 지니지만 
	//템플릿 함수의 경우 해당 함수를 실제 호출해야지만 템플릿 함수가 생성되는 
	//반면 일반적인 전역함수는 함수의 호출 여부와 상관없이 해당 함수가 기계어로 번역이 된다
	template <>
	void Swap(STData &a_rstLhs, STData &a_rstRhs)
	{
		Swap<int>(a_rstLhs.m_nVal, a_rstRhs.m_nVal);
	}

#elif E07_TEMPLATE_CLS
#endif // E07_TEMPLATE_FUNC

	void E07(const int argc, const char ** args)
	{
	#if E07_TEMPLATE_FUNC
		int nValA=10;
		int nValB=20;
		float fValA=10.0f;
		float fValB=20.0f;
		
		std::string oStrA = "ABCD";
		std::string oStrB = "abcd";
		
		STData stDataA = { 10,10.0f };
		STData stDataB = { 20,20.0f };

		printf("\n교환전\n");
		printf("%d %d\n", nValA, nValB);
		printf("%f %f\n", fValA, fValB);
		printf("%s %s\n", oStrA.c_str(), oStrB.c_str());
		printf("(%d %f) (%d %f)", stDataA.m_nVal, stDataA.m_fVal, stDataB.m_nVal, stDataB.m_fVal);

		//템플릿 함수를 호출 할때 자료형을 별도로 명시해주는 것이 좋은 습관이다
		//매개변수의 자료형을 기반으로 컴파일러가 찾아준다 이는 원치 않는 결과를 만들어 낼수있기에 명시한다 속도 차이는 없음 
		Swap<int>(nValA, nValB);
		Swap<float>(fValA, fValB);
		Swap<std::string>(oStrA, oStrB);
		Swap<STData>(stDataA, stDataB);

		printf("\n교환후\n");
		printf("%d %d\n", nValA, nValB);
		printf("%f %f\n", fValA, fValB);
		printf("%s %s\n", oStrA.c_str(), oStrB.c_str()); 
		printf("(%d %f) (%d %f)", stDataA.m_nVal, stDataA.m_fVal, stDataB.m_nVal, stDataB.m_fVal);

		int *pnVals = MakeArr<int>(10);
		float *pfVals = MakeArr<float>(10);

		for (int i = 0; i < 10; i++)
		{
			pnVals[i] = i + 1;
			pfVals[i] = i + 1.0f;
		}
		printf("\n동적 할당결과\n");

		printf("int : ");
		for (int i = 0; i < 10; i++)
		{
			printf("%d ", pnVals[i]);
		}
		printf("\n");
		printf("float : ");
		for (int i = 0; i < 10; i++)
		{
			printf("%.2f ", pfVals[i]);
		}
		printf("\n");
		SAFE_DELETE_ARRAY(pnVals);
		SAFE_DELETE_ARRAY(pfVals);
	#elif E07_TEMPLATE_CLS
	#endif // E07_TEMPLATE_FUNC
	
	}
}
