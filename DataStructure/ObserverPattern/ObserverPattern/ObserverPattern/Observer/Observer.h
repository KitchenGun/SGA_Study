#pragma once
class Observer
{ 
public: 
	Observer() {}
	virtual ~Observer() {} 
	virtual void onNotify() = 0; //등록된 객체들에게 전달
	virtual void RegisterObserver() = 0; //수신받을 객체를 등록하는 함수
	virtual void RemoveObserver() = 0;	//수신을 받던 객체의 수신을 해제하는 함수
};
