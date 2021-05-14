#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cassert>
#include <Windows.h>
#include <tchar.h>
#include <vector>


//메모리 관리

#define SAFE_FREE(TARGET)\
if((TARGET)!=nullptr){free((TARGET));(TARGET)=nullptr;}
#define SAFE_FCLOSE(TARGET)\
if((TARGET)!=nullptr){fclose((TARGET));(TARGET)=nullptr;}

#define SAFE_DEL(TARGET)\
if((TARGET)!=nullptr){delete(TARGET);(TARGET)=nullptr;}
#define SAFE_DEL_ARR(TARGET) \
if((TARGET)!=nullptr){delete[](TARGET);(TARGET)=nullptr;}
#define SAFE_RELEASE_DC(WND_HANDLE,TARGET)\
if((TARGET)!=nullptr){ReleaseDC((WND_HANDLE),(TARGET));(TARGET)=nullptr;}
//윈도우 어플리케이션
#define GET_WND_APP()		(CWndApp::GetInst())

#define GET_WND_SIZE()		(GET_WND_APP()->GetWndSize())

#define GET_WND_HANDLE()	(GET_WND_APP()->GetWndHandle())

#define GET_INST_HANDLE()	(GET_WND_APP()->GetInstHandler())