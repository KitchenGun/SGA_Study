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
	square = new Square({ 200,200,0 }, { 100,100,1 }, 0,Red);
	square2 = new Square({ 400,400,0 }, { 100,100,1 }, 0, Red);
}

void Scene1::Update()
{
	//�Է�
	if (Keyboard::Get()->Press('W'))
		square->Move({ 0,10,0 });
	else if (Keyboard::Get()->Press('S'))
		square->Move({ 0,-10,0 });
	if (Keyboard::Get()->Press('A'))
		square->Move({ -10,0,0 });
	else if (Keyboard::Get()->Press('D'))
		square->Move({ 10,0,0 });


	if (Math::Intersect(square, square2))
	{
		//square->SetIntersect(true);
		square2->SetIntersect(true);
		square2->SetColor(Cyan);
	}
	else
	{
		//square->SetIntersect(false);
		square2->SetIntersect(false);
		square2->SetColor(Red);
	}

	square->Update();
	square2->Update();
}

void Scene1::Render()
{
	//square �ȿ��� wb 0�� ���� 0�� �־����
	square->Render();
	square2->Render();
}
