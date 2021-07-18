#include "stdafx.h"
#include "Fortress.h"

Fortress::Fortress()
{
}

Fortress::~Fortress()
{
}

void Fortress::Init()
{
	CPlayer = new Player(Vector3(50, 50, 0), Vector3(100, 100, 1), 0,true);
	CEnemy = new Player(Vector3(WinMaxWidth - 50, 50 , 0), Vector3(100, 100, 1), 0,false);
	BG = new SoundSystem;
	BG->CreateBGSound("./_Sounds/Stage.mp3");
	BG->SetLoop(true);
	BG->Play();
	BG->SetVolume(0.2f);
}

void Fortress::Update()
{
	if (isPlayerTurn)
	{
		CPlayer->Update();
		if (CPlayer->GetIsFire())
		{
			CPlayer->SetIsFire(false);
			isPlayerTurn = false;
		}
	}
	else if(!isPlayerTurn)
	{
		CEnemy->Update();
		if (CEnemy->GetIsFire())
		{
			CEnemy->SetIsFire(false);
			isPlayerTurn = true;
		}
	}
	CPlayer->BulletUpdate();
	CEnemy->BulletUpdate();
}

void Fortress::PreRender()
{
}

void Fortress::Render()
{
	CPlayer->Render();
	CEnemy->Render();
}

void Fortress::PostRender()
{
}
