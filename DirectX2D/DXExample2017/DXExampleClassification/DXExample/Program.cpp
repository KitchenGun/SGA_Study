#include "stdafx.h"
#include "Program.h"

Program::Program()
{
	VPBuffer = new ViewProjectionBuffer();

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
	D3DXMatrixIdentity(&view);
	D3DXMatrixIdentity(&projection);

	D3DXMatrixLookAtLH(&view, &D3DXVECTOR3(0, 0, 0), &D3DXVECTOR3(0, 0, 1), &D3DXVECTOR3(0, 1, 0));
	D3DXMatrixOrthoOffCenterLH(&projection, 0, WinMaxWidth, 0, WinMaxHeight, 0, 1);

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
