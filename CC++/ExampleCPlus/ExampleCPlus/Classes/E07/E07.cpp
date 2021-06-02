#include "E07.h"

//#define E07_TEMPLATE_FUNC	1
#define E07_TEMPLATE_CLS	2

#if E07_TEMPLATE_CLS
#define TEMPLATE_CLS_CASE_A	1
//#define TEMPLATE_CLS_CASE_B 2
#define TEMPLATE_CLS_CASE_C 3

#endif 
namespace E07Space
{
#if E07_TEMPLATE_FUNC
	struct STData
	{
		int m_nVal;
		float m_fVal;

	};

	/*
	모든 템플릿 함수 또는 클래스는 template 키워드로 명시를 해줘야하며 template 함수 또는 클래스는 자료형을 대체할 형식인자가 필요하다 
	형식 인자는 typename 또는 클래스 키워드를 통해서 선언하는 것이 가능하며 해당 인자의 개수는 필요한 만큼 지정하는 것이 가능하다
	*/
	template <typename T>
	//값을 교환해 준다
	void Swap(T &a_rtLhs, T &a_rtRhs)
	{
		T tTemp = a_rtLhs;
		a_rtLhs = a_rtRhs;
		a_rtRhs = tTemp;
	}
	/*
	템플릿의 형식 인자에는 자료형 뿐만 아니라 상수도 명시하는 것이 가능하다
	해당 상수를 활용해서 배열등의 동작 할당 코드를 작성하는 것이 가능하다
	*/
	//배열을 생성한다
	template <typename T,int SIZE =5>
	T* MakeArr(int a_nSize = SIZE)
	{
		return new T[a_nSize];
	}
	
	/*
	c++ 템플릿은 특정 자료형일 경우 기존의 템플릿이 아니라 별도의 템플릿으로 동작하는 특수화 기능을 제공합니다
	단 함수 템플릿은 템플릿의 부분 특수화 기능 제공하지 않으며 템플릿의 완전 특수화만 지원합니다
	즉 템플릿의 부분 특수화란 템플릿의 형식 인자가 2개 이상일 경우 
	해당 인자의 자료형을 모두 지정하는 것이 아니라 일부만 지정 할수있는 기능을 의미한다
	*/
	//값을 교환한다
	//템플릿의 완전 특수화 같은 경우 템플릿이 아닌 함수와 결과적으로 동일한 원형을 지니지만 
	//템플릿 함수의 경우 해당 함수를 실제 호출해야지만 템플릿 함수가 생성되는 
	//반면 일반적인 전역함수는 함수의 호출 여부와 상관없이 해당 함수가 기계어로 번역이 된다
	template <>
	void Swap(STData &a_rstLhs, STData &a_rstRhs)
	{
		Swap<int>(a_rstLhs.m_nVal, a_rstRhs.m_nVal);
	}

#elif E07_TEMPLATE_CLS
#if TEMPLATE_CLS_CASE_A

	//연결 리스트
	template <class T>
	class CLinkedList
	{
	public:
		//노드
		struct  STNode
		{
			T m_tVal;
			STNode *m_pstNextNode;
		};
	public:
		//생성자 소멸자
		CLinkedList(void)
		{
			//do nothing
		}
		virtual ~CLinkedList(void)
		{
			this->Reset();
		}
		CLinkedList(const CLinkedList &a_rOther)
		{
			*this = a_rOther;
		}
		//복사생성자

