#pragma once


#include "../Global/Define/KGDefine.h"

/*
STL�̶�?
c++���� �����ϴ� ���ø����� �̷���� ǥ�� ���̺귯���� �ǹ��Ѵ� �� �ش� ���̺귯���� ����ϸ� ���α׷��� �����ϴµ� �־ 
�̸� ������� ���� ����� Ȱ���Ҽ��ֱ⿡ ���� �Ⱓ�� �����ϴ� ���� �����ϴ� 

c++ STL�� �ֿ� ���
-�÷���		(�뷱�� ����Ž�� Ʈ��) (�ؽ����̺�)
array vector list   map        unordered_map set
array�� ���� ũ�� �迭�̴�(c++11�� �߰�)
vector ���� ũ�� �迭�̴�
list array vector ���� �����̴�.
������ ��������
map�� ��� Ž���� �־ǰ� �ּ��� ��� �ӵ��� ���������    
����  Ʈ���� ������ �����ϱ����ؼ� �߰����� ������ �ʿ��ϴ� 
unordered map�� �汹 �־ǰ� �ּ��� �ӵ��� �ſ� �ٸ��ϴ�   
���� �콬�Լ��� ��ġ�� ���̺��� ���� �ؽ����� ���� �����Ͱ� ������ ������ �浹(Ŭ����������)�� �߻��ؼ� �˻��ð��� �þ��

map vs unordered_map 

=map�� ���������� �뷱�� ���� Ž�� Ʈ���� �����Ǿ��ֱ� ������ �ּ��� ���� �־��� ���� ����� log  n�� Ž�������� �����Ѵ� 
�� ���������� Ʈ���� ������ �������� ���� �����ϱ� ���ؼ� Ư�� ������ ���� ���� ���� �� Ʈ�� ������ ȸ���ϱ� ���� �߰����� ������ �߻��Ѵ�

=unordered map�� ���������� �ؽ� ���̺��� �����Ǿ��ֱ� ������ �ּ��� ��� 0 1 ��� �ð��� Ž���� �����Ѵ� �� Ư�� �����Ͱ� �ؽ� ���̺���
Ư�������� �����ϴ� Ŭ������ ������ �߻��Ұ�� Ž���� ������ �������� ������ �־��� ��� 0�� Ž�� �ð��� �ʿ��ϴ�
(������ �̷� ���� ���� �幮���̰� �Ϲ������� map���� ������) c# ��Ǿ�� ���� �迭

set �������� �̴�.
-�ݺ���
-��ƿ��Ƽ �Լ�
sort find....

�÷����̶�?
2�� �̻��� �����͸� ȿ�������� ���� �Ҽ��ִ� ����� �����ϴ� Ŭ���� ������ �ǹ��Ѵ�
�� ���α׷��� �����Ҷ� ��Ȳ�� �´� �÷����� ����ϸ� �ټ��� �����͸� ���� ������ϴ�

���� ������ �迭�� �÷��ǿ� �Ϻ��̴�.

Iterater
Enumerator 
�ݺ��ڶ�? 
�÷����� Ư�� �����ͶǴ� ��ġ�� ����Ű�� ������ó�� �����ϴ� ��ü�� �ǹ��Ѵ�
�� ����Ʈ �����ʹ� �ƴϴ�
�ݺ��ڸ� ����ϸ� �÷��� ���� ����� �������� �ش� �÷��ǿ� �����ϴ� �����͸� �����ϴ°��� �����ϴ� 


�̵� �����ڶ�?  Move semantics
������ C++�� ������ �ִ� �ٺ����� ������ �ذ��ϱ� ���ؼ� ���Ӱ� ������ �������� �������ν� �ش� �����ڸ� ����ϸ� 
�̵� �ø�ƽ�� �����ϴ� ���� �����ϴ�. 
�� �ش� �����ڸ� ��������� ���ʿ��� ��ü�� ���縦 �����ϴ� ���� �����ϴ�


STL�� ����ϸ� �޸� ����ȭ�� �߻��Ѵ� �̰� �ذ��ϱ����ؼ� ���α׷��� ��������
�𸮾��� �𸮾� ���� �÷����� �ִ� ���� ����! 
STL�� �ӵ����� ���뼺�� ������ �׷��� �����ʴ� ����� �� �־ ������ 
*/
namespace E09Space
{
	void E09(const int argc, const char **args);
}