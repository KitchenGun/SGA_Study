#pragma once

#define MAX_INPUT_KEY 255
#define MAX_INPUT_MOUSE 8

#define KeyDown_Up Keyboard::Get()->Down('W')
#define KeyDown_Down Keyboard::Get()->Down('S')
#define KeyDown_Left Keyboard::Get()->Down('A')
#define KeyDown_Right Keyboard::Get()->Down('D')

#define KeyPress_Up Keyboard::Get()->Press('W')
#define KeyPress_Down Keyboard::Get()->Press('S')
#define KeyPress_Left Keyboard::Get()->Press('A')
#define KeyPress_Right Keyboard::Get()->Press('D')

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

	byte KeyState[MAX_INPUT_KEY];		//���� Ű ����	
	byte KeyOldState[MAX_INPUT_KEY];	//���� Ű ����
	byte KeyMap[MAX_INPUT_KEY];			//���� Ű ����

	enum
	{
		KEY_INPUT_STATUS_NONE=0,
		KEY_INPUT_STATUS_DOWN,
		KEY_INPUT_STATUS_UP,
		KEY_INPUT_STATUS_PRESS,
	};
};