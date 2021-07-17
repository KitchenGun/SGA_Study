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
	CPlayer = new Player(Vector3(100, 100, 0), Vector3(100, 100, 1), 0);
}

void Fortress::Update()
{
	CPlayer->Update();

}

void Fortress::PreRender()
{
}

void Fortress::Render()
{
	CPlayer->Render();
}

void Fortress::PostRender()
{
}
