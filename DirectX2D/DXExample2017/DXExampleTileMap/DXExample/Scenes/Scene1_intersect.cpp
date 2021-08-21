#include "stdafx.h"
#include "Scene1_intersect.h"

Scene1::Scene1()
{

}

Scene1::~Scene1()
{
	SAFE_DELETE(square2);
	SAFE_DELETE(square);
}

void Scene1::Init()
{
	square = new Square({ 200,200,0 }, { 100,100,1 }, 30,Red);
	square2 = new Square({ 400,400,0 }, { 100,100,1 }, 0, Red);
}

void Scene1::Update()
{
	//입력
	if (Keyboard::Get()->Press('W'))
		square->Move({ 0,1,0 });
	else if (Keyboard::Get()->Press('S'))
		square->Move({ 0,-1,0 });
	if (Keyboard::Get()->Press('A'))
		square->Move({ -1,0,0 });
	else if (Keyboard::Get()->Press('D'))
		square->Move({ 1,0,0 });
	

	if (Math::IntersectOriented(square, square2))
	{
		square2->SetIntersect(true);
		square2->SetColor(Cyan);
	}
	else
	{
		square2->SetIntersect(false);
		square2->SetColor(Red);
	}

	square->Update();
	square2->Update();
}

void Scene1::PreRender()
{
}

void Scene1::Render()
{
	//square 안에는 wb 0에 슬롯 0을 넣어놨다
	square->Render();
	square2->Render();
}

void Scene1::PostRender()
{
}
