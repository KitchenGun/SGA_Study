#include "P03.h"
#include "Map.h"
#include "PlayerCtrl.h"

namespace P03Space
{
	void P03(const int argc, const char** args)
	{
		CMap oMap;
		oMap.Reset();
		Player oPlayer(oMap);
		oMap.PrintMap();
	
		while (!oPlayer.GetIsDie()) 
		{
			
			printf("HP : %d\n", oPlayer.GetHP());
			char chInput = _getch();
			system("cls");
			oPlayer.InputKey(chInput);

		}
	}
}
