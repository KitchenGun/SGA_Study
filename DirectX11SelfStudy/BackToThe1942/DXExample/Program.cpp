#include "stdafx.h"
#include "Program.h"
#include "Scenes/SceneList.h"

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
	sceneList.push_back(new Intro());
	sceneList.push_back(new Stage());
	currentScene = sceneList[0];
	currentScene->Init();

	BGM = new SoundSystem();
	BGM->CreateBGSound("_Sounds/Scene0/Start.mp3");
	BGM->Play();
	BGM->SetLoop(true);
}


void Program::Update()
{
	static int beforeIndex;
	static int SceneIndex;
	Camera::Get()->Update();
	BGM->Update();
	if (currentScene == sceneList[0])
	{
		if (dynamic_cast<Intro*>(currentScene)->index >= 1)
		{
			SceneIndex = 0;
			if (beforeIndex == 0)
			{
				BGM->ChangeSoundFunc(L"_Sounds/Scene0/Briefing.mp3");
				BGM->Play();
			}
		}
		if (dynamic_cast<Intro*>(currentScene)->index >= 7)
		{
			currentScene = sceneList[1];
			currentScene->Init();
			if (SceneIndex == 0)
			{
				BGM->ChangeSoundFunc(L"_Sounds/Scene1/BGM.mp3");
				BGM->Play();
				SceneIndex = 1;
			}
		}
		if (dynamic_cast<Intro*>(currentScene) != nullptr)
		{
			beforeIndex = dynamic_cast<Intro*>(currentScene)->index;
		}
	}
	if (Keyboard::Get()->Down(VK_F1))
	{
		currentScene = sceneList[0];
		currentScene->Init();
	}
	
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
