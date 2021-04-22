#include "E05.h"

//#define E05_CLASS_MEM	1
#define E05_SINGLETON	2
#if E05_SINGLETON
#define SINGLETON_CASE_A	1
#define SINGLETON_CASE_B	2
#endif // E05_SINGLETON


namespace E05Space
{
#if E05_CLASS_MEM
	//위젯
	class CWidget
	{
	public:
		//값 반환
		int GetValue(void)const
		{
			return m_nValueA;
		}
		//값 변경
		void SetValue(int a_nValue)
		{
			m_nValueA = a_nValue;
		}
		//값 추가
		void AddValue(int a_nValue)
		{
			m_nValueB += a_nValue;
		}
		static int GetConstMemValue(void)
		{
			return m_nValueB;
		}

		/*
		클래스 함수 내부에서는 일반적인 맴버 변수 및 함수를 사용하는 것이 불가능 하다

		이는 맴버 변수 및 함수는 사용위해서 특정 객체의 지정 해줘야 하기때문이다
		즉 클래스 함수내부에서는 특정 객체를 지정하기 위한 this 포인터가 전달되지 않는다
		*/
		//정보를 출력한다 클래스 맴버 함수
		static void ShowInfo(void)
		{
			//m_nValueA;
			printf("widget호출\n");
		}
	private:
		int m_nValueA = 0;
		static int m_nValueB;
	};
	/*
	클래스 변수는 일반적인 맴버 변수와 달리 클래스 내부에 선언을 해주는 것만으로 사용하는 것이 불가능 하다 따라서
	해당 클래스 외부에서 반드시 클래스 변수에 대한 초기화를 해줘야 해당 클래스 변수의 정의가 완료된다.
	*/
	//class 맴버 변수(static) 초기화
	int CWidget::m_nValueB = 0;


#elif E05_SINGLETON
#if SINGLETON_CASE_A

	//싱글톤 데이터 관리자
	class CDataManager
	{
	public:
		struct STData
		{
			std::string m_oID;

			int m_nValue;
			float m_fValue;
		};
	public:
		//데이터 반환
		STData GetData(const std::string &a_rID)
		{
			int nIdx = this->FindData(a_rID);
			assert(nIdx >= 0);//항상 0보다 크다는 것을 가정하고 작성
			/*
			assert 매크로 함수를 사용하면 특정 조건이 거짓 일때 프로그램을 더이상 실행하지 않고 해당 파일에 대한 파일 경로+라인 출력해준다
			assert 매크로는 개발중인 프로젝트에서만 작동하며 빌드버전 (디버깅을 안하는 작업)에서 작동하지 않는다 
			*/
			// try catch 대신에 사용함 


			return m_astDatas[nIdx];
		}
		//데이터 추가
		void AddData(const STData &a_rstData)
		{
			int nIdx = this->FindData(a_rstData.m_oID);
			//데이터 없을시
			if (nIdx <= -1)
			{
				m_astDatas[m_nNumDatas++] = a_rstData;
			}
		}
		//데이터 제거
		void RemoveData(const std::string &a_rID)
		{
			int nIdx = this->FindData(a_rID);
			//데이터 존재시
			if (nIdx >= 0)
			{
				for (int i = nIdx; i < m_nNumDatas - 1; ++i)
				{
					m_astDatas[i] = m_astDatas[i + 1];
				}
				m_nNumDatas -= 1;
			}
		}
		//데이터 탐색
		int FindData(const std::string &a_rID)
		{
			for (int i = 0; i < m_nNumDatas; ++i)
			{
				if (m_astDatas[i].m_oID == a_rID)
				{
					return i;
				}
			}
			return -1;
		}
		//인스턴스 반환
		static CDataManager *GetInst(void)
		{
			//인스턴스 존재 안할경우   
			/*
			싱글톤 패턴은 결과적으로 생성되는 객체를 1개로 제한 함으로서 전역 변수와 마찬가지로 고유한 객체 및 데이터를 생성하는 것이다 또한 일반적으로 싱글톤
			객체는 미리 생성하는 것이 아니라 해당 객체를 필요로 하는 중간 생성이 된다
			이를 Lazy Initialization
			게으른 초기화 객체 생성시 초기화 라고한다
			*/
			if (CDataManager::m_pInst == nullptr)
			{
				CDataManager::m_pInst = new CDataManager();

				/*
				CDataManager의 복사 생성자를 구현부가 없고 원형만 존재하기 때문에 이는 곧 해당 클래스를 통해 생성된 객체를 복사하는 것이 불가능하다는 것을 의미한다
				즉 객체가 복사 되기 위해서는 복사 생성자가 호출되어야하는데 복사 생성자의 구현부가 존재하지 않기 때문에 링크 에러가 발생한다
				*/
				//CDataManager oDataManager(*CDataManager::m_pInst);
			}

			return CDataManager::m_pInst;
		}
		//인스턴스 제거
		static void DestroyInst(void)
		{
			//인스턴스 존재할 경우
			if (CDataManager::m_pInst != nullptr)
			{
				SAFE_DELETE(CDataManager::m_pInst);
			}
		}
	private:
		CDataManager(void)
		{
			//do nothing
		}
		virtual ~CDataManager(void)
		{
			//do nothing
		}
		//복사생성자 
		CDataManager(const CDataManager &a_rOther);

