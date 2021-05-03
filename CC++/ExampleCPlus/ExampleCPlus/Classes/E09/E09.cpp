#include "E09.h"

namespace  E09Space
{
#define E09_COLLECTION		1
#define E09_ITERATOR		2
#define E09_UTILITY_FUNC	3

#if E09_COLLECTION
//#define COLLECTION_ARRAY	1
//#define COLLECTION_VECTOR	2
//#define COLLECTION_LIST	3
#define COLLECTION_MAP		4
#define COLLECTION_SET		5
#endif // E09_COLLECTION


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
			//아래가 성능이 더 좋다 
			oValListB.insert(decltype(oValListB)::value_type(oKey, std::to_string(i + 1)));
		}
#elif COLLECTION_SET

#elif E09_ITERATOR
#elif E09_UTILITY_FUNC
	#endif//COLLECTION_VECTOR
	#endif//E09_COLLECTION
	}
}