	public:
		//operator =
		CLinkedList & operator=(const CLinkedList &a_rOther)
		{
			this->Reset();
			STNode *pstCurNode = a_rOther.m_pstHeadNode;
			while (pstCurNode != nullptr)
			{
				this->AddVal(pstCurNode->m_tVal);
				pstCurNode = pstCurNode->m_pstNextNode;
			}

			return *this;
		}
	public:
		//함수
		//상태 리셋
		void Reset(void)
		{
			STNode *pstCurNode = m_pstHeadNode;

			while (pstCurNode != nullptr)
			{
				STNode *pstRemoveNode = pstCurNode;
				pstCurNode = pstCurNode->m_pstNextNode;

				SAFE_DELETE(pstRemoveNode);
			}
			m_pstHeadNode = nullptr;
		}
		//값 개수 반환
		int GetNumVals(void)const
		{
			return m_nNumVals;
		}
		//데이터 추가
		void AddVal(T a_tVal)
		{
			STNode *pstNode = this->CreateNode(a_tVal);
			//헤드 노드가 존재하지 않을 경우
			if (m_pstHeadNode == nullptr)
			{
				m_pstHeadNode = pstNode;
			}
			else
			{
				STNode *pstTailNode = m_pstHeadNode;

				//테일 노드 탐색한다
				while (pstTailNode->m_pstNextNode != nullptr)
				{
					pstTailNode = pstTailNode->m_pstNextNode;
				}
				pstTailNode->m_pstNextNode = pstNode;
			}
			m_nNumVals += 1;
		}
		//데이터 탐색
		STNode *FindVal(int a_nIdx)
		{
			STNode *pstCurNode = m_pstHeadNode;
			for (int i = 0; i < a_nIdx; i++)
			{
				pstCurNode = pstCurNode->m_pstNextNode;
			}
			return pstCurNode;
		}
	private:
		//node 생성
		STNode *CreateNode(T a_tVal)
		{
			STNode *pstNode = new STNode();
			pstNode->m_tVal = a_tVal;
			pstNode->m_pstNextNode = nullptr;

			return pstNode;
		}
	private:
		//변수
		int m_nNumVals = 0;
		STNode*m_pstHeadNode = nullptr;
	};
#elif TEMPLATE_CLS_CASE_B
	//싱글톤 템플릿으로 작성하는 이유 c++와 c를 제외하고는 전처리 함수를 사용할수없어서 이런 방식으로 제작함
	//템플릿 클래스로 제작된 코드 부분은 최소한 싱글톤이 가춰야할 기능을 기입하고 나머지는 상속으로 처리를 한다.
template <class T>
class CSinglton
{
public:
	static T *GetInst(void)
	{
		//인스턴스 존재안할경우
		if (CSinglton::m_pInst == nullptr)
		{
			CSinglton::m_pInst = new T();
		}
		return m_pInst;
	}
	//인스턴스 제거
	static void DestroyInst(void)
	{
		//인스턴스 존재할경우
		if (CSinglton::m_pInst != nullptr)
		{
			SAFE_DELETE(CSinglton::m_pInst);
		}
	}
protected:
	//생성자 소멸자
	CSinglton(void)
	{
		//do nothing
	}
	virtual ~CSinglton(void)
	{
		//do nothing
	}
	//복사 생성자
	CSinglton(const CSinglton &a_rOther);

private:
	//변수
	static T *m_pInst;
};

template <class T> 
T *CSinglton<T>::m_pInst = nullptr;

//위젯
class CWidget :public CSinglton<CWidget>
{
public:
	/*
	c++언어는friend 키워드를 특정 클래스와 동맹관계로 명시하는 것이 가능하다
	이때 동맹 관계가 성립된 클래스는 해당 키워드를 명시한 클래스의 private 맴버에 접근하는 것이 가능하다 
	단 friend 키워드는 단방향이기 때문에 상대방 클래스가 해당 클래스를 friend로 명시하지 않았을 경우에는 private 맴버에 접근하는 것이 불가능하다
	*/
	friend class CSinglton<CWidget>;
public:
	void ShowInfo(void)
	{
		printf("CWidget.CWidget(void)함수 호출\n");
	}
private:
	//생성자
	CWidget(void)
	{
		printf("CWidget.CWidget(void)생성자 호출\n");
	}
	virtual ~CWidget(void)
	{
		printf("CWidget.CWidget(void)소멸자 호출\n");
	}
};
#elif TEMPLATE_CLS_CASE_C
	//데이터
template<class T1,class T2>
class CData
{
public:
	//생성자
	CData(void)
	{
		printf("CData<T1 T2>.CData(void)생성자 호출\n");
	}
private:
	T1 m_tValA;
	T2 m_tValB;
};

/*
c++ 클래스 템플릿은 함수템플릿과 달리
형식 인자가 2개 이상일 경우 특정 형식만 고정하는 것이 가능하며 이를 템플릿의 부분 특수화라고 한다
단 이때 클래스 이름 옆에 템플릿 형식 인자를 명시해줘야지만 컴파일러가 해당 클래스 템플릿이 
부분 특수화 템플릿이라고 인식할수있다
*/
//데이터
template <class T>
class CData<int,T>//이걸 명시해줘야 부분 특수화이다
{
public:
	//생성자
	CData(void)
	{
		printf("CData<int T>.CData(void)생성자 호출\n");
	}
private:
	//변수
	int m_nValA;
	T m_nValB;

};

template <>
class CData<int, float>
{
public:
	//생성자
	CData(void)
	{
		printf("CData<int float>.CData(void)생성자 호출\n");
	}
private:	
	//변수
	int m_nValA;
	float m_nValB;
};

#endif // TEMPLATE_CLS_CASE_A
#endif // E07_TEMPLATE_FUNC

