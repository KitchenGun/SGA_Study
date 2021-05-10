#include "VectorMemberManager.h"

void CVecMemManager::InsertMember()
{
	oMemList.push_back(CMember::InsertMem());
}

void CVecMemManager::DeleteMember(CMember a_oMem)
{
	std::string strName;
	printf("\n���� �� ȸ�� �̸� �Է� : ");
	std::cin >> strName;
	a_oMem.SetName(strName);

	printf("\n===== ȸ�� ���� ��� =====\n");
	for (auto oIterator = oMemList.begin(); oIterator != oMemList.end(); ++oIterator)
	{
		if (*oIterator == a_oMem)
		{
			printf("%s(��)�� �����߽��ϴ�.\n", oIterator->GetName().c_str());
			oMemList.erase(oIterator);
			break;
		}
	}
}

void CVecMemManager::SearchMember(CMember a_oMem)
{
	std::string strName;
	printf("\n�˻� �� ȸ�� �̸� �Է� : ");
	std::cin >> strName;
	a_oMem.SetName(strName);

	printf("\n===== ȸ�� �˻� ��� =====\n");
	for (auto oIterator = oMemList.begin(); oIterator != oMemList.end(); ++oIterator)
	{
		if (*oIterator == a_oMem)
		{
			oIterator->Print();
		}
	}
}

void CVecMemManager::PrintAll()
{
	printf("\n===== ��� ȸ�� ���� =====\n");
	for (CMember mem : oMemList)
	{
		mem.Print();
	}
}

void CVecMemManager::PrintMenu()
{
	printf("\n===== �޴� =====\n");
	printf("1. ȸ�� �߰�\n");
	printf("2. ȸ�� ����\n");
	printf("3. ȸ�� �˻�\n");
	printf("4. ��� ȸ�� ���\n");
	printf("5. ����\n");
}

CVecMemManager::CVecMemManager()
{

}

CVecMemManager::~CVecMemManager()
{

}