	private:
		int m_nNumDatas = 0;
		STData m_astDatas[100];
		static CDataManager *m_pInst;
	};

	CDataManager *CDataManager::m_pInst = nullptr;
#elif SINGLETON_CASE_B
//싱글톤 A
class CSingletonA 
{
public:
	//정보 출력
	void ShowInfo(void);

	DECLARE_SINGLETON(CSingletonA)
};
/*
:: 범위 지정 연산자를 사용하면 클래스의 맴버함수를 클래스 외부에 구현하는 것이 가능하다 즉 해당 연산자를 활용하면
클래스의 선언 헤더파일 클래스의 정의는 소스파일에 각각 특정 클래스를 분리해서 코드작성하는 것이 가능하다
*/
//생성&소멸자
CSingletonA::CSingletonA(void)
{
	printf("생성자a 호출\n");
}
CSingletonA::~CSingletonA(void)
{
	printf("소멸자a 호출\n");
}
//정보 출력
void CSingletonA::ShowInfo(void)
{
	printf("csingleton A 호출\n");
}
//싱글톤 B
class CSingletonB
{
public:
	void ShowInfo(void);

	DECLARE_SINGLETON(CSingletonB)
};
//생성&소멸자
CSingletonB::CSingletonB(void)
{
	printf("생성자b 호출\n");
}
CSingletonB::~CSingletonB(void)
{
	printf("소멸자b 호출\n");
}
//정보 출력
void CSingletonB::ShowInfo(void)
{
	printf("csingleton B 호출\n");
}
//싱글톤 C
class CSingletonC
{
public:
	void ShowInfo(void);

	DECLARE_SINGLETON(CSingletonC)
};
//생성&소멸자
CSingletonC::CSingletonC(void)
{
	printf("생성자c 호출\n");
}
CSingletonC::~CSingletonC(void)
{
	printf("소멸자c 호출\n");
}
void CSingletonC::ShowInfo(void) 
{
	printf("csingleton C 호출\n");
}
#endif // SINGLETON_CASE_A
#endif // E05_CLASS_MEM

	
	void E05(const int argc, const char ** args)
	{
	#if E05_CLASS_MEM
		CWidget oWidgetA;
		CWidget oWidgetB;
		
		oWidgetA.ShowInfo();
		CWidget::ShowInfo();
		
		oWidgetA.SetValue(10);
		oWidgetB.SetValue(20);

		oWidgetA.AddValue(10);
		oWidgetB.AddValue(20);
		/*
		 클래스 변수는 해당 클래스로 부터 생성된 모든 객체가 공유하는 변수이기때문에 해당 변수의 값을 변경하면 모든 객체가 영향을 받는다
		*/
		printf("\n클래스 변수 조작 결과\n");
		printf("A : %d, %d\n", oWidgetA.GetValue(),oWidgetA.GetConstMemValue());
		printf("B : %d, %d\n", oWidgetB.GetValue(),oWidgetB.GetConstMemValue());
	#elif E05_SINGLETON
	#if SINGLETON_CASE_A
		/*
	CDataManager는 생성자가 private임으로 해당객체를 클래스 외부에서 생성하는 것이 불가능하다
	소멸자 또한 private이기 때문에 클래스 외부에서 객체 제거가 불가능 하다
	*/
	//delete CDataManager::GetInst;


		for (int i = 0; i < 10; i++)
		{
			CDataManager::STData stData = { std::to_string(i),i + 1,i + 1.5f };

			CDataManager::GetInst()->AddData(stData);
		}
		printf("데이타 관리자 추가 결과\n");
		for (int i = 0; i < 10; i++)
		{
			std::string oID = std::to_string(i);
			CDataManager::STData stData = CDataManager::GetInst()->GetData(oID);

			printf("Data : [%d, %f]\n", stData.m_nValue, stData.m_fValue);
		}

		CDataManager::DestroyInst();
	#elif SINGLETON_CASE_B
		CSingletonA::GetInst()->ShowInfo();
		printf("\n");
		CSingletonB::GetInst()->ShowInfo();
		printf("\n");
		CSingletonC::GetInst()->ShowInfo();
		printf("\n");
	#endif // SINGLETON_CASE_A
	#endif //E05_CLASS_MEM
	}
}
