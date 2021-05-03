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
		printf("\nArray int ��� ���\n");

		for (int i = 0; i < oValListA.size(); i++)
		{
			printf("%d ", oValListA[i]);
		}

		printf("\n\nArray string ��� ���\n");

		for (int i = 0; i < oValListB.size(); i++)
		{
			printf("%s ", oValListB[i].c_str());
		}
		
	#elif COLLECTION_VECTOR
		std::vector<int> oValListA;
		std::vector<std::string> oValListB;

		/*
		vector Ŭ������ array Ŭ������ �޸� �������� ���̰� ���ϴ� �迭�� Ŭ����ȭ ��Ų �÷����̱� ������ �ش� Ŭ������ ���ؼ� ��ü�� �������� ��� �⺻������
		�ش� ��ü�� ��� ������ 0�̴� �� ������ ���ÿ� size �Լ��� ȣ������ ��� 0�� ��ȯ�ȴ�

		���� �ش� �÷����� ���̸� �����ϱ� ���ؼ��� ���ο� �����͸� �߰� ��ų �ʿ䰡 ������ �ش� ������ push back �Լ��� ����� ���ν� ó���ϴ� ���� �����ϴ�
		�� push back �Լ��� �Ѱ��� �����͸� �÷��ǿ� ���� �������� �߰��ϴ� ������ �����ϸ� �̶� ���� �÷��ǿ� ���̻� �����͸� �����Ҽ����� ��� �ڵ��������� ������ 
		�÷��ִ� ������ �����Ѵ�

		vector Ŭ������ push back �Լ� �̿ܿ��� insert �Լ��� �����ϸ� �ش� �Լ��� ����ϸ� �÷����� Ư�� ��ġ�� �����͸� �߰��ϴ� ���� �����ϴ�
		�� �����͸� ���� ������ ��ġ�� �߰��Ҷ��� push back �Լ��� ����ϸ� Ư�� ��ġ�� �߰� �Ҷ��� insert �Լ��� ����ϸ� �ȴ�
		*/

		for (int i = 0; i < 10; i++)
		{
			oValListA.push_back(i + 1);
			oValListB.insert(oValListB.begin(),std::to_string(i + 1));
			/*
			vector Ŭ������ ������ ���ÿ� �ε��� �����ڸ� ���ؼ� Ư�� ��ҿ� ������ ��� �߸��� �޸� ���� ������ �߻��Ѵ�
			�̴� �ش� �����ڴ� ����� ���� ������ �ε����� �����ϴ� ���� �����ϱ� ������ �������� �ƹ��� �����Ͱ� �߰� ���� ����
			vector ��ü�� ���̰� 0�̱� ������ �ش� �����ڸ� ����ϴ� ���� �Ұ����ϴ�
			*/
			//oValListA[i] = i + 1;
			//oValListB[i] = std::to_string(i + 1);
		}
		printf("\nVector int ��� ���\n");

		for (int i = 0; i < oValListA.size(); i++)
		{
			printf("%d ", oValListA[i]);
		}

		printf("\n\nVector string ��� ���\n");

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
		list Ŭ������ ���������� ���� ����ũ ������� �����Ǿ��ֱ� ������ vector Ŭ������ �޸� Ư�� ��ҿ� �ѹ��� �����ϴ� ���� ������ ����� �������� �ʽ��ϴ�
		�� [] �ε��� ������ ��� �Ұ���
		���� �ش� �÷����� ��ҿ� �����ϱ� ���ؼ� �ݺ��� �Ǵ� ���� ��� for ���� ����ؾ� �Ѵ�
		�� ù ��� ���� ���������� �����ؾ��Ѵ�
		*/
		printf("\nList int ��� ���\n");

		for (int nVal : oValListA)
		{
			printf("%d ", nVal);
		}

		printf("\n\nList string ��� ���\n");

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
			map �Ǵ� unordered map Ŭ������ Ű ���� ������ �����͸� ó���ϱ� ������ �ش� �÷��ǿ� ���ο� ��Ҹ� �߰� �ϱ� ���ؼ� 
			make pair �Լ� �Ǵ� value type�� ���ؼ� Ű�� ������ �ϳ��� ������ ����� �� �ʿ䰡 �ִ�
			�� Ű�� �����͸� Ž���ϱ� ���� �ĺ��� �뵵�� �ϸ� ������ �ش� �÷��ǿ� �����ϱ� ���� ���� ������ �ǹ��Ѵ�
			*/
			oValListA.insert(std::make_pair(oKey, i + 1));
			//�Ʒ��� ������ �� ���� 
			oValListB.insert(decltype(oValListB)::value_type(oKey, std::to_string(i + 1)));
		}
#elif COLLECTION_SET

#elif E09_ITERATOR
#elif E09_UTILITY_FUNC
	#endif//COLLECTION_VECTOR
	#endif//E09_COLLECTION
	}
}