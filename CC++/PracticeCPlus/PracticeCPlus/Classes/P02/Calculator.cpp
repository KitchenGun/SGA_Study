#include "Calculator.h"

int CCalculator::GetNumDatas()
{
	return m_nNumDatas;
}

void CCalculator::AddData(const STData& a_rstData)
{
	m_stDatas[m_nNumDatas++] = a_rstData;
}

void CCalculator::RemoveData(const int a_rID)
{
	if (a_rID >= 0)
	{
		for (int i = a_rID; i < m_nNumDatas - 1; ++i)
		{
			m_stDatas[i] = m_stDatas[i + 1];
		}
	}
	m_nNumDatas--;
}

CCalculator::STData CCalculator::FindData(const int a_rID)
{
	if (a_rID >= 0)
	{
		return m_stDatas[a_rID];
	}
	return { 0 };
}

void CCalculator::Transform(void)
{
	for (int i = 0; i < Formula.size(); ++i)
	{
		switch (Formula[i])
		{
		case'(':
		{
			Operator += "(";
			break;
		}
		case')':
		{
			Calculation();
			break;
		}
		case'+':
		{
			Operator += "+";
			break;
		}
		case'-':
		{
			Operator += "-";
			break;
		}
		case'*':
		{
			Operator += "*";
			break;
		}
		case'/':
		{
			Operator += "/";
			break;
		}
		default:
			STData stData = { (float)atoi(&Formula[i]) };
			AddData(stData);
			break;
		}
	}
	Calculation();
}

void CCalculator::Calculation(void)
{//현재 배열 마지막 자리 확인
	int nOperatorArraySize = (int)Operator.size();
	int nNumArraySize = GetNumDatas() - 1;

	float nResult;

	while (Operator[nOperatorArraySize] != '(')
	{
		if (--nOperatorArraySize >= 0)
		{
			switch (Operator[nOperatorArraySize])
			{
			case'+':
			{
				Operator[nOperatorArraySize] = '\0';
				nResult = (float)FindData(nNumArraySize - 1).m_nValue + FindData(nNumArraySize).m_nValue;
				STData stData = { nResult };
				RemoveData(nNumArraySize);
				RemoveData(nNumArraySize - 1);
				AddData(stData);
				break;
			}
			case'-':
			{
				Operator[nOperatorArraySize] = '\0';
				nResult = (float)FindData(nNumArraySize - 1).m_nValue - FindData(nNumArraySize).m_nValue;
				STData stData = { nResult };
				RemoveData(nNumArraySize);
				RemoveData(nNumArraySize - 1);
				AddData(stData);
				break;
			}
			case'*':
			{
				Operator[nOperatorArraySize] = '\0';
				nResult = (float)FindData(nNumArraySize - 1).m_nValue * FindData(nNumArraySize).m_nValue;
				STData stData = { nResult };
				RemoveData(nNumArraySize);
				RemoveData(nNumArraySize - 1);
				AddData(stData);
				break;
			}
			case'/':
			{
				Operator[nOperatorArraySize] = '\0';
				nResult = (float)FindData(nNumArraySize - 1).m_nValue / FindData(nNumArraySize).m_nValue;
				STData stData = { nResult };
				RemoveData(nNumArraySize);
				RemoveData(nNumArraySize - 1);
				AddData(stData);
				break;
			}
			case'(':
			{
				Operator[nOperatorArraySize] = '\0';
				break;
			}
			}
		}
		else
		{
			break;
		}
	}

}

void CCalculator::PrintResult(void)
{
	printf("계산 결과 : %.2f", FindData(0).m_nValue);
}

CCalculator::CCalculator(std::string a_sFormula)
	:
	Formula(a_sFormula),
	Result(0)
{

}

CCalculator::~CCalculator()
{

}