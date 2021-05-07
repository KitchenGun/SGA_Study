#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cassert>
#include <random>
#include <functional>
#include <algorithm>
#include <string>
#include <memory>
#include <thread>
#include <mutex>
#include <array>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <time.h>


#define SAFE_DELETE(TARGET)			if((TARGET)!=nullptr){delete(TARGET); (TARGET =nullptr);}
#define SAFE_DELETE_ARRAY(TARGET)	if((TARGET)!=nullptr){delete[](TARGET); (TARGET =nullptr);}
//��ũ���Լ��� \�� ���� �ǳ� ��ٴ� �ǹ��̴�
#define DECLARE_SINGLETON(CLS_NAME)			\
private:									\
CLS_NAME(void);								\
CLS_NAME(const CLS_NAME &a_rOther);			\
~CLS_NAME(void);							\
public:										\
static CLS_NAME * GetInst(void)				\
{											\
	static CLS_NAME oInst;					\
	return &oInst;							\
}
