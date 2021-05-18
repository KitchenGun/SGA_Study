#pragma once

#include"../../Define/KGDefine.h"


//갱신인터페이스
class IUpdatable
{
public:
	//상태를 갱신한다
	virtual void Update(float a_fDeltaTime) = 0;//순수 가상함수 상속시 반드시 구현
	//상태를 지연 갱신한다
	virtual void LateUpdate(float a_fDeltaTime) {}//순수 가상함수 상속시 필요시 구현 구현안해도 괜찮음
};