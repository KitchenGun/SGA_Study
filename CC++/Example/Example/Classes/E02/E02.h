#pragma once

#include"../Global/Define/KGDefine.h"

//�ڷ��� = �����͸� �ν��ϴ� or �ؼ� ���
//����ڴ� �ڷ��� ���ؼ� ��ǻ�Ͱ� �ؼ������ ���� ������Ѵ�
/*
����		����Ʈ
short	 2
int		 4
long	 4 or 8 
longlong 8
�Ǽ�
float	 4
double   8
����
char	 1

���� = �Ҽ����� ���� �� ǥ��
�Ǽ� = �Ҽ����� �����ϴ� ���� ǥ��
���� = �� ���� ǥ��

������ �����͸� �����Ҽ��ִ� �����ǹ�

c��� ���� ���� ���
�ڷ��� + ���� �̸�
ex) 
int nValueA;
short nValueB;

����� ������ �޸� �����͸� ����ϸ� ���� �Ұ��� ����� �ʿ��� ���� �о���̴� ������ �����ϴ�
const + �ڷ��� + ����̸�
ex)
const int nValueA(�ɺ���) = 0(���ͳ� ���)
�̸��� �����ϴ� �ɺ��� ���
�̸��� ���������ʴ� ���ͳ� ���
*/
//ex) 1�� �������ΰ� ���� ���ΰ�
//Example 2
void E02(int argc, char **args);