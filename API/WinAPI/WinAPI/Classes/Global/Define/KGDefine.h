#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cassert>
#include <Windows.h>
#include <tchar.h>


//메모리 관리

#define SAFE_FREE(TARGET)\
if((TARGET)!=nullptr){free((TARGET));(TARGET)=nullptr;}
#define SAFE_FCLOSE(TARGET)\
if((TARGET)!=nullptr){fclose((TARGET));(TARGET)=nullptr;}

#define SAFE_DEL(TARGET)\
if((TARGET)!=nullptr){delete(TARGET);(TARGET)=nullptr;}
#define SAFE_DEL_ARR(TARGET) \
if((TARGET)!=nullptr){delete[](TARGET);(TARGET)=nullptr;}
