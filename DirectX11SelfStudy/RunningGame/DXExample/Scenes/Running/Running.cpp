#include "stdafx.h"
#include "Running.h"

Running::Running()
{
}

Running::~Running()
{
}

void Running::Init()
{
	startTime = clock();
	CPlayer = new Player(Vector3(150, 50, 0), Vector3(100, 100, 1), 0);
	CSpawnManager = new EnemyManager;
}

void Running::Update()
{
	static float speed = 3;
	speed += 0.001;
	for (Enemy* tempEnemy : CSpawnManager->GetEnemyList())
	{
		if (tempEnemy != nullptr)
		{
			if (Math::Intersect(CPlayer, tempEnemy))
			{
				wstring title = L"���� : ";
				wstring scoreStr = to_wstring(score);
				title += scoreStr;
				MessageBox(handle,title.c_str(), L"���� ����", MB_OK);
				SendMessage(handle, WM_CLOSE, 0, 0);
			}
			tempEnemy->SetSpeed(-speed);
			tempEnemy->Update();
			if (tempEnemy->GetLB().z<0)
			{
				CSpawnManager->ReplaceEnemy(tempEnemy);
			}
		}
	}
	CPlayer->Update();
}

void Running::PreRender()
{
}

void Running::Render()
{
	CPlayer->Render();
	for (Enemy* tempEnemy : CSpawnManager->GetEnemyList())
	{
		if (tempEnemy != nullptr)
		{
			tempEnemy->Render();
		}
	}
}

void Running::PostRender()
{
	endTime = clock();
	score = (endTime - startTime) / 100;
	bool temp = true; //�⺻���� �ٲٱ� ���ؼ� bool ������ �Ѱ������ ���� false�� �ѱ�� �ȳ���
	ImGui::SetNextWindowPos({ WinMaxWidth - 150,20 });//���� �������� ������ ����//���ܿ� ���
	if (ImGui::Begin("Score", &temp, ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoTitleBar| ImGuiWindowFlags_NoResize))//guiâ �ϳ��� ���ڴ�
	{//Ÿ��Ʋ �� ���� ��浵 ����
		string ScoreStr = "SCORE : " + to_string(score);//������ ����Ʈ �޾ƿ�
		ImGui::TextColored(ImVec4(1, 1, 1, 1), ScoreStr.c_str());
	}
	ImGui::End();
}
