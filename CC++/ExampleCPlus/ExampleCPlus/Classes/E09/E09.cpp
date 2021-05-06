#include "E09.h"

namespace  E09Space
{
//#define E09_COLLECTION		1
//#define E09_ITERATOR		2
#define E09_UTILITY_FUNC	3

#if E09_COLLECTION
//#define COLLECTION_ARRAY	1
//#define COLLECTION_VECTOR	2
//#define COLLECTION_LIST	3
//#define COLLECTION_MAP	4
#define COLLECTION_SET		5
#endif // E09_COLLECTION
#if E09_COLLECTION
#if COLLECTION_SET
	//문자열의 술열 여부를 검사한다
	bool IsUniqueStr(const std::string &a_rStr)
	{
		std::set<char> oLetterList;
		for (int i = 0; i < a_rStr.length(); ++i)
		{
			char chLetter = a_rStr[i];
			if (oLetterList.find(chLetter) != oLetterList.end())
			{
				return false;
			}
			oLetterList.insert(chLetter);
		}

		return true;

	}
#endif//COLLECTION_SET
#elif E09_ITERATOR
	//이터레이터 레퍼
	template <class T>
	class CIteratorWrapper
	{
	public:
		//첫 시작위치를 반환한다
		T *begin(void)
		{
			return m_ptVals;
		}
		//종료 위치를 반환한다
		T * end(void)
		{
			return m_ptVals + m_nNumVals;
		}

	public://생성자
		CIteratorWrapper(T *a_ptVals, int a_nNumVals)
		:
			m_nNumVals(a_nNumVals),
			m_ptVals(a_ptVals)
		{
			//do nothing
		}
	private:
		int m_nNumVals = 0;
		T *m_ptVals = nullptr;
	};
#endif//E09_COLLECTION



