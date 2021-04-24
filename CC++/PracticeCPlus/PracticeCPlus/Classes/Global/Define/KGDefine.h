#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cassert>
#include <random>
#include <functional>
#include <algorithm>
#include <string>
#include <stdlib.h>

#define SAFE_DELETE(TARGET)			if((TARGET)!=nullptr){delete(TARGET); (TARGET =nullptr);}
#define SAFE_DELETE_ARRAY(TARGET)	if((TARGET)!=nullptr){delete[](TARGET); (TARGET =nullptr);}