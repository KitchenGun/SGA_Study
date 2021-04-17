#include "P01.h"

//#define P1	1
#define P2	2

namespace P01Space
{
#if P1
	class CString
	{
	public:
		enum
		{
			DEF_SIZE = 10
		};
	public://생성 소멸
		CString(int a_nArraySize = DEF_SIZE)
			:
			m_nArraySize(a_nArraySize)
		{//초기화
			m_customString = new char[a_nArraySize];
			memset(m_customString, 0, sizeof(char) * a_nArraySize);
		}

		~CString()
		{
			SAFE_DELETE_ARRAY(m_customString);
		}

	public:
		//사용가능한 명령 출력
		void PrintList()
		{
			std::cout << "\n===== 메뉴 =====" << std::endl;
			std::cout << "1. 문자열 추가" << std::endl;
			std::cout << "2. 문자열 제거" << std::endl;
			std::cout << "3. 문자열 검색" << std::endl;
			std::cout << "4. 종료" << std::endl;
			printf("\n메뉴 선택 : ");
		}

		//명령 실행
		void Execute(int a_nSelectValue)
		{
			char* temp = new char[100];
			switch (a_nSelectValue)
			{
			case 1:
				std::cout << "추가 할 문자열 입력 : ";
				std::cin >> temp;
				AddString(temp);
				break;
			case 2:
				std::cout << "제거 할 문자열 입력 : ";
				std::cin >> temp;
				RemoveString(temp);
				break;
			case 3:
				std::cout << "검색 할 문자열 입력 : ";
				std::cin >> temp;
				FindString(temp);
				break;
			case 4:
				std::cout << " 종료 " << std::endl;
				break;
			default:
				std::cout << "잘못된 값을 입력하셨습니다." << std::endl;
				break;
			}

			SAFE_DELETE_ARRAY(temp);
		}

		//! 문자열을 추가한다
		void AddString(const char* a_pszString)const
		{
			strcat(this->m_customString, a_pszString);
			std::cout << "문자열 추가 결과 : " << this->m_customString << std::endl;
		}

		//! 문자열을 제거한다
		void RemoveString(const char* a_pszString)const
		{
			//문자열 길이 확인
			int nStrlen = strlen(m_customString) - 1;
			if (nStrlen <= -1)
			{
				std::cout << "제거할 문자열이 없습니다." << std::endl;
				return;
			}
			//중복 문자열 확인
			SameString(0, a_pszString, 0);
			RemoveEmptySpace();
			std::cout << m_customString << std::endl;
			//std::cout << "문자열 제거 결과 : " << this->m_customString << std::endl;
		}
		//중복 문자열 위치 확인
		void SameString(int a_nIdx, const char* a_pszCheckString, int a_nCheckIdx)const
		{
			int nMStrlen = strlen(m_customString) - 1;
			int nCStrlen = strlen(a_pszCheckString) - 1;
			//문자열의 길이보다 작을 경우 검색 실행
			while (a_nIdx <= nMStrlen)
			{
				if (m_customString[a_nIdx] == a_pszCheckString[a_nCheckIdx])
				{
					if (a_nCheckIdx == nCStrlen)
					{
						m_customString[a_nIdx] = ' ';
					}
					else
					{
						SameString(++a_nIdx, a_pszCheckString, ++a_nCheckIdx);
						if (m_customString[a_nIdx] == ' ')
						{
							m_customString[a_nIdx-1] = ' ';
						}
					}

				}
				else
				{
					SameString(++a_nIdx, a_pszCheckString, 0);
				}
			}
		}
		//공백 문자열 삭제
		void RemoveEmptySpace()const
		{
			int nIdx = 0;
			for (unsigned int i = 0; i < strlen(m_customString); i++)
			{
				if (m_customString[i] == ' ')
				{
					if (m_customString[i + 1] == ' ')
					{
						if (i + 1 == strlen(m_customString)-1)
						{
							m_customString[i + 1] = 0;
							i = 0;
						}
						else
						{
							m_customString[i] = m_customString[i + 1];
							m_customString[i + 1] = ' ';
						}
					}
					else
					{
						m_customString[i] = m_customString[i + 1];
						m_customString[i + 1] = ' ';
					}
				}
				else
				{
					nIdx++;
				}
			}
			if (nIdx <=strlen(m_customString)-1)
			{
				RemoveEmptySpace();
			}
		}


