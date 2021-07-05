#include "stdafx.h"
#include "String.h"

void String::SplitString(vector<string>* result, string origin, string tok)//특정 문자를 기준으로 문자열 자르기
{
	result->clear();

	int cutAt = 0;//자를 위치 인덱스
	
	//문자열 origin에서 tok가 나오는 가장 첫번째 문자의 인덱스를 cutat에 넣고 while문 돌림
	//찾는 문자열이 있을 경우 돌린다
	while (cutAt = (int)origin.find_first_of(tok) != origin.npos)
	{
		if (cutAt > 0)
			result->push_back(origin.substr(0, cutAt));
		//오리지날에 자른부분을 제외하고 넣어준다
		origin = origin.substr(cutAt + 1);
	}
	if (origin.length() > 0)
		result->push_back(origin.substr(0, cutAt));
}

void String::SplitString(vector<wstring>* result, wstring origin, wstring tok)
{
	result->clear();

	int cutAt = 0;
	while ((cutAt = (int)origin.find_first_of(tok) != origin.npos))
	{
		if (cutAt > 0)
			result->push_back(origin.substr(0, cutAt));

		origin = origin.substr(cutAt + 1);
	}

	if (origin.length() > 0)
		result->push_back(origin.substr(0, cutAt));
}

bool String::StartsWith(string str, string comp)
{
	string::size_type index = str.find(comp);

	if (index != string::npos && (int)index == 0)//str 첫번째 값을 넣을때만 true가 나온다
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

void String::Replace(string * str, string comp, string rep)
{
	//원래 문자열 주소에서 사이즈를 늘리는 방법
	string temp = *str;
	size_t start_pos = 0;
	while ((start_pos = temp.find(comp, start_pos)) != string::npos)
	{
		temp.replace(start_pos, comp.length(), rep);//선택한 인덱스 범위를 rep로 교체함
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
