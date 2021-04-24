#include "P02.h"

namespace  P02Space
{
	class CCalculator
	{
	public:
		//숫자 배열 구조체
		struct STData
		{
			float m_nValue;
		};

	public://숫자 배열
		int GetNumDatas()
		{
			return m_nNumDatas;
		}
		//추가
		void AddData(const STData& a_rstData)
		{
			m_stDatas[m_nNumDatas++] = a_rstData;
		}
		//삭제
		void RemoveData(const int a_rID)
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
		//검색
		STData FindData(const int a_rID)
		{
			if (a_rID >= 0)
			{
				return m_stDatas[a_rID];
			}
			return { 0 };
		}
	public:
		//전환
		void Transform(void)
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
		//연산
		void Calculation(void)
		{//현재 배열 마지막 자리 확인
			int nOperatorArraySize = (int)Operator.size();
			int nNumArraySize =GetNumDatas()-1;

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
		//출력
		void PrintResult(void)
		{
			printf("계산 결과 : %.2f", FindData(0).m_nValue);
		}

	public://생성 소멸자
		//생성자 소멸자
		CCalculator(std::string a_sFormula)
			:
			Formula(a_sFormula),
			Result(0)
		{

		}

		~CCalculator()
		{

		}

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

	
	void P02(const int argc, const char** args)
	{
		std::string sFomulaInput;
		printf("수식 입력 : ");
		std::cin >> sFomulaInput;
		CCalculator calculator(sFomulaInput);
		calculator.Transform();
		calculator.PrintResult();
	}
	
}
