#include "E01/E01.h"

/*
���� �Լ��� c ���� �ۼ��� ���α׷����� ���� ó������ ����Ǵ� �Լ��� �ǹ��Ѵ�. 
�� ���� �Լ��� �����ؾ����� ���α׷��� ���� ��ġ�� ��ǻ�Ͱ� �˼��ֱ⶧���� �ش��Լ��� �ݵ�� ����
�����Լ� ����� ���α׷� ���� ����Ǳ� ������ �ش��Լ��� ���α׷��� �����Լ��� �Ѵ�.
�����Լ� ���� == ���α׷� ����
�����Լ� ���� == ���α׷� ����
c��� �����Լ��� ����
x�ǹ� : main�Լ���ü�� �Է¾��� ��� return �� ����
input o output o int main(int,char**)
input o	output x void main(int, char**)
input x	output o int main(void)
input x	output x void main(void)
*/
int main(int argc, char **args)
{
	E01(argc, args);
	return 0;
}