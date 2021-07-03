#include "stdafx.h"
#include "AirHockey.h"

AirHockey::AirHockey()
{
}

AirHockey::~AirHockey()
{
}

void AirHockey::Init()
{
	//ball
	CBall = new Ball({ WinMaxWidth/2,WinMaxHeight / 2,0 }, {25,25,1}, 100, Red);
	//player
	CPlayer = new Player({ WinMaxWidth / 3*2,WinMaxHeight / 2,0 }, { 50,50,1 }, 100, Blue);
	//map
	CLeft = new Circle({ 0,WinMaxHeight / 2,0 }, { 100,200,1 }, 100, White);
	CRight = new Circle({ WinMaxWidth,WinMaxHeight / 2,0 }, { 100,200,1 }, 100, White);
	CMidLine = new Line({ WinMaxWidth / 2,0,0 }, WinMaxHeight, 90, White);
}

void AirHockey::Update()
{
	//충돌감지
	Math::CircleIntersect(CBall, CPlayer);

	//ball
	CBall->Update();
	//player
	CPlayer->Update();
	//map
	CLeft->Update();
	CRight->Update();
	CMidLine->Update();
}

void AirHockey::PreRender()
{
}

void AirHockey::Render()
{
	//ball
	CBall->Render();
	//player
	CPlayer->Render();
	//map
	CLeft->Render();
	CRight->Render();
	CMidLine->Render();
}
