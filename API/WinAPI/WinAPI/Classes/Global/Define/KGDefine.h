#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <dinput.h>
#include <Windows.h>
#include <tchar.h>


//메모리 관리

#define SAFE_FREE(TARGET)\
if((TARGET)!=nullptr){free((TARGET));(TARGET)=nullptr;}

#define SAFE_FCLOSE(TARGET)\
if((TARGET)!=nullptr){fclose((TARGET));(TARGET)=nullptr;}

#define SAFE_DEL(TARGET)\
if((TARGET)!=nullptr){delete(TARGET);(TARGET)=nullptr;}

#define SAFE_DEL_ARR(TARGET)\
if((TARGET)!=nullptr){delete[](TARGET);(TARGET)=nullptr;}

#define SAFE_DEL_DC(TARGET)\
if((TARGET)!=nullptr){DeleteDC((TARGET));(TARGET)=nullptr;}

#define SAFE_DEL_GDI_OBJ(TARGET)\
if((TARGET)!=nullptr){DeleteObject((TARGET));(TARGET)=nullptr;}

#define SAFE_RELEASE_DC(WND_HANDLE,TARGET)\
if((TARGET)!=nullptr){ReleaseDC((WND_HANDLE),(TARGET));(TARGET)=nullptr;}

#define SAFE_RELEASE(TARGET)\
if((TARGET)!=nullptr){(TARGET)->Release();(TARGET)=nullptr;}

#define SAFE_UNACQUIRE(TARGET)\
if((TARGET)!=nullptr){(TARGET)->Unacquire();SAFE_RELEASE((TARGET));}
//시간 관리자
#define GET_TIME_MANAGER()	(CTimeManager::GetInst())

#define GET_DELTA_TIME()	(GET_TIME_MANAGER()->GetDeltaTime())

#define	GET_RUNNING_TIME()	(GET_TIME_MANAGER()->GetRunningTime())
//윈도우 어플리케이션
#define GET_WND_APP()		(CWndApp::GetInst())

#define GET_WND_SIZE()		(GET_WND_APP()->GetWndSize())

#define GET_WND_HANDLE()	(GET_WND_APP()->GetWndHandle())

#define GET_INST_HANDLE()	(GET_WND_APP()->GetInstHandle())

//싱글톤
#define DECLARE_SINGLETON(CLS_NAME)	\
private:							\
CLS_NAME(void);						\
~CLS_NAME(void);					\
public:								\
static CLS_NAME* GetInst(void)		\
{									\
	static CLS_NAME oInst;			\
	return &oInst;				\
}

//마우스 버튼
enum class EMouseBtn
{
	NONE=-1,
	LEFT,
	RIGHT,
	MIDDLE,
	MAX_VAL
};