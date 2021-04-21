#pragma once
#include "../Global/Define/KGDefine.h"
/*
클래스 맴버란?
일반적인 맴버 변수 및 함수는 객체를 생성하고 나서 사용이 가능하지만 
클래스 맴버는 객체를 생성하지 않고도 해당 맴버를 사용하는 것이 가능하다
즉 일반적인 맴버는 객체에 종속되는 반면 클래스 맴버는 클래스 자체에 종속되기 때문에 
모든 객체가 공통적으로 사용할수있다는 특징이 있다.

ex 
class CWidget
{
public:
//정보를 출력한다
static void ShowInfo(void);
private:
static int m_nValue;
};

위와 같이 클래스 맴버를 선언하기 위해서는 변수및함수에 static 키워드를 명시하면 된다


싱글톤이란?
프로그램 상에서 전역적으로 공유되는 객체 또는 데이터를 생성할 수있는 디자인 패턴중 하나로써 
전역 변수를 사용하는 것 보다 좀 더 안전하게 프로그램 상에서 공유되는 사원을 생성 및 관리하는 것이 가능하다
*/

namespace E05Space
{
	void E05(const int argc, const char **args);
}