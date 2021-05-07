#include "E09.h"

namespace  E09Space
{
//#define E09_COLLECTION		1
//#define E09_ITERATOR		2
//#define E09_UTILITY_FUNC	3
#define E09_THREAD			4


#if E09_COLLECTION
//#define COLLECTION_ARRAY	1
//#define COLLECTION_VECTOR	2
//#define COLLECTION_LIST	3
//#define COLLECTION_MAP	4
#define COLLECTION_SET		5
#endif // E09_COLLECTION
#if E09_COLLECTION
#if COLLECTION_SET
	//���ڿ��� ���� ���θ� �˻��Ѵ�
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
	//���ͷ����� ����
	template <class T>
	class CIteratorWrapper
	{
	public:
		//ù ������ġ�� ��ȯ�Ѵ�
		T *begin(void)
		{
			return m_ptVals;
		}
		//���� ��ġ�� ��ȯ�Ѵ�
		T * end(void)
		{
			return m_ptVals + m_nNumVals;
		}

	public://������
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
#elif E09_THREAD
	
	static std::mutex g_oMutex;

	//ī���� Ŭ����
	class CCounting
	{
	public:

		//ī��Ʈ ��ȯ
		int GetCount(void) const
		{
			return m_nCounting;
		}
		//ī��Ʈ ����
		void StartCounting(int a_nCounting)
		{
			/*
			lockguard Ŭ������ ����ϸ� �����ڿ� �Ѱ��� ����ȭ ��ü�� �ڵ������� �����ϴ� ���� �����ϴ� 
			�� lockguard Ŭ������ �����ڰ� ȣ��Ǹ� �ش� ����ȭ ��ü�� lock �Լ��� ȣ���ϸ�
			�Ҹ��ڰ� ȣ��Ǿ����� unlock�Լ��� ȣ�������ν� ���� �����ϰ� ����ȭ ó���ϴ� ���� �����ϴ�
			
			���� Ư�� ����ȭ ��ü�� lock �Լ��� ȣ���� ���¿��� unlock �Լ��� ȣ������ ���� ���
			�̴� Ư�� �����尡 �ش� ����ȭ ��ü�� �ڿ��� ������ ����ϴ� ����� ������ ���߽�Ų��
			*/
			std::lock_guard<std::mutex> oLockGuard(g_oMutex);
			//os���� �������ִ� ��ü(���ñ����� �̿��ؼ� �����ڿ� �Ҹ��ڿ� ������ ����ȭ�� ������������ ����)

			//g_oMutex.lock();
			for(int i =0;i < a_nCounting;++i)
			{
				m_nCounting += 1;
			}
			//g_oMutex.unlock();//Ư�� ������ �������� ������ ����������̶���� 
		}
	private://����
		int m_nCounting=0;
	};

	static CCounting g_oCounting;

