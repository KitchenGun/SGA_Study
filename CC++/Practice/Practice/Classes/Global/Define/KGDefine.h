#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <time.h>

#define SAFE_FREE(TARGET)	\
if((TARGET)!=NULL){free((TARGET));(TARGET)=NULL;}
