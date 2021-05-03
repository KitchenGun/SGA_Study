#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cassert>
#include <random>
#include <functional>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <conio.h>


#define SAFE_DELETE(TARGET)			if((TARGET)!=nullptr){delete(TARGET); (TARGET =nullptr);}
#define SAFE_DELETE_ARRAY(TARGET)	if((TARGET)!=nullptr){delete[](TARGET); (TARGET =nullptr);}




#define DECLARE_ACCESSER(DATA_TYPE, ACCESSER_NAME, VAR_NAME)			\
DATA_TYPE Get##ACCESSER_NAME(void) const { return VAR_NAME; }			\
void Set##ACCESSER_NAME(DATA_TYPE a_nVar) { VAR_NAME = a_nVar; }
