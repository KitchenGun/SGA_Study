#include "../stdafx.h"
#include "Window.h"

WinDesc Window::desc;
HINSTANCE instance;

Window::Window(WinDesc desc)
{
	WNDCLASSEX wndClass;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hCursor = LoadCursor(NULL,IDC_ARROW);
	wndClass.hIcon = LoadCursor(NULL, IDI_WINLOGO);
	wndClass.hInstance = desc.instance;
	wndClass.lpfnWndProc = (WNDPROC)WndProc;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wndClass.cbSize = sizeof(WNDCLASSEX);
}

Window::~Window()
{

}

WPARAM Window::Run()
{
	return WPARAM();
}

LRESULT Window::WndProc(HWND handle, UINT message, WPARAM wParam, LPARAM lParam)
{
	return LRESULT();
}
