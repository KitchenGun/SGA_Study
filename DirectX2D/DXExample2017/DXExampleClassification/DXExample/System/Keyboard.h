#pragma once

#define MAX_INPUT_KEY 255
#define MAX_INPUT_MOUSE 8

class Keyboard
{
public:
	static Keyboard *Get();
	static void Create();
	static void Delete();

	void Update();

	bool Down(DWORD key) { return KeyMap[key] == KEY_INPUT_STATUS_DOWN; }
	bool Up(DWORD key) { return KeyMap[key] == KEY_INPUT_STATUS_UP; }
	bool Press(DWORD key) { return KeyMap[key] == KEY_INPUT_STATUS_PRESS; }
private:

	Keyboard();
	~Keyboard();

	static Keyboard* instance;

	byte KeyState[MAX_INPUT_KEY];
	byte KeyOldState[MAX_INPUT_KEY];
	byte KeyMap[MAX_INPUT_KEY];

	enum
	{
		KEY_INPUT_STATUS_NONE=0,
		KEY_INPUT_STATUS_DOWN,
		KEY_INPUT_STATUS_UP,
		KEY_INPUT_STATUS_PRESS,
	};
};