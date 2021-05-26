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

		desc.Usage = D3D11_USAGE_IMMUTABLE;//설명서에 적힌 용도 
		/*
		접근 방식에 대한 지정법   (자원 접근이 가능하면 데이터를 변경할수있다)
		D3D11_USAGE_DEFAULT	= gpu만 데이터 읽고 쓸수있다
		D3D11_USAGE_IMMUTABLE = gpu가 데이터를 읽기만 한다/cpu접근 마찬가지로 불가능/생성과 동시에 초기화를 해야한다/제일 빠르다
		D3D11_USAGE_DYNAMIC	= gpu 읽기 허용	/cpu 쓰기 허용  /맵 언맵을 사용해서 cpu에서 접근해서 수정이 가능함/cpu에서 한프레임당 한번씩 업데이트 필요한 자원에 사용
		D3D11_USAGE_STAGING	= gpu 메모리에서 cpu 메모리로 복사 허용   /속도가 제일 느림
		
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
