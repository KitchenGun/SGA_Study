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
	//gui�� �޼��� �ޱ����ؼ� ����ϴ� ����
	return ImGui_ImplWin32_Proc(handle, message, wParam, lParam);
}

void Gui::Resize()//�ػ� �ٲ�ų� ��Ⱑ �ٲ����� ȣ��
{
	ImGui_ImplDX11_InvalidateDeviceObjects();
	ImGui_ImplDX11_CreateDeviceObjects();
}

void Gui::PrintFrame()//������ ���
{
	bool temp = true; //�⺻���� �ٲٱ� ���ؼ� bool ������ �Ѱ������ ���� false�� �ѱ�� �ȳ���
	ImGui::SetNextWindowPos({ WinMaxWidth - 150,0 });//���� �������� ������ ����//���ܿ� ���
	if (ImGui::Begin("FrameRate", &temp, ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoTitleBar|ImGuiWindowFlags_NoResize))//guiâ �ϳ��� ���ڴ�
	{//Ÿ��Ʋ �� ���� ��浵 ����
		string frameStr = "Frame Rate : " + to_string((int)ImGui::GetIO().Framerate);//������ ����Ʈ �޾ƿ�
		ImGui::TextColored(ImVec4(1, 1, 1, 1), frameStr.c_str());
	}
	ImGui::End();
}

//trVec texturerect�� ���� name�� â�� �̸���
void Gui::TextureRectGUIS(vector<class TextureRect*>& trVec, const char * name)//TextureRect�� gui �۾��� ó���ϴ� �Լ�
{
	if (trVec.size() <= 0)
	{
		return;
	}
	bool temp = true;
	if (ImGui::Begin(name), &temp)
	{
		for (UINT i = 0; i < trVec.size(); i++)
		{
			trVec[i]->GUI(i);
		}
	}
	ImGui::End();
}

void Gui::Update()
{
	ImGui_ImplDX11_NewFrame();//���콺 / Ű���� ������ ������Ʈ
	ImGui_ImplWin32_NewFrame();//Win32 �޽��� ó���� ������ ������Ʈ

	ImGui::NewFrame();//�� ImGui �������� �����մϴ�.�� �������� Render () / EndFrame ()���� ��� ������ ������ �� �ֽ��ϴ�.

}

void Gui::Render()
{
	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	ImGuiIO & io = ImGui::GetIO();
	if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
	{
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
	}
}

Gui::Gui()
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();

	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	//�ڵ�� dc�� device�� �Ѱ���
	ImGui_ImplWin32_Init(handle);
	ImGui_ImplDX11_Init(DEVICE, DC);

	ApplyStyle();
}

Gui::~Gui()
{//�Ҹ��ڿ��� ����
	ImGui_ImplDX11_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();

}

void Gui::ApplyStyle()//gui ���� ����
{
	ImGui::GetIO().ConfigWindowsResizeFromEdges = true;
	ImGui::StyleColorsDark();
	ImGuiStyle& style = ImGui::GetStyle();

	float fontSize = 15.0f;
	float roundness = 2.0f;
	ImVec4 white = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
	ImVec4 text = ImVec4(0.76f, 0.77f, 0.8f, 1.0f);
	ImVec4 black = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
	ImVec4 backgroundVeryDark = ImVec4(0.08f, 0.086f, 0.094f, 1.0f);
	ImVec4 backgroundDark = ImVec4(0.117f, 0.121f, 0.145f, 1.0f);
	ImVec4 backgroundMedium = ImVec4(0.26f, 0.26f, 0.27f, 1.0f);
	ImVec4 backgroundLight = ImVec4(0.37f, 0.38f, 0.39f, 1.0f);
	ImVec4 highlightBlue = ImVec4(0.172f, 0.239f, 0.341f, 1.0f);
	ImVec4 highlightBlueHovered = ImVec4(0.202f, 0.269f, 0.391f, 1.0f);
	ImVec4 highlightBlueActive = ImVec4(0.382f, 0.449f, 0.561f, 1.0f);
	ImVec4 barbackground = ImVec4(0.078f, 0.082f, 0.09f, 1.0f);
	ImVec4 bar = ImVec4(0.164f, 0.180f, 0.231f, 1.0f);
	ImVec4 barHovered = ImVec4(0.411f, 0.411f, 0.411f, 1.0f);
	ImVec4 barActive = ImVec4(0.337f, 0.337f, 0.368f, 1.0f);

	style.WindowBorderSize = 1.0f;
	style.FrameBorderSize = 1.0f;
	style.FramePadding = ImVec2(5, 5);
	style.ItemSpacing = ImVec2(6, 5);
	style.Alpha = 1.0f;
	style.WindowRounding = roundness;
	style.FrameRounding = roundness;
	style.PopupRounding = roundness;
	style.GrabRounding = roundness;
	style.ScrollbarSize = 20.0f;
	style.ScrollbarRounding = roundness;

	style.Colors[ImGuiCol_Text] = text;
	style.Colors[ImGuiCol_WindowBg] = backgroundDark;
	style.Colors[ImGuiCol_Border] = black;
	style.Colors[ImGuiCol_FrameBg] = bar;
	style.Colors[ImGuiCol_FrameBgHovered] = highlightBlue;
	style.Colors[ImGuiCol_FrameBgActive] = highlightBlueHovered;
	style.Colors[ImGuiCol_TitleBg] = backgroundVeryDark;
	style.Colors[ImGuiCol_MenuBarBg] = backgroundVeryDark;
	style.Colors[ImGuiCol_ScrollbarBg] = barbackground;
	style.Colors[ImGuiCol_ScrollbarGrab] = bar;
	style.Colors[ImGuiCol_ScrollbarGrabHovered] = barHovered;
	style.Colors[ImGuiCol_ScrollbarGrabActive] = barActive;
	style.Colors[ImGuiCol_CheckMark] = white;
	style.Colors[ImGuiCol_SliderGrab] = bar;
	style.Colors[ImGuiCol_SliderGrabActive] = barActive;
	style.Colors[ImGuiCol_Button] = barActive;
	style.Colors[ImGuiCol_ButtonHovered] = highlightBlue;
	style.Colors[ImGuiCol_ButtonActive] = highlightBlueActive;
	style.Colors[ImGuiCol_Header] = highlightBlue;
	style.Colors[ImGuiCol_HeaderHovered] = highlightBlueHovered;
	style.Colors[ImGuiCol_HeaderActive] = highlightBlueActive;
	style.Colors[ImGuiCol_Separator] = backgroundLight;
	style.Colors[ImGuiCol_ResizeGrip] = backgroundMedium;
	style.Colors[ImGuiCol_ResizeGripHovered] = highlightBlue;
	style.Colors[ImGuiCol_ResizeGripActive] = highlightBlueHovered;
	style.Colors[ImGuiCol_PlotLines] = ImVec4(0.0f, 0.7f, 0.77f, 1.0f);
	style.Colors[ImGuiCol_PlotHistogram] = highlightBlue;
	style.Colors[ImGuiCol_PlotHistogramHovered] = highlightBlueHovered;
	style.Colors[ImGuiCol_TextSelectedBg] = highlightBlue;
	style.Colors[ImGuiCol_PopupBg] = highlightBlue;
	style.Colors[ImGuiCol_DragDropTarget] = backgroundLight;

}