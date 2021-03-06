#include "stdafx.h"
#include "Scene7_Sound.h"

Scene7::Scene7()
{
}

Scene7::~Scene7()
{
	SAFE_DELETE(EffSound);
	SAFE_DELETE(BGSound);
}

void Scene7::Init()
{
	string fileName = "./_Sounds/war.mp3";
	BGSound = new SoundSystem();
	BGSound->CreateBGSound(fileName);

	EffSound = new SoundSystem();
	EffSound->CreateEffSound("./_Sounds/play_fire.wav");
}

void Scene7::Update()
{
	if (Keyboard::Get()->Down(VK_01))
	{
		BGSound->Play();
	}
	else if (Keyboard::Get()->Down(VK_02))
	{
		BGSound->Stop();
	}
	else if (Keyboard::Get()->Down(VK_03))
	{
		EffSound->Play();
	}
	else if (Keyboard::Get()->Down(VK_04))
	{
		EffSound->Stop();
	}
	else if (Keyboard::Get()->Down(VK_05))
	{
		EffSound->SetLoop(true);
	}
	else if (Keyboard::Get()->Down(VK_06))
	{
		EffSound->SetLoop(false);
	}
	BGSound->Update();
	EffSound->Update();
}

void Scene7::PreRender()
{
}

void Scene7::Render()
{
	
}

void Scene7::PostRender()
{
	//guiâ����
	bool temp = true;
	if (ImGui::Begin("Sounds"), &temp);
	{
		BGSound->GUI(0);
		EffSound->GUI(1);
	}
	ImGui::End();
}
