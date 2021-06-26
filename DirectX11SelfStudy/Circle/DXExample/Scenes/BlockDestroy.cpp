#include "stdafx.h"
#include "BlockDestroy.h"

BlockDestroy::BlockDestroy()
{

}

BlockDestroy::~BlockDestroy()
{
	SAFE_DELETE(ball);
	SAFE_DELETE(player);
}

void BlockDestroy::Init()
{
	player = new Player({ 200,200,0 }, { 100,100,1 }, 0, Red);
	ball = new Ball({ 400,400,0 }, { 50,50,1 },100, Red);
}

void BlockDestroy::Update()
{
	//if (Math::CircleIntersect(ball,player))
	//{
	//	player->SetIntersect(true);
	//	player->SetColor(Cyan);
	//	cout << "충돌" << endl;
	//}
	//else
	//{
	//	player->SetIntersect(false);
	//	player->SetColor(Red);
	//}

	player->Update();
	ball->Update();
}

void BlockDestroy::PreRender()
{
}

void BlockDestroy::Render()
{
	//player 안에는 wb 0에 슬롯 0을 넣어놨다
	player->Render();
	ball->Render();
}
