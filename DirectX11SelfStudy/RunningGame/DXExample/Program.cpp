#include "stdafx.h"
#include "Scenes/SceneList.h"
#include "Program.h"

Program::Program()
{
	//view projection 버퍼 
	VPBuffer = new ViewProjectionBuffer();
	//버퍼 초기화
	SetGlobalBuffers();
	
}

Program::~Program()
{
	SAFE_DELETE(VPBuffer);
}

void Program::Init()
{
	sceneList.push_back(new Running());
	currentScene = sceneList[0];
	currentScene->Init();
}

void Program::SetGlobalBuffers()
{	
	//view projection 세팅
	//처음 설정하고 바꾸지 않음
	D3DXMatrixIdentity(&view);
	D3DXMatrixIdentity(&projection);
	//왼손좌표계
	D3DXMatrixLookAtLH(&view, &Vector3(0, 0, 0), &Vector3(0, 0, 1), &Vector3(0, 1, 0));
	//좌하단이 원점으로 제작
	D3DXMatrixOrthoOffCenterLH(&projection, 0, WinMaxWidth, 0, WinMaxHeight, 0, 1);
	//전치
	VPBuffer->SetView(view);
	VPBuffer->SetProjection(projection);
}

void Program::Update()
{
	if (Keyboard::Get()->Down(VK_F1))
	{
		currentScene = sceneList[0];
		currentScene->Init();
	}
	currentScene->Update();
}




void Program::PreRender()
{
	//world와 분리했기 때문에 1이다
	VPBuffer->SetVSBuffer(1);
	currentScene->PreRender();
}

void Program::Render()
{
	currentScene->Render();
}

void Program::PostRender()
{
	Gui::Get()->PrintFrame();
	currentScene->PostRender();
}