	//���� �����带 �����Ѵ�
	void StartSubThread(void)
	{
		for (int i = 0; i < 10000; ++i)
		{
			printf("subthread\n");
		}
	}
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
			//std::pair<int,int>�� ��ȯ������ ����Ͽ��� �������� �����͸� �ѱ���ִ�. 
			//�Ʒ��� ������ �� ���� make pair�� ���������� ���縦 �ؼ� �׷���
			oValListB.insert(decltype(oValListB)::value_type(oKey, std::to_string(i + 1)));
			/*
			decltype Ű���带 ����ϸ� �ش�Ű���� ()�ȿ� ��õ� ǥ�������� �����Ϸ��� �ڷ����� �߷�������
			�ش� Ű���带 ����ϸ� mapŬ������ �����͸� �����ϱ� ���� �ڵ带 ���� ��� ��Ű�� ���� �����ϴ�
			
			�Ϲ����� map Ŭ������ �����͸� �߰��Ҷ��� make_pair ��뺸�� value type�� ����ϴ� ���� 
			���������� ���ʿ��� ���簡 �߻����� �ʱ� ������ ���� �����ս��� ����
			auto�� ����ÿ��� ����Ҽ��ִ�. 
			*/
		}
		printf("\nmap ��� ���\n");
		for (auto stKeyVal : oValListA)
		{
			printf("[%s] %d ", stKeyVal.first.c_str(), stKeyVal.second);//first �� Ű second ���� �ǹ��Ѵ� 
		}
		//for (int i = 0; i < oValListA.size(); i++)
		//{
		//	std::string oKey = std::to_string(i + 1);
		//	printf("[%s] %d ", oKey.c_str(), oValListA[oKey]);
		//}
		/*
		map and unordered map �� ���� ���� �̱⶧���� �ش� �÷��ǿ� ����Ǿ��ִ� �������� ������ �ش� �����͸� �߰� �� �����ʹ� �������
		���� Ư�� ��Ģ�� �°� �����͸� ��ȸ�ϱ� ���ؼ��� �ش� ��Ģ�� �´� ������ Ű�� �����ؼ� ������ ��ȸ�� �õ��ؾ��Ѵ� 
		*/
		printf("\nunordered_map ��� ���\n");
		for (auto stKeyVal : oValListB)
		{
			printf("[%s] %s ", stKeyVal.first.c_str(), stKeyVal.second.c_str());
		}
		printf("\n");
		/*
		�ݷ����� Ư�� �����͸� �����ϰ� ���� ��� erase �Լ��� ����ϸ� �ȴ� 
		�ش� �Լ��� �÷����� ������������ ���� ���� ������ ���� �䱸�ϴ� �Ű������� �ٸ��� 
		���� �÷���(vector list)�� ��� �ݺ��ڸ� �䱸�ϸ�
		���� ����(map unordered map)�� Ű�� �Ű� ������ �䱸�Ѵ� 
		*/
		oValListA.erase("5");//Ű�� 5�� ������ ����
		oValListB.erase("10");

		printf("\n������ ������ map ��� ���\n");
		for (auto stKeyVal : oValListA)
		{
			printf("[%s] %d ", stKeyVal.first.c_str(), stKeyVal.second);
		}
		printf("\n");
		printf("\n ������ ������ unorder_map ��� ���\n");
		for (auto stKeyVal : oValListB)
		{
			printf("[%s] %s ", stKeyVal.first.c_str(), stKeyVal.second.c_str());
		}
		printf("\n");

	#elif COLLECTION_SET
		/*
		set�� ������ Ư¡�� ������ �÷����̱� ������ �ش� �÷��ǿ� ����Ǵ� �������� �ߺ��� ������� �ʴ´�.

		�������� �ߺ��� �����Ҷ� ��� ex �ߺ� ���ڿ� ã��
		*/
		srand((unsigned int)time(NULL));
		std::set<int>oValList;
		for (int i = 0; i < 10; i++)
		{
			oValList.insert(rand() % 10);
		}

		printf("\n==set ��� ���\n");

		for (int nVal : oValList)
		{
			printf("%d ",nVal);
		}

		char szStr[100] = "";
		printf("\n\n���ڿ� �Է� : ");
		fgets(szStr, sizeof(szStr), stdin);
		//���๮�ڰ� �����Ұ��
		if (szStr[strlen(szStr) - 1] == '\n')
		{
			szStr[strlen(szStr) - 1] = '\0';
		}
		printf("���� ���� : %d\n", IsUniqueStr(szStr));


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
	printf("�ݺ��ڸ� ���� vector ��� ��� \n");
	/*
	�ݺ��ڸ� ���� Ư�� �÷����� ��ȸ�ϱ� ���ؼ��� �ش� �÷����� �����ϴ� begin�Լ��� ���ؼ� 
	���� ù �����͸� ����Ű�� �ݺ��ڸ� ���� �� end�Լ��� �����ϴ� ����
	��ġ���� ���� ���� �ݺ� ������ �����ϸ� �ȴ�

	�� stl�� ��� �÷����� �ݺ��� ���۰� ���� ��Ÿ���� begin end �Լ��� �����Ѵ�

	�ݺ��ڴ� �÷����� ��� �߿� Ư�� ��ġ�� ����Ű�� ������ ��ü�̱� ������ �ش� ��ü�� ���ؼ� �÷����� ��ҿ� �����ϱ� ���ؼ��� 
	*������ �����ڶǴ� ->������ �ɹ� ���������ڸ� ����ؾ��Ѵ�
	*/
	for (auto oIterator = oValListA.begin(); oIterator != oValListA.end(); ++oIterator)
	{
		printf("%d ", *oIterator);
	}
	printf("�ݺ��ڸ� ���� unordered map ��� ��� \n");
	for (auto oIterator = oValListB.begin(); oIterator != oValListB.end(); ++oIterator)
	{
		printf("[%s] %d ", oIterator->first.c_str(),oIterator->second);
	}

