#include "stdafx.h"
#include "Scene3_Texture.h"

Scene3::Scene3()
{
}

Scene3::~Scene3()
{
	SAFE_DELETE(circle);
}

void Scene3::Init()
{
	circle = new FilledCircle(Vector3(800, 600, 0), Vector3(100, 100, 1), 100, White);
}

void Scene3::Update()
{
	circle->Update();
}

void Scene3::PreRender()
{

}

void Scene3::Render()
{
	circle->Render();
}
