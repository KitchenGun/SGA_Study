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
	GetLocalTime(&time);//�ý��� Ÿ�� ������ ����ð��� �ҷ����� ����
	//cout << time.wYear << "��";
	//cout << time.wMonth << "��";
	//cout << time.wDay << "��";
	//switch (time.wDayOfWeek)
	//{
	//case 0:
	//	cout << "�Ͽ���";
	//	break;
	//case 1:
	//	cout << "������";
	//	break;
	//case 2:
	//	cout << "ȭ����";
	//	break;
	//case 3:
	//	cout << "������";
	//	break;
	//case 4:
	//	cout << "�����";
	//	break;
	//case 5:
	//	cout << "�ݿ���";
	//	break;
	//case 6:
	//	cout << "�����";
	//	break;
	//default:
	//	break;
	//}
	cout << time.wHour << "��";
	cout << time.wMinute << "��";
	cout << time.wSecond << "��.";
	cout << time.wMilliseconds << "";
	cout << endl;

	//90�� ������ 12�� �������� ���� ����
	/*
		�ð���	12*30 =360
		����		60*6  =360
		�ʴ�		60*6  =360
		�̷��� �����ϸ� ���������� �����̴� ���� ���´�.
		//������ ������ �ڿ������� ������ ������ ���ؼ� ��ħ�� ȸ���� �а� �� �и��ʸ� ���ؼ� ��������Ѵ� ��ħ�� ��ħ ���� ����������
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
