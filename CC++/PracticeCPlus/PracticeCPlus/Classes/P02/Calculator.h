#pragma once
#include "../Global/Define/KGDefine.h"

class CCalculator
{
public:
	//���� �迭 ����ü
	struct STData
	{
		float m_nValue;
	};

public://���� �迭
	int GetNumDatas();
	//�߰�
	void AddData(const STData& a_rstData);
	//����
	void RemoveData(const int a_rID);
	//�˻�
	STData FindData(const int a_rID);
public:
	//��ȯ
	void Transform(void);
	
	//����
	void Calculation(void);

	//���
	void PrintResult(void);

public://���� �Ҹ���
	//������ �Ҹ���
	CCalculator(std::string a_sFormula);

	~CCalculator();

private:
	//������
	std::string Formula;
	std::string Operator;
	//���
	float Result;
	//����
	int m_nNumDatas = 0;
	STData m_stDatas[100] = { 0 };
};
