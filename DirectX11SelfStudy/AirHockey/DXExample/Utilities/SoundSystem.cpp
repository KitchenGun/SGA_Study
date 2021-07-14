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
	//기본 설정
	FMOD_RESULT result = FMOD_System_CreateSound(system, fileName.data(), FMOD_DEFAULT, 0, &sound);
	if (result != FMOD_OK)
		ASSERT(false);

	bLoop = false;
}

void SoundSystem::CreateBGSound(const string & fileName)
{
	this->fileName = Path::GetFileName(fileName) + " (BGSound)";
	CreateSound(fileName);
}

void SoundSystem::CreateEffSound(const string & fileName)
{
	this->fileName = Path::GetFileName(fileName) + " (EFFSound)";
	CreateSound(fileName);
}

void SoundSystem::Play()
{//생성한 사운드 플레이
	bPlaying = true;
	FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, sound, 0, &channel);
}

void SoundSystem::Stop()
{//생성한 사운드 멈추기
	bPlaying = false;
	FMOD_Channel_Stop(channel);
}

void SoundSystem::Update()
{
	if (system)
		FMOD_System_Update(system);

	FMOD_MODE mode = bLoop ? FMOD_LOOP_NORMAL : FMOD_LOOP_OFF;
	FMOD_Channel_SetMode(channel, mode);
	SetVolume(volume);
}

void SoundSystem::SetVolume(float val)
{
	volume = val;
	FMOD_Channel_SetVolume(channel, volume);
}

void SoundSystem::SetMute(bool val)
{
	bMute = val;
	FMOD_Channel_SetMute(channel, bMute);
}

void SoundSystem::SetLoop(bool val)
{
	bLoop = val;
}

