#include "stdafx.h"
#include "Running.h"

Running::Running()
{
}

Running::~Running()
{
}

void Running::Init()
{
	CPlayer = new Player(Vector3(150, 50, 0), Vector3(100, 100, 1), 0);
}

void Running::Update()
{
	CPlayer->Update();

}

void Running::PreRender()
{
}

void Running::Render()
{
	CPlayer->Render();
}

void Running::PostRender()
{

}
