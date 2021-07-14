#include "stdafx.h"
#include "SoundSystem.h"
#include <FMod/fmod.h>

SoundSystem::SoundSystem()
{
	result = FMOD_System_Create(&system);
	if (result != FMOD_OK)
		ASSERT(false);
	FMOD_System_Init(system, 32, FMOD_INIT_NORMAL, nullptr);
}

SoundSystem::~SoundSystem()
{
	FMOD_Sound_Release(sound);
	FMOD_System_Close(system);
	FMOD_System_Release(system);
}

void SoundSystem::CreateSound(const string & fileName)
{
	FMOD_RESULT result = FMOD_System_CreateSound(system, fileName.data(), FMOD_LOOP_NORMAL, 0, &sound);
	if (result != FMOD_OK)
		ASSERT(false);
	bLoop = false;
}

void SoundSystem::CreateBGSound(const string & fileName)
{
}

void SoundSystem::CreateEffSound(const string & fileName)
{
}

void SoundSystem::Play()
{
}

void SoundSystem::Stop()
{
}

void SoundSystem::Update()
{
}

void SoundSystem::SetVolume(float val)
{
}

void SoundSystem::SetMute(bool val)
{
}

void SoundSystem::SetLoop(bool val)
{
}

void SoundSystem::GUI(int ordinal)
{
<<<<<<< Updated upstream
=======
	string objName = "Sound" + to_string(ordinal);
	string GUIFileName = "File Name : " + fileName;
	if (ImGui::BeginMenu(objName.c_str()))
	{
		ImGui::Text(objName.c_str());
		ImGui::Text(GUIFileName.c_str());
		//음원 교체
		if (ImGui::Button("ChangeSound", ImVec2(100, 30)))
		{
			ChangeSoundFunc();
			if (bPlaying)
			{
				Play();
			}
		}
		//볼륨 조절
		ImGui::SliderFloat("Volume", &volume, 0.0f, 1.0f, "%.2f");
		SetVolume(volume);
		//뮤트
		ImGui::Checkbox("Mute", &bMute);
		SetMute(bMute);

		ImGui::EndMenu();
	}
>>>>>>> Stashed changes
}

void SoundSystem::ChangeSoundFunc(const wstring & path)
{
<<<<<<< Updated upstream
=======
	if (path.length() < 1)
	{
		//경로가 없을 경우
		function<void(wstring)> func = bind(&SoundSystem::ChangeSoundFunc, this, placeholders::_1);
		Path::OpenFileDialog(L"", Path::SoundFilter, L"./_Sounds/", func, handle);
	}
	else
	{
		size_t index = fileName.find_last_of('(');

		fileName = Path::GetFileName(String::ToString(path)) + " " + fileName.substr(index, fileName.length());
		if (bPlaying)
		{
			Stop();
			bPlaying = true;
		}

		if (bLoop)
		{
			CreateSound(String::ToString(path));
			bLoop = true;
		}
		else
		{
			CreateSound(String::ToString(path));
		}
	}
>>>>>>> Stashed changes
}
