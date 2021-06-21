#include "stdafx.h"
#include "Program.h"

Program::Program()
{
	//view projection 버퍼 
	VPBuffer = new ViewProjectionBuffer();
	//버퍼 초기화
	SetGlobalBuffers();
	square = new Square({ 200,200,0 }, { 100,100,1 }, 0, Red);
	square2 = new Square({ 400,400,0 }, { 100,100,1 }, 0, Red);
	line = new Line({ Vector3(WinMaxWidth / 2,WinMaxHeight / 2,0),WinMaxWidth / 2 ,0,Red });
}

Program::~Program()
{
	SAFE_DELETE(line);
	SAFE_DELETE(square2);
	SAFE_DELETE(square);

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
	GetLocalTime(&time);

	cout << time.wYear << "년";
	cout << time.wMonth << "월";
	cout << time.wDay << "일";
	switch (time.wDayOfWeek)
	{
	case 0:
		cout << "일요일";
		break;
	case 1:
		cout << "월요일";
		break;
	case 2:
		cout << "화요일";
		break;
	case 3:
		cout << "수요일";
		break;
	case 4:
		cout << "목요일";
		break;
	case 5:
		cout << "금요일";
		break;
	case 6:
		cout << "토요일";
		break;
	default:
		break;
	}
	cout << time.wHour << "시";
	cout << time.wMinute << "분";
	cout << time.wSecond << "초.";
	cout << time.wMilliseconds << "";
	cout << endl;
	

	//입력
	if (Keyboard::Get()->Press('W'))
		square->Move({ 0,10,0 });
	else if (Keyboard::Get()->Press('S'))
		square->Move({ 0,-10,0 });
	if (Keyboard::Get()->Press('A'))
		square->Move({ -10,0,0 });
	else if (Keyboard::Get()->Press('D'))
		square->Move({ 10,0,0 });

	square->Update();
	square2->Update();
	line->Update();

	if (Math::Intersect(square, square2))
	{
		//square->SetIntersect(true);
		square2->SetIntersect(true);
		square2->SetColor(Cyan);
	}
	else
	{
		//square->SetIntersect(false);
		square2->SetIntersect(false);
		square2->SetColor(Red);
	}

}

void Program::Render()
{
	//world와 분리했기 때문에 1이다
	VPBuffer->SetVSBuffer(1);
	//square 안에는 wb 0에 슬롯 0을 넣어놨다
	//square->Render();
	//square2->Render();
	line->Render();

}
