#pragma once
class ObserverManager
{ 
public: 
	virtual void onNotify() = 0; //��ϵ� ��ü�鿡�� ����
	virtual void RegisterObserver() = 0; //���Ź��� ��ü�� ����ϴ� �Լ�
	virtual void RemoveObserver() = 0;	//������ �޴� ��ü�� ������ �����ϴ� �Լ�
};
