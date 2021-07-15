#include "stdafx.h"
#include "Scenes/SceneList.h"
#include "Program.h"

Program::Program()
{
	//view projection ���� 
	VPBuffer = new ViewProjectionBuffer();
	//���� �ʱ�ȭ
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
	//view projection ����
	//ó�� �����ϰ� �ٲ��� ����
	D3DXMatrixIdentity(&view);
	D3DXMatrixIdentity(&projection);
	//�޼���ǥ��
	D3DXMatrixLookAtLH(&view, &Vector3(0, 0, 0), &Vector3(0, 0, 1), &Vector3(0, 1, 0));
	//���ϴ��� �������� ����
	D3DXMatrixOrthoOffCenterLH(&projection, 0, WinMaxWidth, 0, WinMaxHeight, 0, 1);
	//��ġ
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
	//world�� �и��߱� ������ 1�̴�
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
