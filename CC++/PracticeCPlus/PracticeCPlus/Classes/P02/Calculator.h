#pragma once
#include "../Global/Define/KGDefine.h"

class CCalculator
{
public:
	//숫자 배열 구조체
	struct STData
	{
		float m_nValue;
	};

public://숫자 배열
	int GetNumDatas();
	//추가
	void AddData(const STData& a_rstData);
	//삭제
	void RemoveData(const int a_rID);
	//검색
	STData FindData(const int a_rID);
public:
	//전환
	void Transform(void);
	
	//연산
	void Calculation(void);

	//출력
	void PrintResult(void);

public://생성 소멸자
	//생성자 소멸자
	CCalculator(std::string a_sFormula);

	~CCalculator();

private:
	//연산자
	std::string Formula;
	std::string Operator;
	//결과
	float Result;
	//숫자
	int m_nNumDatas = 0;
	STData m_stDatas[100] = { 0 };
};
