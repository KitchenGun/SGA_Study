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

	bounceSFX = new SoundSystem;
	bounce2SFX = new SoundSystem;
	string fileName = "./_Sounds/gen_3A.wav";
	bounceSFX->CreateEffSound(fileName);
	fileName = "./_Sounds/gen_2C.wav";
	bounce2SFX->CreateEffSound(fileName);
	//ball
	CBall = new Ball({ WinMaxWidth/2,WinMaxHeight / 2,0 }, {25,25,1}, 100, Red);
	//player
	CPlayer = new Player({ WinMaxWidth / 3*2,WinMaxHeight / 2,0 }, { 50,50,1 }, 100, Blue);
	CPlayerGoalPost = new Square({ WinMaxWidth,WinMaxHeight / 2,0 }, { 50,200,1 }, 0, Red);
	//enemy
	CEnemy = new Player({ WinMaxWidth / 4,WinMaxHeight / 2,0 }, { 50,50,1 }, 100, Green);
	CEnemy->SetEnemy(true);
	CEnemyGoalPost = new Square({ 0,WinMaxHeight / 2,0 }, { 50,200,1 }, 0, Red);
	//map
	CLeft = new Circle({ 0,WinMaxHeight / 2,0 }, { 100,200,1 }, 100, White);
	CRight = new Circle({ WinMaxWidth,WinMaxHeight / 2,0 }, { 100,200,1 }, 100, White);
	CMidLine = new Line({ WinMaxWidth / 2,0,0 }, WinMaxHeight, 90, White);
}

void AirHockey::Update()
{
	//ball
	if (CBall != NULL)
	{
		CBall->Update();
		if (CBall->GetIntersect())
		{
			bounceSFX->Play();
		}
	}
	//player
	CPlayer->Update();

	CPlayerGoalPost->Update();
	//enemy
	CEnemy->Update();

	if (CBall != NULL)
	{
		if (CBall->GetTransformedCoord().POINT.x < WinMaxWidth)
		{
			CEnemy->SetVecDir({ CBall->GetVecDir().x * 5,CBall->GetVecDir().y * 3,0 });
		}
		else
		{
			CEnemy->SetVecDir({ CBall->GetVecDir().x * 3,CBall->GetVecDir().y,0 });
		}
	}
	else
		CEnemy->SetVecDir({ 0,0,0 });
	CEnemyGoalPost->Update();
	//map
	CLeft->Update();
	CRight->Update();
	CMidLine->Update();
	//충돌감지
	if (CBall != NULL)
	{
		Math::CircleIntersect(CBall, CPlayer);
		Math::CircleIntersect(CBall, CEnemy);
		if (Math::CircleIntersect(CBall, CPlayerGoalPost))
		{
			nEnemyPoint++;
			cout << nEnemyPoint << " : " << nPlayerPoint << endl;
			CBall->Reset();
		}
		if (Math::CircleIntersect(CBall, CEnemyGoalPost))
		{
			nPlayerPoint++;
			cout << nEnemyPoint << " : " << nPlayerPoint << endl;
			CBall->Reset();
		}

		//결과 출력
		if (nEnemyPoint >= 3 || nPlayerPoint >= 3)
		{
			if (nEnemyPoint >= 3)
				MessageBox(handle, L"패배", L"게임 종료", MB_OK);
			if (nPlayerPoint >= 3)
				MessageBox(handle, L"승리", L"게임 종료", MB_OK);
			SAFE_DELETE(CBall)
		}
	}
	if (CPlayer->GetIntersect() || CEnemy->GetIntersect())
	{
		bounce2SFX->Play();
		static int temp=0;
		temp++;
		cout << temp << endl;
		bounce2SFX->Update();
	}
}

void AirHockey::PreRender()
{
}

void AirHockey::Render()
{
	//ball
	if (CBall != NULL)
		CBall->Render();
	//player
	CPlayer->Render();
	CPlayerGoalPost->Render();
	//enemy
	CEnemy->Render();
	CEnemyGoalPost->Render();
	//map
	CLeft->Render();
	CRight->Render();
	CMidLine->Render();
}
