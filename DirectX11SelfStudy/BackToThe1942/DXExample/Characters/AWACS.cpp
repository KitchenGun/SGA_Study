#include "stdafx.h"
#include "AWACS.h"

AWACS::AWACS(Vector3 position, Vector3 size, float rotation)
	:AnimationRect(position,size,rotation)
{
	Speaker = new SoundSystem();
}

AWACS::~AWACS()
{
	AnimationRect::~AnimationRect();
}

void AWACS::Update()
{
	Speaker->Update();
}

void AWACS::SetSoundPath(int index)
{
}


