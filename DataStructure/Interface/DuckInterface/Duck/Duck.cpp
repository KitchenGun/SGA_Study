#include "Duck.h"


Duck::Duck()
	:
	m_strDuckType("����"),
	m_oflyBehavior(nullptr)
{

}

void Duck::Fly()
{
	
}

void Duck::Display()
{
	std::cout << m_strDuckType << std::endl;
}
