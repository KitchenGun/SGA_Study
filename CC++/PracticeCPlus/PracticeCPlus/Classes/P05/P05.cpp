#include "P05.h"

//#define NPOS	0
//#define SUBSTR	1
//#define STARTSWITH	2
//#define CONTAIN		3
#define REPLACE		4
namespace P05Space
{
	void P05(const int argc, const char** args)
	{
#ifdef NPOS
		std::string a = { "abcd" };
		std::string b = { "efgh" };

		if (b.find("a") == std::string::npos)
		{
			std::cout << "true";
		}
#elif SUBSTR
		std::string a = "012345";
		std::string b = a.substr(1,4);
		std::string c = a.substr(3);
		std::cout << b <<" "<<c<< std::endl;

#elif STARTSWITH
		std::string a = "012345";
		std::string::size_type index = a.find("0");

		if (index != std::string::npos && (int)index == 0)//항상FALSE아닌가?
			std::cout << "true";
		else
			std::cout << "false";

#elif CONTAIN
		std::string a = "012345";
		size_t found = a.find("67");

		if (found != std::string::npos)
			std::cout << "true";
		else
			std::cout << "false";

#elif REPLACE
		std::string a = "012345";
		std::string comp = "0123";
		std::string rep = "9876";
		size_t start_pos = 0;
		
		while ((start_pos = a.find(comp, start_pos)) != std::string::npos)
		{
			a.replace(start_pos, comp.length(), rep);
			start_pos += rep.length();
		}
		std::cout<<a;
#endif // npos

	}
}