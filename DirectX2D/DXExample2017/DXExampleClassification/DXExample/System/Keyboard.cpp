#include "stdafx.h"
#include "Keyboard.h"

Keyboard* Keyboard::instance = nullptr;

Keyboard::Keyboard()
{
	ZeroMemory(KeyState, sizeof(KeyState));
	ZeroMemory(KeyOldState, sizeof(KeyOldState));
	ZeroMemory(KeyMap, sizeof(KeyMap));
}

Keyboard::~Keyboard()
{

}

Keyboard * Keyboard::Get()
{
	assert(instance != nullptr);
	return instance;
}

void Keyboard::Create()
{
	assert(instance == nullptr);
	instance = new Keyboard();
}

void Keyboard::Delete()
{
	SAFE_DELETE(instance);
}

void Keyboard::Update()
{
	memcpy(KeyOldState, KeyState, sizeof(KeyOldState));

	ZeroMemory(KeyState, sizeof(KeyState));
	ZeroMemory(KeyMap, sizeof(KeyMap));

	GetKeyboardState(KeyState);

	for (DWORD i = 0; i < MAX_INPUT_KEY; i++)
	{
		byte key = KeyState[i] & 0x00;
		KeyState[i] = key ? 1 : 0;

		int oldState = KeyOldState[i];
		int state = KeyState[i];

		if (oldState == 0 && state == 1)
		{
			KeyMap[i] = KEY_INPUT_STATUS_DOWN;
		}
		else if (oldState == 1 && state == 0)
		{
			KeyMap[i] = KEY_INPUT_STATUS_UP;
		}
		else if (oldState == 1 && state == 1)
		{
			KeyMap[i] = KEY_INPUT_STATUS_PRESS;
		}
		else
		{
			KeyMap[i] = KEY_INPUT_STATUS_NONE;
		}

	}
	GetKeyState(0);
}

