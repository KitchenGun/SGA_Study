#include "stdafx.h"
#include "Program.h"

Program::Program()
{
	//view projection ���� 
	VPBuffer = new ViewProjectionBuffer();
	//���� �ʱ�ȭ
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
	
	box->Move(Math::Lerp(Vector3(0,0,0),Vector3(WinMaxWidth-100,WinMaxHeight-100,0),tempFrameCount));
	if (tempFrameCount < 1)
	{
		tempFrameCount = tempFrameCount + 0.001f;
		cout << "�̵���"<< tempFrameCount << endl;
	}
	else
	{
		cout << "����" << endl;
	}
	//Update
	box->Update();
}

void Program::Render()
{
	//world�� �и��߱� ������ 1�̴�
	VPBuffer->SetVSBuffer(1);
	//square �ȿ��� wb 0�� ���� 0�� �־����
	box->Render();

}
