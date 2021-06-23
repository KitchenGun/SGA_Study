#include "stdafx.h"
#include "Program.h"

Program::Program()
{
	//view projection 버퍼 
	VPBuffer = new ViewProjectionBuffer();
	//버퍼 초기화
	SetGlobalBuffers();
	box = new Square({ Vector3(0,0,0),Vector3(100 ,100,1),0,Red });
}

Program::~Program()
{
	SAFE_DELETE(box);

	SAFE_DELETE(VPBuffer);
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
	
	box->Move(Math::Lerp(Vector3(0,0,0),Vector3(WinMaxWidth-100,WinMaxHeight-100,0),tempFrameCount));
	if (tempFrameCount < 1)
	{
		tempFrameCount = tempFrameCount + 0.001f;
		cout << "이동중"<< tempFrameCount << endl;
	}
	else
	{
		cout << "정지" << endl;
	}
	//Update
	box->Update();
}

void Program::Render()
{
	//world와 분리했기 때문에 1이다
	VPBuffer->SetVSBuffer(1);
	//square 안에는 wb 0에 슬롯 0을 넣어놨다
	box->Render();

}
