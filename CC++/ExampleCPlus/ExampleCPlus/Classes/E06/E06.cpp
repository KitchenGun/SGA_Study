#include "E06.h"

namespace E06Space
{
	//배열
	class CArray
	{
	public:
		enum
		{
			DEF_SIZE = 5
		};
	public:
		/*
		만약에 []=을 표현하고 싶으면
		operator[] 내부에서operator=을 호출하도록 제작해야한다
			oArray[i]=

			c++클래스의 언어는 클래스의 맴버 함수하고 상수 맴버 함수 인지 일반적인 맴버 함수인지에 대한 유무를 기반으로 함수 오버로딩을 제공한다
			즉 맴버 함수의 상수 전용 여부 또한 함수 오버로딩의 조건중 하나이다.
			따라서 해당 특징을 잘 활용하면 기존에 가진 논리대로 객체가 연산자를 사용하는 것이 가능하다

		만약 맴버 함수의 일반 버전과 상수 버전 모두 호출이 가능할 경우
		우선 순위는 일반 맴버 함수가 더 높기 때문에 해당 경우에는 일반 맴버 함수가 호출된다
		*/
		//operator[]
		//레퍼런스
		int & operator[](const int a_nIdx)
		{
			/*
			역 참조 연산자 와 맴버 지정 연산자를 동시에 사용했을 경우 일반적으로
			먼저 맴버 지정이 해석 되고 역참조 연산자가 해석이 된다
			따라서 아래의 경우 this 객체의 맴버가 가리키는 곳에 접근해라 라는 식으로 해석이 된다
			//*this.n_nNumValues=10;
			
			반면 아래의 경우 ()(우선 순위 연산자)레 의해서 역참조 연산자를 먼저 해석되게 우선 순위를 변경했기 때문에 해당 구문은 컴파일러에 의해서
			this 포인터가 가리키는 객체 또는 구조체의 맴버 m_nNumValues에 접근해라는 식으로 해석이 된다
			//(*this).n_nNumValues=10;
			맴버 지정 연산자 대신 포인터 맴버 지정 연산자를 사용했지만
			맴버 지정 연산자를 사용했을때와 포인터 맴버 지정 연산자가 먼저 해석된 후 역참조 연산자가 해석 된다
			즉 포인터 맴버 지정 연산자 또한 역참조 연산자 보다 우선 순위가 높다
			//*this->n_nNumValues=10;
			*/
			return m_pnValues[a_nIdx];
		}
		//operator[]
		//레퍼런스 x
		int operator[](const int a_nIdx) const
		{
			/*
			상수 맴버 함수에서 오버로딩된 일반 맴버 함수를 호출하기 위해서는
			해당 객체가 지니고 있는 상수성을 일시적으로 제거 시킨 후 해당함수를 호출하면된다
			즉 객체의 상수성 제거 되었기 때문에 함수 오버로딩 호출 우선 순위에 따라서
			상수버전의 함수가 아니라 일반 맴버함수가 호출이 된다
			*/
			//case 1 레퍼런스 형으로 변환후 연산자 사용
			return const_cast<CArray &>(*this)[a_nIdx];
			//return const_cast<CArray &>(*this).operator[](a_nIdx); 위의 구문은 이것 처럼 해석이 된다
		
			//case 2 포인터로 변환 후 연산자 오버로딩 된 함수 직접 호출 
			return const_cast<CArray*>(this)->operator[](a_nIdx);
		}
		
		//operator
		CArray& operator=(const CArray &a_rOther)//객체를 대상으로 연산자를 쓸수있게 만드는 부분 
		{
			SAFE_DELETE_ARRAY(m_pnValues);

			m_nSize = a_rOther.m_nSize;
			m_nNumValues = a_rOther.m_nNumValues;

			m_pnValues = new int[a_rOther.m_nSize];
			memcpy(m_pnValues, a_rOther.m_pnValues, sizeof(int)*a_rOther.m_nSize);

			return *this;
		}

	public:
		//값의 개수를 반환
		int GetNumValues() const
		{
			return m_nNumValues;
		}
		//값을 반환한다
		int GetValue(int a_nIdx)const
		{
			return m_pnValues[a_nIdx];
		}
		//값을 변경한다
		void SetValue(int a_nIdx, int a_nValue)
		{
			m_pnValues[a_nIdx] = a_nValue;
		}
		//값을 추가한다
		void AddValue(int a_nValue)
		{
			//배열이 가득 찼을 경우
			if (m_nNumValues >= m_nSize)
			{
				m_nSize *= 2;
				m_pnValues = (int *)realloc(m_pnValues, sizeof(int)*m_nSize);
			}

			m_pnValues[m_nNumValues++] = a_nValue;
		}


	public://생성자 소멸자
		CArray(int a_nSize = DEF_SIZE)
			:
			m_nSize(a_nSize)
		{
			m_pnValues = new int[a_nSize];
			memset(m_pnValues, 0, sizeof(int)*a_nSize);
		}
		//복사 생성자
		CArray(const CArray &a_rOther)
		{
			*this = a_rOther;
		}


		~CArray()
		{
			SAFE_DELETE_ARRAY(m_pnValues);

		}

	private://변수
		int m_nSize;
		int m_nNumValues;

		int *m_pnValues = nullptr;
	};
	////operator[]
	//static int operator[](const CArray &a_rArray, int a_nIdx)
	//{
	//단 전역함수 버전 연산자 오버로딩은 맴버 함수버젼과 달리 사용할수있는 연산자의 종류가 제한되어있기 때문에 해당사항에 주의해서 전역 함수 버전을 제작해야한다
	//}

	/*
	c++언어는 전역 함수를 통해서 연산자 오버로딩을 할수있는 기능을 제공한다 
	이는 이미 완성되어 제공되는 클래스를 대상으로 연산자 오버로딩 할수있게 언어 차원에서
	지원되는 기능이다
	즉 맴버함수를 통한 연산자 오버로딩은 해당 클래스를 직접적으로 제작할때는 사용하는 것이 가능하지만
	이미 완성되어 라이브러리 형태로 제공되는 클래스에는 맴버 함수를 통한 연산자 오버로딩을 사용하는 것이 불가능하다
	*/
	//operator<<
	std::ostream & operator<<(std::ostream &a_rStream, const CArray &a_rArray)
	{
		for (int i = 0; i < a_rArray.GetNumValues(); ++i)
		{
			printf("%d ", a_rArray[i]);
		}
		return a_rStream;
	}

	void E06(const int argc, const char ** args)
	{
		CArray oArray;

		for (int i = 0; i < 10; ++i)
		{ 
			oArray.AddValue(i + 1);
		}
		for (int i = 0; i < oArray.GetNumValues(); ++i)
		{
			oArray[i] *= 10;
		}
		printf("배열 요소\n");
		for (int i = 0; i < oArray.GetNumValues(); ++i)
		{
			printf("%d ", oArray[i]);
		}
		printf("\n");
		std::cout << oArray << std::endl;
	}
}
