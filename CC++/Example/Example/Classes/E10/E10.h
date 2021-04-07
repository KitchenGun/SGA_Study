#pragma once

#include "../Global/Define/KGDefine.h"
/*
	동적 할당이란?
	프로그램 실행중에 필요한 만큼 메모리를 사용 및 해제할수있는 기능을 의미함
	동적으로 할당한 메모리는 시스템에 의해서 관리가 되지 않기 때문에 더이상 사용되지 않는 메모리라면 반드시 해제를 해줘야한다. 
	만약 불필요한 메모리를 해제 하지 않을 경우 정상적으로 필요한 메모리의 공간이 줄어 들기 때문에 정작 필요한 순간 메모리 부족으로 할당 불가능 상황 발생함
	이런 상황을 메모리 릭
	c언어 동적 할당 하는 방법
	malloc 
	calloc
	realloc  

	ex)
	int *pnValueA = (int*)malloc(sizeof(int));			
	int *pnValueB = (int*)calloc(sizeof(int),1);

*/
void E10(int argc, char **args);