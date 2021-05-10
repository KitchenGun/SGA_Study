#include "MapMemberManager.h"

void CMapMemManager::InsertMember()
{
	oMemList.insert(decltype(oMemList)::value_type(oMemList.size(), CMember::InsertMem()));
}

void CMapMemManager::DeleteMember(CMember a_oMem)
{ 
	std::string strName;
	printf("\n삭제 할 회원 이름 입력 : ");
	std::cin >> strName;
	a_oMem.SetName(strName);

	printf("\n===== 회원 삭제 결과 =====\n");
	for (auto oIterator = oMemList.begin(); oIterator != oMemList.end(); ++oIterator)
	{
		if (oIterator->second.GetName() == a_oMem.GetName())
		{
			printf("%s(을)를 삭제했습니다.\n", oIterator->second.GetName().c_str());
			oMemList.erase(oIterator);
			break;
		}
	}
}

void CMapMemManager::SearchMember(CMember a_oMem)
{
	std::string strName;
	printf("\n검색 할 회원 이름 입력 : ");
	std::cin >> strName;
	a_oMem.SetName(strName);

	printf("\n===== 회원 검색 결과 =====\n");
	for (auto oIterator = oMemList.begin(); oIterator != oMemList.end(); ++oIterator)
	{
		if (oIterator->second.GetName() == a_oMem.GetName())
		{
			oIterator->second.Print();
		}
	}
}

void CMapMemManager::PrintAll()
{
	printf("\n===== 모든 회원 정보 =====\n");
	for (auto oIterator = oMemList.begin(); oIterator != oMemList.end(); ++oIterator)
	{
		oIterator->second.Print();
	}
}

void CMapMemManager::PrintMenu()
{
	printf("\n===== 메뉴 =====\n");
	printf("1. 회원 추가\n");
	printf("2. 회원 삭제\n");
	printf("3. 회원 검색\n");
	printf("4. 모든 회원 출력\n");
	printf("5. 종료\n");
}

CMapMemManager::CMapMemManager()
{
	//do nothing
}

CMapMemManager::~CMapMemManager()
{
	//do nothing
}
