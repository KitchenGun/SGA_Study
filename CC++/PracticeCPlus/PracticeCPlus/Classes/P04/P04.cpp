#include "P04.h"
#include "VectorMemberManager.h"
#include "MapMemberManager.h"
//#define VECTOR	1
#define MAP		2

namespace P04Space
{
	void P04(const int argc, const char** args)
	{
#if VECTOR
		CMember oTempMem = CMember("", "", 0);
		CVecMemManager oVecManager = CVecMemManager();
		int nInputVal = 0;
		while (true)
		{
			oVecManager.PrintMenu();
			printf("\n메뉴 선택 : ");
			std::cin >> nInputVal;
			switch (nInputVal)
			{
			case 1:
				oVecManager.InsertMember();
				break;
			case 2:
				oVecManager.DeleteMember(oTempMem);
				break;
			case 3:
				oVecManager.SearchMember(oTempMem);
				break;
			case 4:
				oVecManager.PrintAll();
				break;
			case 5:
				printf("\n프로그램을 종료합니다\n");
				return;
			default:
				printf("\n숫자를 입력하세요!\n");
				break;
			}
		}
#elif MAP
		CMember oTempMem = CMember("", "", 0);
		CMapMemManager oMapManager = CMapMemManager();
		int nInputVal = 0;
		while (true)
		{
			oMapManager.PrintMenu();
			printf("\n메뉴 선택 : ");
			std::cin >> nInputVal;
			switch (nInputVal)
			{
			case 1:
				oMapManager.InsertMember();
				break;
			case 2:
				oMapManager.DeleteMember(oTempMem);
				break;
			case 3:
				oMapManager.SearchMember(oTempMem);
				break;
			case 4:
				oMapManager.PrintAll();
				break;
			case 5:
				printf("\n프로그램을 종료합니다\n");
				return;
			default:
				printf("\n숫자를 입력하세요!\n");
				return;
			}
		}
#endif // VECTOR
	}
}
