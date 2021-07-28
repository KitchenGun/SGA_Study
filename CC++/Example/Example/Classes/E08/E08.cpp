#include "E08.h"

//#define E08_STRUCT 1
//#define E08_UNION 2
#define E08_ENUM 3

#if E08_STRUCT
//PLAYER
/*
typedef 키워드를 사용하면 특정자료형의 새로운 이름을 부여하는 것이 가능함 따라서 
기본자료형을 사용할때보다 좀더 제어하는 데이터의 가독성을 높이는 것이 가능하다

ex)
int nPower =0;
typedef int POWER_VALUE;
POWER_VALUE nPower =0;
->유지보수를 이용하여서 사용하는 것이 좋은 습관이다
typedef int POWER_VALUE;
POWER_VALUE nPower =0;
*/
typedef struct _tagE08STPlayer
{
	short m_ID;
	int m_nHP;
	int m_nLevel;
}E08STPlayer;
//레벨업 func
E08STPlayer E08LevelUp(E08STPlayer a_stPlayer)
{
	a_stPlayer.m_nLevel += 1;
	a_stPlayer.m_nHP += 10;
	return a_stPlayer;
}
//플레이어 정보 출력
void E08STPrintPlayerInfo(E08STPlayer a_stPlayer)
{
	printf("플레이 %d 정보 : %d %d \n", a_stPlayer.m_ID, a_stPlayer.m_nLevel, a_stPlayer.m_nHP);
}
#elif E08_UNION
union E08UNData
{
	int m_nData;
	float m_fData;
};
#elif E08_ENUM
//아이템 타입
/*
각 열거형 상수에 값을 지정하지 않을 경우 이전 상수보다 +1씩 증가한 값이 자동으로 부여 된다 
특정 값을 지정하지 않으면 컴파일러에 의해서 중복되지 않는 값을 지니는 상수 선언 가능

종속성을 띄기 위해서 C++11에서 추가된 스코프드 열거형과 언스코프드 열거형으로 구분된다 
핵심은 enum만의 공간이 있다.
기본 c 언어에서 발생하는 중복 상수 에러를 방지하는 것이 불가능 하지만 스코프드 열거형을 사용하면 
특정 상수의 범위를 지정하는 것이 가능하기 때문에 서로 다른 열거형이라면 중복된 상수를 선언하는 것이 가능하다
*/
enum class E08ArraySize
{
	NONE = -1,
	DEF_SIZE = 10,
	MAX_VALUE
};

enum class E08ItemType
{
	NONE=-1,
	GOLD,
	WEAPON,
	MAX_VALUE
};
//무기타입
enum class E08WeaponType
{
	NONE = -1,
	GUN,
	SWORD,
	MAX_VALUE
};

#endif // E08_STRUCT
//타입 재정의
//typedef int INT_32;

void E08(int argc, char ** args)
{
	//타입 재정의
	//INT_32 nValue = 0;
#if E08_STRUCT

	printf("플레이어 구조체 크기%d\n",sizeof(E08STPlayer));
	//구조체의 크기는 컴파일러가 연산을 편하게 하기위해 구조체의 맴버 크기보다 크게 바뀔수있음  이렇게 추가되는 바이트를 패딩바이트라고함 
	//꼭 sizeof를 사용하는 것이 좋은 습관임

	E08STPlayer stPlayerA;
	stPlayerA.m_ID = 1;
	stPlayerA.m_nHP = 10;
	stPlayerA.m_nLevel = 1;
	/*
	구조체 변수 또한 일반 변수처럼 동일하게 초기화값을 지정하는 것이 가능함 
	초기화 순서는 구조체의 맴버선언 순서와 동일
	*/
	E08STPlayer stPlayerB =
	{
		2,25,1
	};

	/*
	구조체는 기본 자료형과 동일한 동작을 하는 것이 가능하기 때문에 해당 구조체를 사용해서 배열을 선언하는 것 또한 가능하다.
	*/

	E08STPlayer astPlayers[] = 
	{
	
		{3,35,1},
		{4,30,1}
		
	};

	int nSelPlayerID = 0;
	do
	{
		printf("레벨업 대상 플레이어 선택 (1or4) : ");
		scanf("%d", &nSelPlayerID);
		if (nSelPlayerID == 1)
		{
			stPlayerA = E08LevelUp(stPlayerA);
		}
		else if(nSelPlayerID==2)
		{
			stPlayerB = E08LevelUp(stPlayerB);
		}
		else if (nSelPlayerID == 3)
		{
			astPlayers[0] = E08LevelUp(astPlayers[0]);
		}
		else if (nSelPlayerID == 4)
		{
			astPlayers[1] = E08LevelUp(astPlayers[1]);
		}
		printf("레벨업 결과 \n");
		E08STPrintPlayerInfo(stPlayerA);
		E08STPrintPlayerInfo(stPlayerB);
		for (int i = 0; i < sizeof(astPlayers) / sizeof(astPlayers[0]); i++)
		{
			E08STPrintPlayerInfo(astPlayers[i]);
		}
		printf("\n");
	} while (nSelPlayerID != 0);


#elif E08_UNION
	E08UNData unData;
	unData.m_nData = 123456789;
	printf("정수 할당 결과\n");
	printf("정수 %d\n",unData.m_nData);
	printf("실수 %f\n", unData.m_fData);
	unData.m_fData = 3.14f;
	printf("실수 할당 결과\n");
	printf("정수 %d\n", unData.m_nData);
	printf("실수 %f\n", unData.m_fData);
#elif E08_ENUM
	//열거형 상수의 값은 컴파일 타임에 확정되기 때문에 해당 상수를 사용해서 배열의 길이를 명시하는 것이 가능하다
	//상수는 런타임에 값이 확정 되기때문에 상수로는 배열의 길이를 명시하는 것이 불가능함
	int anValues[(int)E08ArraySize::DEF_SIZE] = { 0 };

	printf("열거형 상수\n");

	printf("NONE %d\n", E08ItemType::NONE);
	printf("GOLD %d\n", E08ItemType::GOLD);
	printf("WEAPON %d\n", E08ItemType::WEAPON);
	printf("MAX_VALUE %d\n", E08ItemType::MAX_VALUE);

	E08ItemType eItemType = E08ItemType::GOLD;
	/*
	열거형 또한 사용자 정의 자료형이기 때문에 해당 열거형을 사용해서 변수 선언 가능
	*/
	printf("\n열거형 상수 비교 결과\n");
	printf("eItemType==NONE %d\n", eItemType== E08ItemType::NONE);
	printf("eItemType==GOLD %d\n", eItemType== E08ItemType::GOLD);
	printf("eItemType==WEAPON %d\n", eItemType== E08ItemType::WEAPON);
	printf("eItemType==MAX_VALUE %d\n", eItemType== E08ItemType::MAX_VALUE);
#endif // E08_STRUCT


	

}
