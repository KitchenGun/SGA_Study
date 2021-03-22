#include "E02.h"

/*
#define ��ɾ ����ϸ� ��ó���⿡ ���ؼ� ó���Ǵ� ��� ���� ����
�ش����� ���ؼ� ������ ����� ��ũ�� ��������  �����Ϸ� ���忡�� ���ͷ� ���
*/
//#define E02_VARIABLE			1
#define E02_DATA_INPUT_OUTPUT	2


void E02(int argc, char ** args)
{
#if E02_VARIABLE
	/*
	�ڷ��� + �����̸��� ���ؼ� ������ �����ϰ� �ʿ�� ���� ������ ������ �� ������ ������ �ʱ�ȭ�����
	c��� ���� �̸� �ۼ� ��Ģ
	�⺻������ ������ �̸��� ���ĺ�(��/�ҹ���),����,_(��� ���ھ�)�� ������ ���ؼ� �ۼ��� �����ϸ� ù���ڿ��� ���ڻ���� �Ұ����ϴ�.
	c�����Ϸ��� ��ҹ��� ���� ����
	ex)
	int a;
	int A;
	c�����Ϸ��� �ش� ������ ���� �ٸ� ������ �ν��Ѵ�
	�����̸��� �ߺ� ��� X
	*/

	short nShort = 10;
	int nInt = 20;
	long nLong = 30;
	long long nLongLong = 40;
	float fFloat = 3.14f;
	double dblDouble = 3.14;
	char chLetter = 'A';
	/*
	printf �Լ��� ���� ���ڸ� Ȱ���ؼ� Ư�� �����͸� ����ϴ� ���� �����ϴ�
	
	printf �Լ� ���� ������ ����
	//����
	%d		==short,int
	%ld		==long
	%lld	==long long
	//�Ǽ�
	%f		==float
	%lf		==double
	//������
	%c		==char
	//���Ĺ��ڸ� ����Ҷ��� �ݵ�� ġȯ��ų �������� �ڷ����� ���缭 ���Ĺ��ڸ� ���������Ѵ�

	*/



	printf("������ ���\n");
	printf("short %d:%d\n", sizeof(nShort), nShort);
	printf("int %d:%d\n", sizeof(nInt), nInt);
	printf("long %d:%ld\n", sizeof(nLong), nLong);
	printf("long long %d:%lld\n", sizeof(nLongLong), nLongLong);
	printf("�Ǽ��� ���\n");
	printf("float %d:%f\n", sizeof(fFloat), fFloat);
	printf("double %d:%lf\n", sizeof(dblDouble), dblDouble);
	printf("������ ���\n");
	printf("char %d:%c\n", sizeof(chLetter), chLetter);

#elif E02_DATA_INPUT_OUTPUT
	int nValueA = 0;
	int nValueB = 0;
	printf("����(2�� �Է�) : ");
	scanf("%d %d", &nValueA, &nValueB);
	//scanf�� ���Ĺ��ڿ� ���鸸 ����� �����ϰ� ���� �������� ���Ŀ� ���缭 ���� �ʿ�  scanf�� �����Լ��⶧���� �ּҰ��� �޾ƾ��Ѵ�
	//�ش����� ���� �ϸ� �ٸ� �����Ϸ������� scanf ��밡�� scanf_s�� ���־� ��Ʃ��� �����Ϸ������� ��밡���ϴ�	
	printf("%d + %d = %d\n", nValueA, nValueB, nValueA + nValueB);
	printf("%d - %d = %d\n", nValueA, nValueB, nValueA - nValueB);
	printf("%d * %d = %d\n", nValueA, nValueB, nValueA * nValueB);
	printf("%d / %d = %f\n", nValueA, nValueB, (float)nValueA / nValueB);
	//�ǿ����ڸ� 2���̻�䱸�ϴ� ��� ���� �����ڸ� ������� ��� �ǿ������� �ڷ����� ��ġ�ؾ��Ѵ�
	//�ຯȯ�� �ؼ� ����� �ٲ۴� �ϳ��� �ٲ㵵 �Ϲ����� ����ȯ(����������ȯ) �߻� ���� �ս��� �� �߻��ϴ� �������� �����
	printf("%d %% %d = %d\n", nValueA, nValueB, nValueA % nValueB);
#endif // E02_VARIABLE
}
