#include "MapMemberManager.h"

void CMapMemManager::InsertMember()
{
	oMemList.insert(decltype(oMemList)::value_type(oMemList.size(), CMember::InsertMem()));
}

void CMapMemManager::DeleteMember(CMember a_oMem)
{ 
	std::string strName;
	printf("\n���� �� ȸ�� �̸� �Է� : ");
	std::cin >> strName;
	a_oMem.SetName(strName);

	printf("\n===== ȸ�� ���� ��� =====\n");
	for (auto oIterator = oMemList.begin(); oIterator != oMemList.end(); ++oIterator)
	{
		if (oIterator->second.GetName() == a_oMem.GetName())
		{
			printf("%s(��)�� �����߽��ϴ�.\n", oIterator->second.GetName().c_str());
			oMemList.erase(oIterator);
			break;
		}
	}
}

void CMapMemManager::SearchMember(CMember a_oMem)
{
	std::string strName;
	printf("\n�˻� �� ȸ�� �̸� �Է� : ");
	std::cin >> strName;
	a_oMem.SetName(strName);

	printf("\n===== ȸ�� �˻� ��� =====\n");
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
	printf("\n===== ��� ȸ�� ���� =====\n");
	for (auto oIterator = oMemList.begin(); oIterator != oMemList.end(); ++oIterator)
	{
		oIterator->second.Print();
	}
}

void CMapMemManager::PrintMenu()
{
	printf("\n===== �޴� =====\n");
	printf("1. ȸ�� �߰�\n");
	printf("2. ȸ�� ����\n");
	printf("3. ȸ�� �˻�\n");
	printf("4. ��� ȸ�� ���\n");
	printf("5. ����\n");
}

CMapMemManager::CMapMemManager()
{
	//do nothing
}

CMapMemManager::~CMapMemManager()
{
	//do nothing
}
