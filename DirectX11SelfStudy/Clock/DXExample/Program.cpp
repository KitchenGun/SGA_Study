#include "stdafx.h"
#include "Program.h"

Program::Program()
{
	//view projection ���� 
	VPBuffer = new ViewProjectionBuffer();
	//���� �ʱ�ȭ
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
	//world�� �и��߱� ������ 1�̴�
	VPBuffer->SetVSBuffer(1);
	//square �ȿ��� wb 0�� ���� 0�� �־����
	Sec->Render();
	Min->Render();
	Hour->Render();

}
