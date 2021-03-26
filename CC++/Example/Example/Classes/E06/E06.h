#pragma once

#include "../Global/Define/KGDefine.h"

/*
배열이란?
-다수의 동일한 자료형의 데이터를 손쉽게 선언 및 관리 할수있는 기능을 의미한다

c언어 배열 선언하는 방법
자료형 +  배열 이름 + 배열 길이

EX)int anValues[5];

비주얼에서 상수만 인덱스 연산자로 사용가능하고 변수를 사용할수없다
배열은 [] (인덱스 연산자)를 활용하여 선언하고 배열의 데이터를 요소라고한다
C 언어는 배열의 요소에 접근하기 위해서 인덱스 연산자와 인덱스 번호의 조합을 통해서 해당 행위가 가능하다
인덱스 번호의 범위는 0~배열 길이 -1의 범위를 지니며 만약 해당 범위를 벗어난 인덱스 번호를 명시하면 오류남

다차원 배열이란?
c 언어의 배열은 인덱스 연산자의 조합을 통해서 배열의 차원을 명시하는 것이 가능하다 즉 하나의 인덱스연산자만 명시했을경우 
이를 1차원이라고하며 2개 이상명시했을 경우 다차원 배열이라고 한다.

EX) int anMatrix[5][5]; <=int 형 2차원 배열 선언


배열리스트 VS 연결 리스트
배열은 인덱스를 통한 연산자와 번호의 조합을 통한 랜덤엑세스(임의 접근이 가능하기 때문에 특정 데이터의 순서를 알고 있다면 상수 시간(0(1))
[데이터의 개수와 상관없이 한번의 비교를 통해서 접근이 가능하다]에 접근하는 것이 가능
반면 리스트는 중간에 데이터 삽입삭제가 발생했을 경우 데이터 순차성을 유지를 위한 나머지 데이터의 이동이 발생한다 즉 데이터의 삽입 삭제 효율이 떨어진다

연결 리스트는 특정데이터의 순서를 알고있다 하더라고 임의 접근이 불가능하기 때문에 항상 첫번째 데이터 부터 순차적으로 탐색을 시도해야한다. 
탐색을 주로할 경우 효율이 떨어진다. 물리적인 메모리의 순서가 아닌 가상의 순서를 부여해 데이터의 순차성을 만들기 때문에 특정 데이터의 삽입 삭제가 발생할경우
데이터의 이동이 발생하지 않는다 즉 배열 리스트에 비해 삽입 삭제 효율 좋음 

문자열이란?
문자의 조합을 통해서 단어 또는 문장을 표현 할수 있는 기능을 의미한다
하지만 컴퓨터의 입장에서는 문자열이란 데이터는 존재하지 않기 때문에 프로그래밍 언어에서 문자열을 표현하기위해서는 문자형의 배열을 사용해야한다

EX)
char szString[100] = "ABC";



단 문자형 배열이 문자열이 되기 위해서는 규칙이 필요하다 이규칙은 마지막 문자에는 반드시 널문자를 포함해줘야한다
즉 5글자의 문자열을 표현하기 위해서는 적어도 길이가 6이상인 배열이 필요하다

*/

void E06(int argc, char **args);



