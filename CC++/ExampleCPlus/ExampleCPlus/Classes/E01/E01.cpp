#include "E01.h"

//using namespace std;
//using 키워드를 사용해서 특정 이름 공간을 명시하면 해당공간 하위에 존재하는 
//함수 변수등일 해당공간을 명시하지 않고 사용하는 것이 가능하다
//동일한 이름의 함수를 다른 공간에서 선언 및 정의 했을 경우 이름 충돌에 의해서 컴파일러 오류가 발생하기 때문에 해당 경우를 조심해야한다.

namespace E01Space
{
	void E01(const int argc, const char ** args)
	{
		int nValue = 10;
		float fValue = 3.14f;

		/*
		c++모든 표준 라이브러리는 std 공간 하위에 존재한다
		cout 객체는 콘솔창에 데이터 출력을 수행한다
		cin 객체는 콘솔창으로 부터 데이터 입력을 받는 행위를 수행한다
		*/

		std::cout << "Hi" << std::endl;//요청
		std::cout << "nValue " << nValue << " fValue " << fValue << std::endl;

		printf("AAA");//명령
		
		std::cout << "\n데이터 입력 : ";
		std::cin >> nValue;

		std::cout << nValue << "*" << nValue << "=" <<nValue*nValue<< std::endl;

	
	}
}
