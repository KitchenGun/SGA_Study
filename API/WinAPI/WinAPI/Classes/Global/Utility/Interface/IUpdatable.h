#pragma once

#include"../../Define/KGDefine.h"


//�����������̽�
class IUpdatable
{
public:
	//���¸� �����Ѵ�
	virtual void Update(float a_fDeltaTime) = 0;//���� �����Լ� ��ӽ� �ݵ�� ����
	//���¸� ���� �����Ѵ�
	virtual void LateUpdate(float a_fDeltaTime) {}//���� �����Լ� ��ӽ� �ʿ�� ���� �������ص� ������
};