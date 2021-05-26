#include "stdafx.h"
#include "Program.h"

Program::Program()
{
	//vertexdata
	{
		vertices = new VertexColor[2];
		vertices[0].position = D3DXVECTOR3(-0.5f, -0.5f, 0.0f);
		vertices[0].color = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
		vertices[1].position = D3DXVECTOR3(-0.5f, 0.5f, 0.0f);
		vertices[1].color = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
		
	}
	//vertex buffer
	{
		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));

		desc.Usage = D3D11_USAGE_IMMUTABLE;//������ ���� �뵵 
		/*
		���� ��Ŀ� ���� ������   (�ڿ� ������ �����ϸ� �����͸� �����Ҽ��ִ�)
		D3D11_USAGE_DEFAULT	= gpu�� ������ �а� �����ִ�
		D3D11_USAGE_IMMUTABLE = gpu�� �����͸� �б⸸ �Ѵ�/cpu���� ���������� �Ұ���/������ ���ÿ� �ʱ�ȭ�� �ؾ��Ѵ�/���� ������
		D3D11_USAGE_DYNAMIC	= gpu �б� ���	/cpu ���� ���  /�� ����� ����ؼ� cpu���� �����ؼ� ������ ������/cpu���� �������Ӵ� �ѹ��� ������Ʈ �ʿ��� �ڿ��� ���
		D3D11_USAGE_STAGING	= gpu �޸𸮿��� cpu �޸𸮷� ���� ���   /�ӵ��� ���� ����
		
		*/
	}
}

Program::~Program()
{

}

void Program::Update()
{
	
}

void Program::Render()
{

}
