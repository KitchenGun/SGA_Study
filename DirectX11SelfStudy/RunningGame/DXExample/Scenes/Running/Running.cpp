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
				wstring title = L"점수 : ";
				wstring scoreStr = to_wstring(score);
				title += scoreStr;
				MessageBox(handle,title.c_str(), L"게임 종료", MB_OK);
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
	bool temp = true; //기본값을 바꾸기 위해서 bool 변수를 넘겨줘야함 만약 false를 넘기면 안나옴
	ImGui::SetNextWindowPos({ WinMaxWidth - 150,20 });//다음 윈도우의 포지션 결정//우상단에 띄움
	if (ImGui::Begin("Score", &temp, ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoTitleBar| ImGuiWindowFlags_NoResize))//gui창 하나를 띄우겠다
	{//타이틀 바 없고 배경도 없음
		string ScoreStr = "SCORE : " + to_string(score);//프레임 레이트 받아옴
		ImGui::TextColored(ImVec4(1, 1, 1, 1), ScoreStr.c_str());
	}
	ImGui::End();
}
