//해더파일을 중복적으로 참조를 현상을 막음
//헤더파일의 첫문장에는 해당 명령어 기입해야함
#pragma once
#define _CRT_SECURE_NO_WARNINGS



/*
#include 키워드는 프로젝트 내부 외부에 존재하는 기능을 가져오는 역할을 수행한다.
stdio.h 파일에는 입출력 관련 기능이 존재하며 미리 만들어져서 제공되는 기능들의 집합을 표준라이브러리라고 한다.
표준라이브러리는 공식적으로 지원되는 기능이기기 때문에 대부분의 컴파일러에서도 해당 파일에 존재하는 기능을 사용하는것이 가능하다.

또한 제3자에 의해서 비공식적으로 제공하는 기능을 3rd Party 라이브러리라고한다.
공식적인 기능이 아니기때문에 다른 컴파일에서 해당기능을 사용할경우 동작하지 않을수있다.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <time.h>

//매크로 함수를 사용하면 반복적으로 발생하는 코드 작성을 방지 하는 것이 가능하다 단 기본적으로 매크로 함수는 1줄에 전부 기입해야한다.
//\을 사용하여서 줄바꿈 가능  매크로 함수는 코드를 생성 할때 사용 (보통의 경우 일반 함수를 사용해라)
#define SAFE_FREE(TARGET)	\
if((TARGET)!=NULL){free((TARGET));(TARGET)=NULL;}

//#include <random>