	int *pnVals = new int[10];
	std::string *poStrs = new std::string[10];
	
	CIteratorWrapper<std::string> oStrWrapper(poStrs, 10);
	CIteratorWrapper<int> oIntWrapper(pnVals, 10);
	/*
	�������� �Ҵ�� �迭�� ������� ������� for ���� ����ϱ� ���ؼ��� �ݺ��� �������̽��� �����ϴ� Ŭ������ �����ؾ��Ѵ�
	�� begin�� end�Լ��� ���ϴ� Ŭ������ ����� �����ؾ���

	���� ���� ��� for ���� �����Ϸ��� ���ؼ� ���������� �ݺ��ڸ� Ȱ���� �ڵ�� ������ �ȴٴ� ���� �˼��ִ�.
	*/
	for (int &rnVal : oIntWrapper)
	{
		rnVal = rand() % 10;
	}
	for (std::string &rStr : oStrWrapper)
	{
		rStr = std::to_string(rand() % 10);
	}

	printf("\n\nĿ���� ���� ��� for�� ���\n");

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
	printf("\nfor each �Լ��� ���� vector ��� ��� \n");

	std::for_each(oValList.begin(), oValList.end(), [](int a_nVal)->void {
		printf("%d ", a_nVal);
	});
	
	/*
	���� �ݺ��ڴ� ���� ������ �����ϱ� ������ ���� vector ����� Ư�� ��ġ�� �����ϰ� �ʹٸ� 
	begin �Լ��� ���ؼ� �������� ù��ġ�� ������ �� �����Ϳ����� ���ؼ� �ش���ġ�� ����ϸ�ȴ�
	���������� ��� �����ϴ� 
	�ش� ������ vector�̱� ������ �Ҽ��ִ� �����̴�
	*/
	oValList.erase(oValList.begin()+2);
	/*
	find�Լ��� ����ϸ� Ư�� �÷��ǿ� �����ϴ� �������� ���翩�θ� Ž���ϴ� ���� �����ϴ�
	�ش� �Լ��� ���� Ž���ϰ����ϴ� ���� �÷��� ���ο� ������ ��� �ش� ��ġ�� ����Ű�� �ݺ��ڰ� ��ȯ�Ǹ�
	�������� �ʴ´ٸ� end �ݺ��ڰ� ��ȯ�ȴ�
	�� �ش� �Լ� ����� end �ݺ��ڿ� �������ν� �������� ���翩�θ� �˻��ϴ� ���� �����ϴ�.
	*/
	auto oIteratorA = std::find(oValList.begin(), oValList.end(), 5);
	//���� �� ���� ������ ���
	if (oIteratorA != oValList.end())
	{
		oValList.erase(oIteratorA);
	}

	printf("\n 5 ������ vector ��� ��� \n");

	std::for_each(oValList.begin(), oValList.end(), [](int a_nVal)->void {
		printf("%d ", a_nVal);
	});

	/*
	find if �Լ� ���� find �Լ��� ���� �÷��ǿ� Ư�� �����͸� Ž���ϴ� ������ �����Ѵ�
	�� �ش� �Լ��� �÷��� ���ο� �����ϴ� �����͸� ���ϴ� �Լ��� ���� ��������ν� 
	����� ���� �ڷ����� ���� �����͸� ���Ҷ� ����ڰ� ���ϴ� �������� �����͸� Ž���ϴ� ����
	�����ϴ�
	*/
	auto oIteratorB = std::find_if(oValList.begin(), oValList.end(), [](int a_nVal)->bool {
		return a_nVal == 15;
	});

