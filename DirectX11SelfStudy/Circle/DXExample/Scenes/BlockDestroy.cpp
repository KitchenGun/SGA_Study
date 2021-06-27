#include "stdafx.h"
#include "BlockDestroy.h"

BlockDestroy::BlockDestroy()
{

}

BlockDestroy::~BlockDestroy()
{
	SAFE_DELETE(ball);
	SAFE_DELETE(player);
	SAFE_DELETE(BoxM);
}

void BlockDestroy::Init()
{

	player = new Player({ WinMaxWidth / 2,WinMaxHeight / 6,0 }, { 200,10,1 }, 0, Red);
	ball = new Ball({ WinMaxWidth/2,WinMaxHeight/2,0 }, { 25,25,1 },100, Red);
	BoxM = new BoxManager();
}

void BlockDestroy::Update()
{
	if (Math::PlayerIntersect(ball, player))
	{
		player->SetColor(Yellow);
	}
	else
	{
		player->SetColor(Red);
	}
	for (Square* enemy : BoxM->GetEnemyList())
	{
		if (enemy != nullptr)
		{
			enemy->Update();
			if (Math::CircleIntersect(ball, enemy))
			{
				BoxM->Remove(enemy);
			}
		}
	}


	player->Update();
	ball->Update();
}

void BlockDestroy::PreRender()
{
}

void BlockDestroy::Render()
{
	//player ¾È¿¡´Â wb 0¿¡ ½½·Ô 0À» ³Ö¾î³ù´Ù
	player->Render();
	ball->Render();

	for (Square* enemy : BoxM->GetEnemyList())
	{
		if (enemy != nullptr)
		{
			enemy->Render();
		}
	}
}
