#include "P02.h"

namespace  P02Space
{
	class CCalculator
	{
	public:
		//���� �迭 ����ü
		struct STData
		{
			float m_nValue;
		};

	public://���� �迭
		int GetNumDatas()
		{
			return m_nNumDatas;
		}
		//�߰�
		void AddData(const STData& a_rstData)
		{
			m_stDatas[m_nNumDatas++] = a_rstData;
		}
		//����
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
		//�˻�
		STData FindData(const int a_rID)
		{
			if (a_rID >= 0)
			{
				return m_stDatas[a_rID];
			}
			return { 0 };
		}
	public:
		//��ȯ
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
		//����
		void Calculation(void)
		{//���� �迭 ������ �ڸ� Ȯ��
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
		//���
		void PrintResult(void)
		{
			printf("��� ��� : %.2f", FindData(0).m_nValue);
		}

	public://���� �Ҹ���
		//������ �Ҹ���
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
		//������
		std::string Formula;
		std::string Operator;
		//���
		float Result;
		//����
		int m_nNumDatas = 0;
		STData m_stDatas[100] = { 0 };
	};

	
	void P02(const int argc, const char** args)
	{
		std::string sFomulaInput;
		printf("���� �Է� : ");
		std::cin >> sFomulaInput;
		CCalculator calculator(sFomulaInput);
		calculator.Transform();
		calculator.PrintResult();
	}
	
}