	void E09(const int argc, const char ** args)
	{
	#if E09_COLLECTION
	#if COLLECTION_ARRAY
		std::array<int, 10> oValListA;
		std::array<std::string, 10> oValListB;


		for (int i = 0; i < oValListA.size(); i++)
		{
			oValListA[i] = i + 1;
			oValListB[i] = std::to_string(i + 1);
		}
		printf("\nArray int 요소 출력\n");

		for (int i = 0; i < oValListA.size(); i++)
		{
			printf("%d ", oValListA[i]);
		}

		printf("\n\nArray string 요소 출력\n");

		for (int i = 0; i < oValListB.size(); i++)
		{
			printf("%s ", oValListB[i].c_str());
		}
		
	#elif COLLECTION_VECTOR
		std::vector<int> oValListA;
		std::vector<std::string> oValListB;

		/*
		vector 클래스는 array 클래스와 달리 동적으로 길이가 변하는 배열을 클래스화 시킨 컬렉션이기 때문에 해당 클래스를 통해서 객체를 생성했을 경우 기본적으로
		해당 객체의 요소 개수는 0이다 즉 생성과 동시에 size 함수를 호출했을 경우 0이 반환된다

		따라서 해당 컬렉션의 길이를 변경하기 위해서는 새로운 데이터를 추가 시킬 필요가 있으며 해당 행위는 push back 함수를 사용함 으로써 처리하는 것이 가능하다
		즉 push back 함수는 넘겨진 데이터를 컬렉션에 가장 마지막에 추가하는 역할을 수행하며 이때 기존 컬렉션에 더이상 데이터를 저장할수없을 경우 자동으로저장 공간을 
		늘려주는 역할을 수행한다

		vector 클래스는 push back 함수 이외에도 insert 함수를 제공하며 해당 함수를 사용하면 컬렉션의 특정 위치에 데이터를 추가하는 것이 가능하다
		즉 데이터를 가장 마지막 위치에 추가할때는 push back 함수를 사용하며 특정 위치에 추가 할때는 insert 함수를 사용하면 된다
		*/

		for (int i = 0; i < 10; i++)
		{
			oValListA.push_back(i + 1);
			oValListB.insert(oValListB.begin(),std::to_string(i + 1));
			/*
			vector 클래스를 생성과 동시에 인덱스 연산자를 통해서 특정 요소에 접근할 경우 잘못된 메모리 지정 에러가 발생한다
			이는 해당 연산자는 요소의 범위 내에서 인덱스를 지정하는 것이 가능하기 때문에 생성된후 아무런 데이터가 추가 되지 않은
			vector 객체는 길이가 0이기 때문에 해당 연산자를 사용하는 것이 불가능하다
			*/
			//oValListA[i] = i + 1;
			//oValListB[i] = std::to_string(i + 1);
		}
		printf("\nVector int 요소 출력\n");

		for (int i = 0; i < oValListA.size(); i++)
		{
			printf("%d ", oValListA[i]);
		}

		printf("\n\nVector string 요소 출력\n");

		for (int i = 0; i < oValListB.size(); i++)
		{
			printf("%s ", oValListB[i].c_str());
		}

#elif COLLECTION_LIST
		std::list<int> oValListA;
		std::list<std::string> oValListB;


		for (int i = 0; i < oValListA.size(); i++)
		{
			oValListA.push_back;
			oValListB.insert(oValListB.begin(), std::to_string(nVal));
		}
		/*
		list 클래스는 내부적으로 연결 리스크 기반으로 구현되어있기 때문에 vector 클래스와 달리 특정 요소에 한번에 접근하는 램덤 엑세스 기능을 지원하지 않습니다
		즉 [] 인덱스 연산자 사용 불가능
		따라서 해당 컬렉션의 요소에 접근하기 위해서 반복자 또는 범위 기반 for 문을 사용해야 한다
		즉 첫 요소 부터 순차적으로 접근해야한다
		*/
		printf("\nList int 요소 출력\n");

		for (int nVal : oValListA)
		{
			printf("%d ", nVal);
		}

		printf("\n\nList string 요소 출력\n");

		for (std::string oStr : oValListB)
		{
			printf("%s ", oStr.c_str());
		}
	#elif COLLECTION_MAP
		std::map<std::string, int> oValListA;
		std::unordered_map<std::string, std::string> oValListB;
		for (int i = 0; i < 15; ++i)
		{
			std::string oKey = std::to_string(i + 1);
			/*
			map 또는 unordered map 클래스는 키 벨류 쌍으로 데이터를 처리하기 때문에 해당 컬렉션에 새로운 요소를 추가 하기 위해서 
			make pair 함수 또는 value type을 통해서 키와 벨류를 하나의 쌍으로 만들어 줄 필요가 있다
			즉 키는 데이터를 탐색하기 위한 식별자 용도를 하며 벨류는 해당 컬렉션에 저장하기 위한 실제 데이터 의미한다
			*/
			oValListA.insert(std::make_pair(oKey, i + 1));
			//std::pair<int,int>를 반환형으로 사용하여서 여러개의 데이터를 넘길수있다. 
			//아래가 성능이 더 좋다 make pair는 내부적으로 복사를 해서 그렇다
			oValListB.insert(decltype(oValListB)::value_type(oKey, std::to_string(i + 1)));
			/*
			decltype 키워드를 사용하면 해당키워드 ()안에 명시된 표현식으로 컴파일러가 자료형을 추론하지만
			해당 키워드를 사용하면 map클래스에 데이터를 삽입하기 위한 코드를 좀더 축약 시키는 것이 가능하다
			
			일반적을 map 클래스에 데이터를 추가할때는 make_pair 사용보다 value type을 사용하는 것이 
			내부적으로 불필요한 복사가 발생하지 않기 때문에 좀더 퍼포먼스가 좋다
			auto는 선언시에만 사용할수있다. 
			*/
		}
		printf("\nmap 요소 출력\n");
		for (auto stKeyVal : oValListA)
		{
			printf("[%s] %d ", stKeyVal.first.c_str(), stKeyVal.second);//first 가 키 second 값을 의미한다 
		}
		//for (int i = 0; i < oValListA.size(); i++)
		//{
		//	std::string oKey = std::to_string(i + 1);
		//	printf("[%s] %d ", oKey.c_str(), oValListA[oKey]);
		//}
		/*
		map and unordered map 은 비선형 구조 이기때문에 해당 컬렉션에 저장되어있는 데이터의 순서는 해당 데이터를 추가 한 순서와는 상관없음
		따라서 특정 규칙에 맞게 데이터를 조회하기 위해서는 해당 규칙에 맞는 순서로 키를 생성해서 데이터 조회를 시도해야한다 
		*/
		printf("\nunordered_map 요소 출력\n");
		for (auto stKeyVal : oValListB)
		{
			printf("[%s] %s ", stKeyVal.first.c_str(), stKeyVal.second.c_str());
		}
		printf("\n");
		/*
		콜랙션의 특정 데이터를 제거하고 싶은 경우 erase 함수를 사용하면 된다 
		해당 함수는 컬렉션이 선형구조인지 비선형 구조 인지에 따라 요구하는 매개변수가 다르면 
		선형 컬랙션(vector list)에 경우 반복자를 요구하며
		비선형 구조(map unordered map)는 키를 매개 변수로 요구한다 
		*/
		oValListA.erase("5");//키가 5인 데이터 삭제
		oValListB.erase("10");

		printf("\n데이터 삭제후 map 요소 출력\n");
		for (auto stKeyVal : oValListA)
		{
			printf("[%s] %d ", stKeyVal.first.c_str(), stKeyVal.second);
		}
		printf("\n");
		printf("\n 데이터 삭제후 unorder_map 요소 출력\n");
		for (auto stKeyVal : oValListB)
		{
			printf("[%s] %s ", stKeyVal.first.c_str(), stKeyVal.second.c_str());
		}
		printf("\n");

	#elif COLLECTION_SET
		/*
		set은 집합의 특징을 가지는 컬렉션이기 때문에 해당 컬렉션에 저장되는 데이터의 중복을 허용하지 않는다.

		데이터의 중복을 방지할때 사용 ex 중복 문자열 찾기
		*/
		srand((unsigned int)time(NULL));
		std::set<int>oValList;
		for (int i = 0; i < 10; i++)
		{
			oValList.insert(rand() % 10);
		}

		printf("\n==set 요소 출력\n");

		for (int nVal : oValList)
		{
			printf("%d ",nVal);
		}

		char szStr[100] = "";
		printf("\n\n문자열 입력 : ");
		fgets(szStr, sizeof(szStr), stdin);
		//개행문자가 존재할경우
		if (szStr[strlen(szStr) - 1] == '\n')
		{
			szStr[strlen(szStr) - 1] = '\0';
		}
		printf("순열 여부 : %d\n", IsUniqueStr(szStr));


	#endif//COLLECTION_VECTOR
	#elif E09_ITERATOR
	std::vector<int> oValListA;
	std::unordered_map<std::string, int> oValListB;
	
	for (int i = 0; i < 10; i++)
	{
		std::string oKey = std::to_string(i + 1);
		oValListA.push_back(i + 1);
		oValListB.insert(decltype(oValListB)::value_type(oKey, i + 1));
	}
	printf("반복자를 통한 vector 요소 출력 \n");
	/*
	반복자를 통해 특정 컬렉션을 순회하기 위해서는 해당 컬렉션이 제공하는 begin함수를 통해서 
	가장 첫 데이터를 가리키는 반복자를 얻어온 후 end함수가 제공하는 값과
	일치하지 않을 동안 반복 구문을 실행하면 된다

	즉 stl의 모든 컬렉션의 반복의 시작과 끝을 나타내는 begin end 함수를 제공한다

	반복자는 컬렉션의 요소 중에 특정 위치를 가리키는 포인터 객체이기 때문에 해당 객체를 통해서 컬렉션의 요소에 접근하기 위해서는 
	*역참조 연산자또는 ->포인터 맴버 지정연산자를 사용해야한다
	*/
	for (auto oIterator = oValListA.begin(); oIterator != oValListA.end(); ++oIterator)
	{
		printf("%d ", *oIterator);
	}
	printf("반복자를 통한 unordered map 요소 출력 \n");
	for (auto oIterator = oValListB.begin(); oIterator != oValListB.end(); ++oIterator)
	{
		printf("[%s] %d ", oIterator->first.c_str(),oIterator->second);
	}

	int *pnVals = new int[10];
	std::string *poStrs = new std::string[10];
	
	CIteratorWrapper<std::string> oStrWrapper(poStrs, 10);
	CIteratorWrapper<int> oIntWrapper(pnVals, 10);
	/*
	동적으로 할당된 배열을 기반으로 범위기반 for 문을 사용하기 위해서는 반복자 인터페이스를 제공하는 클래스를 제작해야한다
	즉 begin과 end함수로 지니는 클래스를 선언및 구현해야함

	따라서 범위 기반 for 문은 컴파일러에 의해서 내부적으로 반복자를 활용한 코드로 변경이 된다는 것을 알수있다.
	*/
	for (int &rnVal : oIntWrapper)
	{
		rnVal = rand() % 10;
	}
	for (std::string &rStr : oStrWrapper)
	{
		rStr = std::to_string(rand() % 10);
	}

	printf("\n\n커스텀 범위 기반 for문 결과\n");

	for (int &rnVal : oIntWrapper)
	{
		printf("%d ", rnVal);
	}

	for (std::string &rStr : oStrWrapper)
	{
		printf("%s ", rStr.c_str());
	}

	printf("\n");
	SAFE_DELETE_ARRAY(pnVals);



	#elif E09_UTILITY_FUNC
	std::vector<int> oValList;
	for (int i = 0; i < 10; ++i)
	{
		oValList.push_back(i + 1);
	}
	printf("\nfor each 함수를 통한 vector 요소 출력 \n");

	std::for_each(oValList.begin(), oValList.end(), [](int a_nVal)->void {
		printf("%d ", a_nVal);
	});
	
	oValList.erase(oValList.begin()+2);
	/*
	백터 반복자는 임의 접근이 가능하기 때문에 만약 vector 요소의 특정 위치게 존재하고 싶다면 
	begin 함수를 통해서 데이터의 첫위치를 가져온 후 포인터연산을 통해서 해당위치를 계산하면된다
	증감연산은 모두 가능하다 
	해당 행위는 vector이기 때문에 할수있는 연산이다
	*/
	#endif//E09_COLLECTION
	}
}