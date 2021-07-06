#include "stdafx.h"
#include "Gui.h"

Gui* Gui::instance = nullptr;

void Gui::Create()
{
	assert(instance == nullptr);

	instance = new Gui();
}

void Gui::Delete()
{
	SAFE_DELETE(instance);
}

Gui * Gui::Get()
{
	return instance;
}

LRESULT Gui::MSGProc(HWND handle, UINT message, WPARAM wParam, LPARAM lParam)
{
	return ImGui_ImplWin32_Proc(handle, message, wParam, lParam);
}

void Gui::Resize()
{
	ImGui_ImplDX11_InvalidateDeviceObjects();
	ImGui_ImplDX11_CreateDeviceObjects();
}

void Gui::PrintFrame()
{
	bool temp = true;
	ImGui::SetNextWindowPos({ WinMaxWidth - 150,0 });
	if (ImGui::Begin("FrameRate", &temp, ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoTitleBar))
	{
		string frameStr = "Frame Rate : " + to_string((int)ImGui::GetIO().Framerate);
		ImGui::TextColored(ImVec4(1, 1, 1, 1), frameStr.c_str());
	}
	ImGui::End();
}

void Gui::TextureRectGUIS(vector<class TextureRect*>& rtVec, const char * name)
{
}

void Gui::Update()
{
}

void Gui::Render()
{
}

Gui::Gui()
{
}

Gui::~Gui()
{
}

void Gui::ApplyStyle()
{
}
