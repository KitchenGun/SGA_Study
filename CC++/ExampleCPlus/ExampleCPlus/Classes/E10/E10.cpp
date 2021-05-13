#include "E10.h"
namespace  E10Space
{
	void E10(const int argc, const char** args)
	{
		long Dword = 0x12345678;

		int Hiword = Dword & 0xFFFF0000;
		Hiword=Hiword >> 16;
		printf("%x\n",Hiword);

		int Loword = Dword & 0x0000FFFF;
		printf("%x\n", Loword);

	}
}