		//! 문자열을 검색한다
		void FindString(const char* a_pszString)
		{
			std::cout << "문자열 검색 결과 : ";
			printf("%d",FindString(0, a_pszString, 0, false));
		}

		int FindString(int a_nIdx, const char* a_pszString, int a_nCheckIdx, bool Check)const
		{
			int nMStrlen = strlen(m_customString);
			int nCStrlen = strlen(a_pszString);

			//문자열의 길이보다 작을 경우 검색 실행
			if (a_nIdx <= nMStrlen)
			{
				if (m_customString[a_nIdx] == a_pszString[a_nCheckIdx])
				{
					if (a_nCheckIdx == nCStrlen-1)
					{
						if (nCStrlen == 1)
						{
							return a_nIdx;
						}
						return a_nIdx - (nCStrlen-1);
					}
					else
					{
						return FindString(++a_nIdx, a_pszString, ++a_nCheckIdx, true);

					}
				}
				else
				{
					return FindString(++a_nIdx, a_pszString, 0, false);
				}
			}
			else
			{
				return -1;
			}
		}

		//! 문자열을 반환한다
		char* GetString(void)
		{
			return this->m_customString;
		}

		private:

			int m_nArraySize;

			char* m_customString = nullptr;

		};
#elif P2
//캐릭터
class CGameObject
{
public:
	//! 공격력을 반환한다
	int GetATK(void)const
	{
		return ATK;
	}
	//! 공격력 수정한다
	void SetATK(int a_nATK)
	{
		ATK = a_nATK;
	}
	//! 방어력을 반환한다
	int GetDEF(void)const
	{
		return DEF;
	}
	//! 방어력을 수정한다
	void SetDEF(int a_nDEF)
	{
		DEF = a_nDEF;
	}
	//! 체력을 반환한다
	int GetHP(void)const
	{
		return HP;
	}
	//! 체력을 수정한다
	void SetHP(int a_nHP)
	{
		HP = a_nHP;
	}
	//! 회피율을 반환한다
	float GetAGI(void)const
	{
		return AGI;
	}
	//! 회피율을 수정한다
	void SetAGI(float a_nAGI)
	{
		AGI = a_nAGI;
	}
	//사망 확인
	bool DeadCheck()
	{
		if (GetHP() <= 0)
		{
			return true;
		}
		return false;
	}

