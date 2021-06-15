#include "stdafx.h"
#include "Program.h"

Program::Program()
{
	//view projection 버퍼 
	VPBuffer = new ViewProjectionBuffer();
	//버퍼 초기화
	SetGlobalBuffers();
	square = new Square({ 200,200,0 }, { 100,100,1 }, 0);
}

Program::~Program()
{
	SAFE_DELETE(square);

	SAFE_DELETE(VPBuffer);
}

void Program::SetGlobalBuffers()
{	
	//버퍼 세팅
	//처음 설정하고 바꾸지 않음
	D3DXMatrixIdentity(&view);
	D3DXMatrixIdentity(&projection);
	//왼손좌표계
	D3DXMatrixLookAtLH(&view, &D3DXVECTOR3(0, 0, 0), &D3DXVECTOR3(0, 0, 1), &D3DXVECTOR3(0, 1, 0));
	//좌하단이 원점으로 제작
	D3DXMatrixOrthoOffCenterLH(&projection, 0, WinMaxWidth, 0, WinMaxHeight, 0, 1);
	//전치
	VPBuffer->SetView(view);
	VPBuffer->SetProjection(projection);
}

void Program::Update()
{
	square->Update();
}

void Program::Render()
{
	//world와 분리했기 때문에 1이다
	VPBuffer->SetVSBuffer(1);
	square->Render();
}
