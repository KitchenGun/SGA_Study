#pragma once

#include "../Global/Define/KGDefine.h"


/*
객체 지향의 3대 요소 

상속
다향성
정보은닉 캡슐화
상속이란?

특정 클래스 간에 공통되는 속성 및 기능를 하나의 클래스에 구현 및 해당 클래스를 공유 할수있는 기능을 의미한다 
즉 상속을 활용하면 클래스 간에 중복되는 속성등을 줄이는 것이 가능하다

상속이라는 것은 각 클래스 간에 관계를 형성하는 것이며 해당기능을 사용하면 부모자식의 관계를 만들어 내는 것이 가능하다

ex
class CParent
{
protected:
	int m_nValue=0;
};
class CChild : public CParent
{
	//출력
	void PrintValue(void)
	{
	printf("value : %d\n",m_nValue);
	}
}

자식 클래스는 부모 클래스를 상속했기 때문에 부모 클래스에 선언된 맴버 변수및 함수를 그대로 사용하는 것이 가능하다. 
단 부모의 private 영역에 존재하는 맴버는 자식이여도 접근 못함
*/
namespace E04Space
{
	void E04(const int argc, const char **args);
}