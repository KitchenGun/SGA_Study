#include "Member.h"

std::string CMember::GetName() const
{
	return this->strName;
}

void CMember::SetName(std::string a_strName)
{
	this->strName = a_strName;
}

std::string CMember::GetPhoneNum() const
{
	return this->strPhoneNum;
}

void CMember::SetPhoneNum(std::string a_strPhoneNum)
{
	this->strPhoneNum = a_strPhoneNum;
}

int CMember::GetAge() const
{
	return this->age;
}

void CMember::SetAge(int a_nAge)
{
	this->age = a_nAge;
}

bool CMember::operator==(const CMember& mem)
{
	return (this->strName == mem.GetName());
}


void CMember::Print()
{
	printf("\n이름 : %s\n", strName.c_str());
	printf("전화번호 : %s\n", strPhoneNum.c_str());
	printf("나이 : %d\n", age);
}

CMember::CMember(std::string a_strName, std::string strPhoneNum, int a_nAge)
	:
	strName(a_strName),
	strPhoneNum(strPhoneNum),
	age(a_nAge)
{
	//do nothing
}

