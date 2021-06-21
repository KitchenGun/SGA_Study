#include "stdafx.h"
#include "Program.h"

Program::Program()
{
	//view projection ���� 
	VPBuffer = new ViewProjectionBuffer();
	//���� �ʱ�ȭ
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
	GetLocalTime(&time);

	cout << time.wYear << "��";
	cout << time.wMonth << "��";
	cout << time.wDay << "��";
	switch (time.wDayOfWeek)
	{
	case 0:
		cout << "�Ͽ���";
		break;
	case 1:
		cout << "������";
		break;
	case 2:
		cout << "ȭ����";
		break;
	case 3:
		cout << "������";
		break;
	case 4:
		cout << "�����";
		break;
	case 5:
		cout << "�ݿ���";
		break;
	case 6:
		cout << "�����";
		break;
	default:
		break;
	}
	cout << time.wHour << "��";
	cout << time.wMinute << "��";
	cout << time.wSecond << "��.";
	cout << time.wMilliseconds << "";
	cout << endl;
	

	//�Է�
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
	//world�� �и��߱� ������ 1�̴�
	VPBuffer->SetVSBuffer(1);
	//square �ȿ��� wb 0�� ���� 0�� �־����
	//square->Render();
	//square2->Render();
	line->Render();

}