	//스탯 입력
	void SetState()
	{
		int a_nATK = 0;
		int a_nDEF = 0; 
		int a_nHP = 0; 
		float a_nAGI = 0.0f;
		std::cin >> a_nATK >> a_nDEF >> a_nHP >> a_nAGI;
		SetATK(a_nATK);
		SetDEF(a_nDEF);
		SetHP(a_nHP);
		SetAGI(a_nAGI);
	}
	//공격
	void Attack(CGameObject &Enemy)
	{
		
		if (this->ATK - Enemy.GetDEF() <= 0)
		{//방어력이 높을 경우 체력을 1만 깍는다
			Enemy.SetHP(Enemy.GetHP() - 1);
		}
		else
		{
			Enemy.SetHP
			(
				Enemy.GetHP() - (this->ATK - this->DEF)
			);
		}
	}
public:
	CGameObject(int a_nATK = 0, int a_nDEF = 0, int a_nHP = 0, float a_nAGI = 0.0f)
		:
		ATK(a_nATK),
		DEF(a_nDEF),
		HP(a_nHP),
		AGI(a_nAGI)
	{
		//do nothing
	}
	
	
private:
	int ATK;
	int DEF;
	int HP;
	float AGI;
};

class CPlayer : public CGameObject
{
public:
	CPlayer(int a_nATK = 0, int a_nDEF = 0, int a_nHP = 0, float a_nAGI = 0.0f)
		:
	CGameObject(a_nATK, a_nDEF, a_nHP, a_nAGI)
	{
		//do nothing
	}
};

class CMonster :public CGameObject
{
public:
	CMonster(int a_nATK = 0, int a_nDEF = 0, int a_nHP = 0, float a_nAGI = 0.0f)
		:
		CGameObject(a_nATK, a_nDEF, a_nHP, a_nAGI)
	{
		//do nothing
	}

};

//결투장
class CBattleMachine
{
public:
	//배틀할 객체 가져오기
	void SetPlayer(CGameObject a_cPlayer)
	{
		cPlayer = a_cPlayer;
	}
	void SetMonster(CGameObject a_cMonster)
	{
		cMonster = a_cMonster;
	}
public:
	//! 배틀을 시작한다
	void StartBattle(void)
	{
		printf("\n===== 배틀 진행 상황 =====\n");

		do 
		{
			if (AttackChance(cPlayer))
			{
				cPlayer.Attack(cMonster);
				printf("플레이어 공격 성공 (몬스터 남은 체력 : %d)\n", cMonster.GetHP());
				if (cMonster.DeadCheck())
				{
					PrintBattleResult();
					bSimEnd=true;
					break;
				}
			}
			else
			{
				printf("플레이어 공격 실패 (몬스터 남은 체력 : %d)\n", cMonster.GetHP());
			}
			if (AttackChance(cMonster))
			{
				cMonster.Attack(cPlayer);
				printf("몬스터 공격 성공 (플레이어 남은 체력 : %d)\n", cPlayer.GetHP());
				if (cPlayer.DeadCheck())
				{
					PrintBattleResult();
					bSimEnd = true;
					break;
				}
			}
			else
			{
				printf("몬스터 공격 실패 (플레이어 남은 체력 : %d)\n", cPlayer.GetHP());
			}
			printf("\n");
		} while (bSimEnd != true);
	}

	bool AttackChance(CGameObject cEnemy)
	{//true 반환시 공격 false 반환시 공격 실패
		std::random_device oRandom;
		std::uniform_real_distribution<float> oUniformReal(0.0f, 1.0f);
		if (oUniformReal(oRandom) >= cEnemy.GetAGI())
		{
			return true;
		}
		return false;
	}
	
	//! 배틀 결과 출력
	void PrintBattleResult(void)
	{
		printf("\n===== 배틀 진행 결과 =====\n");
		if (cMonster.DeadCheck())
		{
			printf("플레이어 승\n");
		}
		else
		{
			printf("몬스터 승\n");
		}
	}
public:
	CBattleMachine(CGameObject a_cPlayer, CGameObject a_cMonster)
		:
		cPlayer(a_cPlayer),
		cMonster(a_cMonster)
	{
		//do nothing
	}

private:
	CGameObject cPlayer;
	CGameObject cMonster;

	bool bSimEnd = false;
};

#endif	// P1

	void P01(const int argc, const char** args)
	{
#if P1
		int nSelectValue;
		CString cString;

		do
		{
			cString.PrintList();
			//입력
			std::cin >> nSelectValue;
			cString.Execute(nSelectValue);
		} while (nSelectValue != 4);


#elif P2
		CPlayer cPlayer;
		CMonster cMonster;

		printf("플레이어 스탯 입력 (공격력, 방어력, 체력, 회피율) : ");
		cPlayer.SetState();
		printf("몬스터 스탯 입력 (공격력, 방어력, 체력, 회피율) : ");
		cMonster.SetState();
		//업캐스팅
		CBattleMachine cBattle((CGameObject)cPlayer, (CGameObject)cMonster);

		cBattle.StartBattle();

#endif	// P1

	}
}
