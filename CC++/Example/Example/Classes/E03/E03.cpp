#include "E03.h"

/*
�����ڶ�?
�����͸� �����ϱ� ���� Ư���� �ǹ̸� ���ϴ� ��ȣ�� ������
�����ڸ� ����ϸ� Ư�� �����͸� ���α׷��� ������ �°� �����ϴ� ���� �����ϴ�

C��� �������� ����
�������
+-/%*
�Ҵ翬����
= += -= *=
�� ������
== >= <= != < >
�� ������
&& || !
���� ������
++ --
��Ʈ������
& | ^(�ͽ��𸣽ú� 0,0->true 1,1 -> fales) ~(��Ʈ ���� 0->1 1->0) >>(shift ������) <<()
���� ������ 
? :
*/

void E03(int argc, char **args)
{
	int nValueA=0;
	int nValueB=0;
	//0�� ���� ���������� ���̴�
	printf("����(2�� �Է�) : ");
	scanf("%d %d", &nValueA, &nValueB);
	printf("���\n");
	printf("%d + %d = %d\n", nValueA, nValueB, nValueA + nValueB);
	printf("%d - %d = %d\n", nValueA, nValueB, nValueA - nValueB);
	printf("%d * %d = %d\n", nValueA, nValueB, nValueA * nValueB);
	printf("%d / %d = %f\n", nValueA, nValueB, (float)nValueA / nValueB);
	printf("%d %% %d = %d\n", nValueA, nValueB, nValueA % nValueB);
	printf("�񱳿�����\n");
	printf("%d != %d =%d\n", nValueA, nValueB, nValueA != nValueB);
	printf("%d == %d =%d\n", nValueA, nValueB, nValueA == nValueB);
	printf("%d >= %d =%d\n", nValueA, nValueB, nValueA >= nValueB);
	printf("%d <= %d =%d\n", nValueA, nValueB, nValueA <= nValueB);
	printf("%d > %d =%d\n", nValueA, nValueB, nValueA > nValueB);
	printf("%d < %d =%d\n", nValueA, nValueB, nValueA < nValueB);
	printf("��������\n");
	printf("%d && %d =%d\n", nValueA, nValueB, nValueA && nValueB);
	printf("%d || %d =%d\n", nValueA, nValueB, nValueA || nValueB);
	printf("!%d =%d\n", nValueA,!nValueA);
	printf("����������\n");//�� �Ǵ� �ڿ� ��� ����
	printf("++%d --%d\n", ++nValueA, --nValueB);//���� ���� �� ���� �� ���� 
	printf("%d++ %d--\n", nValueA++, nValueB--);//���� ���� �� ���� �� ����
	printf("���� ���� ��� %d %d\n", nValueA, nValueB);
	/*
	%x 16������ ������ ����ϱ� ���� ���Ĺ����̴� �빮�ڷ� ���Ĺ��ڸ� �ۼ��ϸ� ����� �빮�ڷ� ���´�
	*/
	printf("��Ʈ������\n");
	printf("%x & %x =%x\n", nValueA, nValueB, nValueA & nValueB);
	printf("%x | %x =%x\n", nValueA, nValueB, nValueA | nValueB);
	printf("%x ^ %x =%x\n", nValueA, nValueB, nValueA ^ nValueB);//�ΰ��� �ٸ��� �� ������ ����  0010 1000 -> 1010
	printf("~%x = %d\n", nValueA, ~nValueA +1);// 2�� �������� ���ؼ� ������ ǥ���� ��Ʈ ���� +1
	printf("%x << 2 =%x\n", nValueA, nValueA << 2);//0�� �� 0���� ����
	printf("%x >> 2 =%x\n", nValueB, nValueB >> 2);
	printf("���ǿ�����\n");//���� ������
	printf("(%d < %d) ? : = %d\n", nValueA, nValueB, nValueA < nValueB ? nValueA : nValueB);
	printf("�Ҵ� ������\n");
	nValueA += 5;
}