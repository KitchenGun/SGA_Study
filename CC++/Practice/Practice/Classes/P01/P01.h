#pragma once

#include "../Global/Define/KGDefine.h"

void P01(const int argc, const char ** args);

//���� 2
void DefinePlusMinursFunc(char sign, int defPlusMinurs);

//���� 5
int CpuInputProc(int selectNum, int CpuNum);

//���� 6
void PrintMatrix(char matrix[][3]);

void CharEliminate(char* str, char ch);