	//������ ���� ������ ���
	if (oIteratorB != oValList.end())
	{
		oValList.erase(oIteratorB);
	}
	printf("\n15���� ��  �Լ��� ���� vector ��� ��� \n");

	std::for_each(oValList.begin(), oValList.end(), [](int a_nVal)->void {
		printf("%d ", a_nVal);
	});

	/*
	�������� �Ҿ��� ����
	*/
	//�Ҿ��� ����
	//std::sort
	//���� ����
	//std::stable_sort
	/*
	c++���� Ư�� �÷����� ��Ҹ� �����ϱ� ���� sort �Լ��� stable sort �Լ��� �����Ѵ�
	sort �Լ��� ���������� ������ �˰������� �Ǿ��ֱ� ������ �Ҿ��� ������ �����ϸ� stable sort �Լ��� 
	���������� ���� ���� �˰������� �Ǿ��ֱ� ������ ���� ������ �����Ѵ�

	���� �����̶�?
	-Ư�� �����͸� ���Ľ�Ű�� ���� ������ ���� �Ǿ��ִ� ������ �����Ҽ��ִٸ� �̸� ���������̶�� �Ѵ�
	*/

	std::sort(oValList.begin(), oValList.end(), [](int a_nLhs, int a_nRhs)->bool{
		return a_nRhs < a_nLhs;
	});
	printf("\n�������� ������ vector ��� ��� \n");

	std::for_each(oValList.begin(), oValList.end(), [](int a_nVal)->void {
		printf("%d ", a_nVal);
	});

	#elif E09_THREAD
	/*
	thread Ŭ������ ����ϸ� ���� ������ �̿ܿ� ������ �����带 �����ϴ� ���� �����ϴ�
	
	thread��?
	cpu�� ���α׷��� �����ϱ� ���� �ð��� �Ҵ�޴� �⺻���� 
	�⺻������ ��� ���α׷��� cpu�� ���ؼ� �ش� ���α׷��� ���ϰ� �ִ� ��ɾ �ؼ��Ǿ����� ���α׷��� �����Ѵ�
	�̶� cpu�� ������ ������� Ư�� ���α׷��� ��ɾ �ؼ��ϱ� ���� �ð��� �־����� 
	���� �� �����带 ���α׷��� ������ ������ �ִٸ� ���ÿ� ���� ��ɾ� ó���ϴ°��� �����ϴ� 
	�� ��� ���α׷��� ����� ���ÿ� �����尡 �����Ǹ� �ش� �����带 ���� �������� �Ѵ�
	*/
		std::thread oThreadA(StartSubThread);
		std::thread oThreadB([](void)->void 
		{
			g_oCounting.StartCounting(1000000); 
		});
		std::thread oThreadC([](void)->void 
		{
			g_oCounting.StartCounting(1000000); 
		});
		for (int i = 0; i < 10000; ++i)
		{
			printf("main\n");
		}
		oThreadA.join();//������ a �� ����Ǳ� ��ٸ���
		oThreadB.join();
		oThreadC.join();

		printf("\nī���� �Ϸ���\n");
		printf("%d \n", g_oCounting.GetCount());
		/*
		thread ��ü�� join�Լ��� ����ϸ� �ش� thread ����� ���� ���
		c++�� ���ξ����尡 ����Ǳ� ���� �ݵ�� ���� �������� ���ᰡ �Ϸ�Ǿ���ϰ� 
		�� ��Ģ�� �������� ���� ��� ���α׷��� ���۵� �ϰų� ũ���ð� �߻��Ѵ�
		
		���� ���� �����忡���� ������ ���� �����带 �����������
		���� �������� ������ ��� �����ϰ� ���� �ݵ�� ���� �������� ���Ḧ ����ؾ��Ѵ�
		*/
	#endif//E09_COLLECTION
	}
}