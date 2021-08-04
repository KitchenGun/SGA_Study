#include "stdafx.h"
#include "Scene_Intro.h"

Intro::Intro()
{
}

Intro::~Intro()
{
	SAFE_DELETE(background);

}

void Intro::Init()
{
	background = new TextureRect(Vector3(0, 0, 0), Vector3(1280, 720, 1), 0);
	mapTex = new Texture2D(L"./_Textures/IMG0.png");
	background->SetSRV(mapTex->GetSRV());

	inputSFX = new SoundSystem();
	
	inputSFX->CreateEffSound("_Sounds/Scene0/bleep.wav");

}


void Intro::Update()
{
	inputSFX->Update();

	if (Keyboard::Get()->Down(VK_SPACE))
	{
		
		inputSFX->Play();
		index++;
	}
	switch (index)
	{
		case 0:
		{
			mapTex = new Texture2D(L"./_Textures/IMG0.png");
			background->SetSRV(mapTex->GetSRV());
			break;
		}
		case 1:
		{
			mapTex = new Texture2D(L"./_Textures/IMG1.png");
			background->SetSRV(mapTex->GetSRV()); 
			break;
		}
		case 2:
		{
			mapTex = new Texture2D(L"./_Textures/IMG2.png");
			background->SetSRV(mapTex->GetSRV()); 
			break;
		}
		case 3:
		{
			mapTex = new Texture2D(L"./_Textures/IMG3.png");
			background->SetSRV(mapTex->GetSRV()); 
			break;
		}
		case 4:
		{
			mapTex = new Texture2D(L"./_Textures/IMG4.png");
			background->SetSRV(mapTex->GetSRV()); 
			break;
		}
		case 5:
		{
			mapTex = new Texture2D(L"./_Textures/IMG5.png");
			background->SetSRV(mapTex->GetSRV()); 
			break;
		}
		case 6:
		{
			mapTex = new Texture2D(L"./_Textures/IMG6.png");
			background->SetSRV(mapTex->GetSRV()); 
			break;
		}
	default:
		break;
	}
	background->Update();
}

void Intro::PreRender()
{

}

void Intro::Render()
{
	background->Render();
}

void Intro::PostRender()
{
}
