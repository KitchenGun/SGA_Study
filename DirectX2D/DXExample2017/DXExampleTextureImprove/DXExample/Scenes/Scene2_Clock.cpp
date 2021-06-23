#include "stdafx.h"
#include "Scene2_Clock.h"

Scene2::Scene2()
{
}

Scene2::~Scene2()
{

	SAFE_DELETE(Hour);
	SAFE_DELETE(Min);
	SAFE_DELETE(Sec);
}

void Scene2::Init()
{
	Hour = new Line({ Vector3(WinMaxWidth / 2,WinMaxHeight / 2,0),WinMaxHeight / 4 ,0,Red });
	Min = new Line({ Vector3(WinMaxWidth / 2,WinMaxHeight / 2,0),WinMaxHeight / 3 ,0,Green });
	Sec = new Line({ Vector3(WinMaxWidth / 2,WinMaxHeight / 2,0),WinMaxHeight / 2.5f ,0,Blue });
	clock = new Circle({ Vector3(WinMaxWidth / 2,WinMaxHeight / 2,0),Vector3(WinMaxHeight / 2.3f,WinMaxHeight / 2.3f,1),100,White });
}

void Scene2::Update()
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
	cout << endl;

	//90를 돌려서 12시 방향으로 맞춰 놓고
	/*
		시간은	12*30 =360
		분은		60*6  =360
		초는		60*6  =360
		이렇게 생각하면 수동적으로 움직이는 값이 나온다.
		//나누는 이유는 자연스러운 움직임 구현을 위해서 시침의 회전에 분과 초 밀리초를 더해서 나눠줘야한다 분침과 초침 역시 마찬가지다
	*/
	Hour->Rotation(90 - time.wHour* 30.0f - time.wMinute * 30.0f / 60.0f - time.wSecond * 30.0f / 60.0f / 60.0f - time.wMilliseconds * 30.0f / 60.0f / 60.0f / 1000.0f);
	Min->Rotation(90 - time.wMinute * 6.0f - time.wSecond * 6.0f / 60.0f - time.wMilliseconds * 6.0f / 60.0f / 1000.0f);
	Sec->Rotation(90 - time.wSecond * 6 - time.wMilliseconds * 6.0f / 1000.0f);
	//Update
	Sec->Update();
	Min->Update();
	Hour->Update();
	clock->Update();
}

void Scene2::Render()
{
	Sec->Render();
	Min->Render();
	Hour->Render();
	clock->Render();
}
