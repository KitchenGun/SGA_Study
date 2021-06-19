#include "stdafx.h"
#include "Program.h"

Program::Program()
{
	//view projection ���� 
	VPBuffer = new ViewProjectionBuffer();
	//���� �ʱ�ȭ
	SetGlobalBuffers();
	//�����Ŵ��� ����
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
	//view projection ����
	//ó�� �����ϰ� �ٲ��� ����
	D3DXMatrixIdentity(&view);
	D3DXMatrixIdentity(&projection);
	//�޼���ǥ��
	D3DXMatrixLookAtLH(&view, &D3DXVECTOR3(0, 0, 0), &D3DXVECTOR3(0, 0, 1), &D3DXVECTOR3(0, 1, 0));
	//���ϴ��� �������� ����
	D3DXMatrixOrthoOffCenterLH(&projection, 0, WinMaxWidth, 0, WinMaxHeight, 0, 1);
	//��ġ
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
				cout << "�浹��" << temp++ << endl;
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
	//world�� �и��߱� ������ 1�̴�
	VPBuffer->SetVSBuffer(1);
	//square �ȿ��� wb 0�� ���� 0�� �־����
	player->Render();
	for (Enemy* enemy : SpawnM->GetEnemyList())
	{
		if (enemy != nullptr)
		{
			enemy->Render();
		}
	}
}