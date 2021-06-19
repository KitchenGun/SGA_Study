#include "stdafx.h"
#include "Program.h"

Program::Program()
{
	//view projection 버퍼 
	VPBuffer = new ViewProjectionBuffer();
	//버퍼 초기화
	SetGlobalBuffers();
	//스폰매니져 세팅
	SpawnM = new SpawnManager();

	player = new Player({ 200,200,0 }, { 100,100,1 }, 0);
}

Program::~Program()
{
	SAFE_DELETE(SpawnM);

	SAFE_DELETE(player);

	SAFE_DELETE(VPBuffer);
}

void Program::SetGlobalBuffers()
{	
	//view projection 세팅
	//처음 설정하고 바꾸지 않음
	D3DXMatrixIdentity(&view);
	D3DXMatrixIdentity(&projection);
	//왼손좌표계
	D3DXMatrixLookAtLH(&view, &D3DXVECTOR3(0, 0, 0), &D3DXVECTOR3(0, 0, 1), &D3DXVECTOR3(0, 1, 0));
	//좌하단이 원점으로 제작
	D3DXMatrixOrthoOffCenterLH(&projection, 0, WinMaxWidth, 0, WinMaxHeight, 0, 1);
	//전치
	VPBuffer->SetView(view);
	VPBuffer->SetProjection(projection);
}

void Program::Update()
{
	player->Update();
	for (Enemy* enemy : SpawnM->GetEnemyList())
	{
		if (enemy != nullptr)
		{
			enemy->Update();
			if (Math::Intersect(player, enemy))
			{
				player->SetIntersect(true);
				enemy->SetIntersect(true);
				cout << "충돌중" << temp++ << endl;
				SpawnM->ReplaceEnemy(enemy);
			}
			else
			{
				player->SetIntersect(false);
				enemy->SetIntersect(false);
			}
		}
	}
}

void Program::Render()
{
	//world와 분리했기 때문에 1이다
	VPBuffer->SetVSBuffer(1);
	//square 안에는 wb 0에 슬롯 0을 넣어놨다
	player->Render();
	for (Enemy* enemy : SpawnM->GetEnemyList())
	{
		if (enemy != nullptr)
		{
			enemy->Render();
		}
	}
}