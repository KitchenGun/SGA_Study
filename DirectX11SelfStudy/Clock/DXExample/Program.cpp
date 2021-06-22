#include "stdafx.h"
#include "Program.h"

Program::Program()
{
	//view projection 버퍼 
	VPBuffer = new ViewProjectionBuffer();
	//버퍼 초기화
	SetGlobalBuffers();
	Hour = new Line({ Vector3(WinMaxWidth / 2,WinMaxHeight / 2,0),WinMaxHeight / 4 ,0,Red });
	Min = new Line({ Vector3(WinMaxWidth / 2,WinMaxHeight / 2,0),WinMaxHeight / 3 ,0,Green });
	Sec = new Line({ Vector3(WinMaxWidth / 2,WinMaxHeight / 2,0),WinMaxHeight / 2.5f ,0,Blue });
}

Program::~Program()
{
	SAFE_DELETE(Hour);
	SAFE_DELETE(Min);
	SAFE_DELETE(Sec);

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
	GetLocalTime(&time);//시스템 타임 변수에 현재시간을 불러오는 역할

	//cout << time.wYear << "년";
	//cout << time.wMonth << "월";
	//cout << time.wDay << "일";
	//switch (time.wDayOfWeek)
	//{
	//case 0:
	//	cout << "일요일";
	//	break;
	//case 1:
	//	cout << "월요일";
	//	break;
	//case 2:
	//	cout << "화요일";
	//	break;
	//case 3:
	//	cout << "수요일";
	//	break;
	//case 4:
	//	cout << "목요일";
	//	break;
	//case 5:
	//	cout << "금요일";
	//	break;
	//case 6:
	//	cout << "토요일";
	//	break;
	//default:
	//	break;
	//}
	cout << time.wHour << "시";
	cout << time.wMinute << "분";
	cout << time.wSecond << "초.";
	cout << time.wMilliseconds << "";
	cout<<endl;

	
	Hour->Rotation(90 - time.wHour* 30.0f - time.wMinute * 30.0f / 60.0f - time.wSecond * 30.0f / 60.0f/ 60.0f - time.wMilliseconds * 30.0f / 60.0f / 60.0f/ 1000.0f);
	Min->Rotation(90 - time.wMinute * 6.0f - time.wSecond * 6.0f / 60.0f  - time.wMilliseconds * 6.0f / 60.0f / 1000.0f);
	Sec->Rotation(90 - time.wSecond * 6- time.wMilliseconds * 6.0f / 1000.0f);
	//Update
	Sec->Update();
	Min->Update();
	Hour->Update();
}

void Program::Render()
{
	//world와 분리했기 때문에 1이다
	VPBuffer->SetVSBuffer(1);
	//square 안에는 wb 0에 슬롯 0을 넣어놨다
	Sec->Render();
	Min->Render();
	Hour->Render();

}
