#pragma once
#include"P04.h"

class CMember
{
public:
	static CMember InsertMem()
	{
		std::string a_strName;
		std::string strPhoneNum;
		int a_nAge=0;
		printf("이름 : ");
		std::cin>>a_strName;
		printf("전화번호 : ");
		std::cin >> strPhoneNum;
		printf("나이 : ");
		std::cin >> a_nAge;
		return CMember(a_strName,strPhoneNum, a_nAge);
	}
public:
	std::string GetName()const;
	void SetName(std::string a_strName);
	std::string GetPhoneNum()const;
	void SetPhoneNum(std::string a_strPhoneNum);
	int GetAge()const;
	void SetAge(int a_nAge);
	bool operator==(const CMember& mem);

public:
	void Print();
public:
	CMember(std::string a_strName, std::string strPhoneNum, int a_nAge);
private:
	std::string strName;
	std::string strPhoneNum;
	int age;
};