	void E07(const int argc, const char ** args)
	{
	#if E07_TEMPLATE_FUNC
		int nValA=10;
		int nValB=20;
		float fValA=10.0f;
		float fValB=20.0f;
		
		std::string oStrA = "ABCD";
		std::string oStrB = "abcd";
		
		STData stDataA = { 10,10.0f };
		STData stDataB = { 20,20.0f };

		printf("\n교환전\n");
		printf("%d %d\n", nValA, nValB);
		printf("%f %f\n", fValA, fValB);
		printf("%s %s\n", oStrA.c_str(), oStrB.c_str());
		printf("(%d %f) (%d %f)", stDataA.m_nVal, stDataA.m_fVal, stDataB.m_nVal, stDataB.m_fVal);

		//템플릿 함수를 호출 할때 자료형을 별도로 명시해주는 것이 좋은 습관이다
		//매개변수의 자료형을 기반으로 컴파일러가 찾아준다 이는 원치 않는 결과를 만들어 낼수있기에 명시한다 속도 차이는 없음 
		Swap<int>(nValA, nValB);
		Swap<float>(fValA, fValB);
		Swap<std::string>(oStrA, oStrB);
		Swap<STData>(stDataA, stDataB);

		printf("\n교환후\n");
		printf("%d %d\n", nValA, nValB);
		printf("%f %f\n", fValA, fValB);
		printf("%s %s\n", oStrA.c_str(), oStrB.c_str()); 
		printf("(%d %f) (%d %f)", stDataA.m_nVal, stDataA.m_fVal, stDataB.m_nVal, stDataB.m_fVal);

		int *pnVals = MakeArr<int>(10);
		float *pfVals = MakeArr<float>(10);

		for (int i = 0; i < 10; i++)
		{
			pnVals[i] = i + 1;
			pfVals[i] = i + 1.0f;
		}
		printf("\n동적 할당결과\n");

		printf("int : ");
		for (int i = 0; i < 10; i++)
		{
			printf("%d ", pnVals[i]);
		}
		printf("\n");
		printf("float : ");
		for (int i = 0; i < 10; i++)
		{
			printf("%.2f ", pfVals[i]);
		}
		printf("\n");
		SAFE_DELETE_ARRAY(pnVals);
		SAFE_DELETE_ARRAY(pfVals);
	#elif E07_TEMPLATE_CLS
	#if TEMPLATE_CLS_CASE_A
		CLinkedList<int> oValListA;
		CLinkedList<std::string> oValListB;

		for (int i = 0; i < 10; i++)
		{
			oValListA.AddVal(i + 1);
			oValListB.AddVal(std::to_string(i + 1));
		}

		printf("\nA리스트요소\n");
		for (int i = 0; i < 10; i++)
		{
			printf("%d ", oValListA.FindVal(i)->m_tVal);
		}
		printf("\nB리스트요소\n");
		for (int i = 0; i < 10; i++)
		{
			printf("%s ", oValListB.FindVal(i)->m_tVal.c_str());
		}
	#elif TEMPLATE_CLS_CASE_B
		CWidget::GetInst()->ShowInfo();
		CWidget::GetInst()->ShowInfo();
		CWidget::GetInst()->ShowInfo();
	#elif TEMPLATE_CLS_CASE_C

		CData<std::string, std::string> oDataA;
		CData<int, std::string> oDataB;
		CData<int, float> oDataC;

	#endif // TEMPLATE_CLS_CASE_A
	#endif // E07_TEMPLATE_FUNC
	}
}
