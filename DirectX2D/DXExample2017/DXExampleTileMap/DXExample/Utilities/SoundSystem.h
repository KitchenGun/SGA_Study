#pragma once

#include <FMod/fmod.h>

class SoundSystem
{
public:
	SoundSystem();
	~SoundSystem();

	void CreateSound(const string& fileName);
	void CreateBGSound(const string& fileName);
	void CreateEffSound(const string& fileName);

	void Play();
	void Stop();

	void Update();

	void SetVolume(float val);
	void SetMute(bool val);
	void SetLoop(bool val);
	void GUI(int ordinal);

private:
	void ChangeSoundFunc(const wstring& path = L"");

	struct FMOD_SYSTEM* system = nullptr;
	struct FMOD_SOUND*	sound = nullptr;
	struct FMOD_CHANNEL* channel = nullptr;

	float volume = 0.2f;
	bool bMute = false;
	bool bLoop = false;
	FMOD_BOOL bPlaying = 0;
	string fileName = "";

	int result = 0;

};