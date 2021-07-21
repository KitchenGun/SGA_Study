#include "stdafx.h"
#include "Scene9_Animation.h"

Scene9::Scene9()
{
	
}

Scene9::~Scene9()
{
	
}

void Scene9::Init()
{
	animRect = new AnimationRect(Vector3(300, 300, 0), Vector3(100, 100, 1), 0);
}

void Scene9::Update()
{
	if (KeyPress_Left)
		animRect->Move(Vector3(-100 * Time::Delta(), 0, 0));
	else if (KeyPress_Right)
		animRect->Move(Vector3(100 * Time::Delta(), 0, 0));

	if (KeyPress_Up)
		animRect->Move(Vector3(0, 100 * Time::Delta(), 0));
	else if (KeyPress_Down)
		animRect->Move(Vector3(0, -100 * Time::Delta(), 0));
	animRect->Update();
	
}

void Scene9::PreRender()
{
}

void Scene9::Render()
{
	animRect->Render();
}

void Scene9::PostRender()
{
	
}
