#include "E01.h"

//using namespace std;
//using Ű���带 ����ؼ� Ư�� �̸� ������ ����ϸ� �ش���� ������ �����ϴ� 
//�Լ� �������� �ش������ ������� �ʰ� ����ϴ� ���� �����ϴ�
//������ �̸��� �Լ��� �ٸ� �������� ���� �� ���� ���� ��� �̸� �浹�� ���ؼ� �����Ϸ� ������ �߻��ϱ� ������ �ش� ��츦 �����ؾ��Ѵ�.

namespace E01Space
{
	void E01(const int argc, const char ** args)
	{
		int nValue = 10;
		float fValue = 3.14f;

		/*
		c++��� ǥ�� ���̺귯���� std ���� ������ �����Ѵ�
		cout ��ü�� �ܼ�â�� ������ ����� �����Ѵ�
		cin ��ü�� �ܼ�â���� ���� ������ �Է��� �޴� ������ �����Ѵ�
		*/

		std::cout << "Hi" << std::endl;//��û
		std::cout << "nValue " << nValue << " fValue " << fValue << std::endl;

		printf("AAA");//���
		
		std::cout << "\n������ �Է� : ";
		std::cin >> nValue;

		std::cout << nValue << "*" << nValue << "=" <<nValue*nValue<< std::endl;

	
	}
}
