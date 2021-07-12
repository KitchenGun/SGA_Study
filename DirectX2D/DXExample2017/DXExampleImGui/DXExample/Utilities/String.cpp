#include "stdafx.h"
#include "String.h"

void String::SplitString(vector<string>* result, string origin, string tok)//Ư�� ���ڸ� �������� ���ڿ� �ڸ���
{
	result->clear();

	int cutAt = 0;//�ڸ� ��ġ �ε���
	
	//���ڿ� origin���� tok�� ������ ���� ù��° ������ �ε����� cutat�� �ְ� while�� ����
	//ã�� ���ڿ��� ���� ��� ������
	//find_first_of(tok)�� ����� ��°�� ������ ��ū�� ���ִ� ���ڿ��� �����ϴ� �����ϳ��� �߰ߵǸ� ����ġ�� ���� ��ȯ�Ѵ�
	//npos == -1�� ���
	while ((cutAt = (int)origin.find_first_of(tok)) != origin.npos)//������ �켱���������� �̷��� �ۼ���
	{
		if (cutAt > 0)
			result->push_back(origin.substr(0, cutAt));
		//���������� �ڸ��κ��� �����ϰ� �־��ش�
		origin = origin.substr(cutAt + 1);
	}
	if (origin.length() > 0)
		result->push_back(origin.substr(0, cutAt));
}

void String::SplitString(vector<wstring>* result, wstring origin, wstring tok)
{
	result->clear();

	int cutAt = 0;
	while ((cutAt = (int)origin.find_first_of(tok)) != origin.npos)
	{
		if (cutAt > 0)
			result->push_back(origin.substr(0, cutAt));

		origin = origin.substr(cutAt + 1);
	}

	if (origin.length() > 0)
		result->push_back(origin.substr(0, cutAt));
}

bool String::StartsWith(string str, string comp)//comp�� �����ϴ��� ���ϴ��� Ȯ�ο�
{
	string::size_type index = str.find(comp);

	if (index != string::npos && (int)index == 0)//�ߺ� ��θ� ã���� ����� �� �ִ�.
		return true;

	return false;
}

bool String::StartsWith(wstring str, wstring comp)
{
	wstring::size_type index = str.find(comp);

	if (index != wstring::npos && (int)index == 0)
		return true;

	return false;
}

bool String::Contain(string str, string comp)
{
	size_t found = str.find(comp);

	return found !=string::npos;
}

bool String::Contain(wstring str, wstring comp)
{
	size_t found = str.find(comp);

	return found != wstring::npos;
}

void String::Replace(string * str, string comp, string rep)//�������ؼ� �����ͷ� ����
{
	//���� ���ڿ��� Ư���κ��� �־��� ���ڿ��� ��ü
	string temp = *str;

	size_t start_pos = 0;
	while ((start_pos = temp.find(comp, start_pos)) != string::npos) //�ݺ����� ����
	{
		temp.replace(start_pos, comp.length(), rep);//������ �ε��� ������ rep�� ��ü��
		start_pos += rep.length();
	}

	*str = temp;
}

void String::Replace(wstring * str, wstring comp, wstring rep)
{
	wstring temp = *str;
	size_t start_pos = 0;
	while ((start_pos = temp.find(comp, start_pos)) != wstring::npos)
	{
		temp.replace(start_pos, comp.length(), rep);
		start_pos += rep.length();
	}
	*str = temp;
}

string String::ToString(Vector3 vec3)
{
	wstring temp;
	temp = to_wstring(vec3.x) + to_wstring(vec3.y) + to_wstring(vec3.z);
	string str = ToString(temp);

	return str;
}

wstring String::ToWString(string value)
{
	wstring temp = L"";
	temp.assign(value.begin(), value.end());

	return temp;
}

string String::ToString(wstring value)
{
	string temp = "";
	temp.assign(value.begin(), value.end());

	return temp;
}
