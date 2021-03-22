#pragma once

#include"../Global/Define/KGDefine.h"

//자료형 = 데이터를 인식하는 or 해석 방법
//사용자는 자료형 통해서 컴퓨터가 해석방법을 결정 해줘야한다
/*
정수		바이트
short	 2
int		 4
long	 4 or 8 
longlong 8
실수
float	 4
double   8
문자
char	 1

정수 = 소수점이 없는 수 표현
실수 = 소수점을 포함하는 수를 표현
문자 = 한 문자 표현

변수란 데이터를 저장할수있는 공간의미

c언어 변수 선언 방법
자료형 + 변수 이름
ex) 
int nValueA;
short nValueB;

상수란 변수와 달리 데이터를 기록하면 변경 불가능 상수는 필요한 시점 읽어들이는 행위만 가능하다
const + 자료형 + 상수이름
ex)
const int nValueA(심볼릭) = 0(리터널 상수)
이름이 존재하는 심볼릭 상수
이름이 존재하지않는 리터널 상수
*/
//ex) 1이 문자형인가 정수 형인가
//Example 2
void E02(int argc, char **args);