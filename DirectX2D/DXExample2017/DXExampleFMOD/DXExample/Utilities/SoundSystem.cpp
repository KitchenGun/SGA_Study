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
}

void SoundSystem::ChangeSoundFunc(const wstring & path)
{
}
