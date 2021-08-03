#include "stdafx.h"
#include "Scenes/SceneList.h"
#include "Program.h"

Program::Program()
{
	Camera::Create();
	
}

Program::~Program()
{
	Camera::Delete();
}

void Program::Init()
{
	sceneList.push_back(new Stage());
	currentScene = sceneList[0];
	currentScene->Init();
}


void Program::Update()
{
	Camera::Get()->Update();
	if (Keyboard::Get()->Down(VK_F1))
	{
		currentScene = sceneList[0];
		currentScene->Init();
	}
	/*else if (Keyboard::Get()->Down(VK_F2))
	{
		currentScene = sceneList[1];
		currentScene->Init();
	}
	else if (Keyboard::Get()->Down(VK_F3))
	{
		currentScene = sceneList[2];
		currentScene->Init();
	}
	else if (Keyboard::Get()->Down(VK_F4))
	{
		currentScene = sceneList[3];
		currentScene->Init();
	}
	else if (Keyboard::Get()->Down(VK_F5))
	{
		currentScene = sceneList[4];
		currentScene->Init();
	}
	else if (Keyboard::Get()->Down(VK_F6))
	{
		currentScene = sceneList[5];
		currentScene->Init();
	}
	else if (Keyboard::Get()->Down(VK_F7))
	{
		currentScene = sceneList[6];
		currentScene->Init();
	}
	else if (Keyboard::Get()->Down(VK_F8))
	{
		currentScene = sceneList[6];
		currentScene->Init();
	}*/
	currentScene->Update();
}




void Program::PreRender()
{
	currentScene->PreRender();
}

void Program::Render()
{
	Camera::Get()->Render();
	currentScene->Render();
}

void Program::PostRender()
{
	Gui::Get()->PrintFrame();
	currentScene->PostRender();
}
