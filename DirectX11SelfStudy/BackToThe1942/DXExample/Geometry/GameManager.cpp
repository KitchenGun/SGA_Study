#include "stdafx.h"
#include "GameManager.h"

GameManager::GameManager(Player* player, BulletManager* playerBulletManager, BulletManager* enemyBulletManager, SAMSpawner* samSpawnManager, MIGSpawner* migSpawnManager)
	:player(player),
	PBM(playerBulletManager),
	EBM(enemyBulletManager),
	SSM(samSpawnManager),
	MSM(migSpawnManager)
{
	Specker = new SoundSystem();
	Specker->CreateEffSound("_Sounds/Scene1/Carrier/1.wav");
	Specker->Play();
}

GameManager::~GameManager()
{
	SAFE_DELETE(player);
}

void GameManager::Update()
{
	
	Specker->Update();
	if (isCarrierTakeOff != true)
	{
		if (Specker->GetbPlaying() == false)
		{
			++scriptIndex;
			SetSoundPath(scriptIndex);
		}
	}
	else
	{
		if (isSiren == true)
		{
			if (deltaTime > sirenRate)//일정 시간 마다 실행함 
			{
				Specker->Stop();
				isSiren = false;
			}
			else//작동환경과 상관없이 일정하게 맞춰준다
			{
				deltaTime += Time::Delta();

				if (Specker->GetbPlaying() == false)
				{
					SetSoundPath("_Sounds/SFX/siren.wav");
					Specker->SetLoop(false);
				}
			}
		}
	}
	/*
	1. 충돌 처리
	//플레이어:미사일
	//총알:적 투사체
	//총알:적 mig
	//적 총알:플레이어
	2. 미그기 스폰
	특정 y축일 경우에 스폰
	3. 플레이어의 이동 제한
	4. 대사 처리

	*/

	//플레이어와 적의 투사체 충돌 처리
	for (Bullet* tempBullet : EBM->GetProjectileList())
	{
		if (tempBullet != nullptr)
		{//객체가 존재할 경우
			if (Math::Intersect(player, tempBullet))
			{
				EBM->RemoveProjectile(tempBullet);
				Lose();
			}
		}
	}

	//플레이어의 투사체와 적의 투사체 충돌 처리
	for (Bullet* tempBullet : PBM->GetProjectileList())
	{
		if (tempBullet != nullptr)
		{
			for (Bullet* tempEBullet : EBM->GetProjectileList())
			{
				if (tempEBullet != nullptr)
				{//객체가 존재할 경우
					if (Math::Intersect(tempBullet, tempEBullet))
					{
						PBM->RemoveProjectile(tempBullet);
						EBM->RemoveProjectile(tempEBullet);
					}
				}
			}
		}
	}

	//플레이어의 투사체와 적의 sam 충돌 처리
	for (Bullet* tempBullet : PBM->GetProjectileList())
	{
		if (tempBullet != nullptr)
		{
			for (SAM* tempSAM : SSM->GetSAMList())
			{
				if (tempSAM != nullptr)
				{//객체가 존재할 경우
					if (Math::Intersect(tempBullet, tempSAM))
					{
						PBM->RemoveProjectile(tempBullet);
						SSM->RemoveSAM(tempSAM);
					}
				}
			}
		}
	}
	
	//플레이어와 적 전투기 충돌 처리
	for (Mig25* temp : MSM->GetMIGList())
	{
		if (temp != nullptr)
		{//객체가 존재할 경우
			if (Math::Intersect(player, temp))
			{
				MSM->RemoveMIG(temp);
				Lose();
			}
		}
	}

	//플레이어의 투사체와 적의 전투기 충돌 처리
	for (Bullet* tempBullet : PBM->GetProjectileList())
	{
		if (tempBullet != nullptr)
		{
			for (Mig25* temp : MSM->GetMIGList())
			{
				if (temp != nullptr)
				{//객체가 존재할 경우
					if (Math::Intersect(tempBullet, temp))
					{
						PBM->RemoveProjectile(tempBullet);
						MSM->RemoveMIG(temp);
					}
				}
			}
		}
	}

	//미그기 스폰
	if (player->GetPosition().y >= 0)
	{
		if (!isTargetAllDown)
		{
			if (deltaTime > SpawnRate)
			{
				MSM->AddMIG(player->GetPosition());
				deltaTime = 0.0f;
			}
			else
				deltaTime += Time::Delta();
		}
	}
}

void GameManager::SetSoundPath(string path)
{
	Specker->ChangeSoundFunc(String::ToWString(path));
	Specker->Play();
}

void GameManager::SetSoundPath(int index)
{
	switch (index)
	{
	case 1:
	{
		Specker->ChangeSoundFunc(L"_Sounds/Scene1/Carrier/2.wav");
		Specker->Play();
		break;
	}
	case 2:
	{
		Specker->CreateEffSound("_Sounds/Scene1/Carrier/3.wav");
		Specker->Play();
		break;
	}
	case 3:
	{
		Specker->CreateEffSound("_Sounds/Scene1/Carrier/4.wav");
		Specker->Play(); 
		break;
	}
	case 4:
	{
		Specker->CreateEffSound("_Sounds/Scene1/Carrier/5.wav");
		Specker->Play(); 
		break;
	}
	case 5:
	{
		Specker->CreateEffSound("_Sounds/Scene1/Carrier/6.wav");
		Specker->Play();
		break;
	}
	case 6:
	{
		Specker->CreateEffSound("_Sounds/Scene1/Carrier/7.wav");
		Specker->Play();
		break;
	}
	case 7:
	{
		Specker->CreateEffSound("_Sounds/Scene1/Carrier/8.wav");
		Specker->Play();
		isCarrierTakeOff = true;
		break;
	}
	case 21:
		Specker->ChangeSoundFunc(String::ToWString("_Sounds/Scene1/End/Win/That's a kill, good job! no one else left.wav"));
		Specker->Play();
		break;
	case 22:
		Specker->ChangeSoundFunc(String::ToWString("_Sounds/Scene1/End/Win/Mobius 1 destroyed the yellows, we have air superiority.wav"));
		Specker->Play();
		break;
	case 23:
		Specker->ChangeSoundFunc(String::ToWString("_Sounds/Scene1/End/Win/Mission complete, all aircraft RTB!.wav"));
		Specker->Play();

		MessageBox(handle, L"미션 종료", L"승리", MB_OK);
		SendMessage(handle, WM_CLOSE, 0, 0);
		break;

	case 31:
		Specker->ChangeSoundFunc(String::ToWString("_Sounds/Scene1/End/Lose/Mobius 1 crashed!.wav"));
		Specker->Play();
		break;
	case 32:
		Specker->ChangeSoundFunc(String::ToWString("_Sounds/Scene1/End/Lose/Target still operational, mission failed, all aircraft RTB.wav"));
		Specker->Play();

		MessageBox(handle, L"미션 종료", L"패배", MB_OK);
		SendMessage(handle, WM_CLOSE, 0, 0);
		break;
	default:
		if(index>=7)
			isCarrierTakeOff = false;
		break;
	}
}

void GameManager::MissileInComing()
{
	random_device rd;
	uniform_int_distribution<int> index(0, 10);
	switch (index(rd))
	{
	case 0:
		Specker->ChangeSoundFunc(String::ToWString("_Sounds/Scene1/Enemy/Missile/Break, missile!.wav"));
		Specker->Play();
		break;
	case 1:
		Specker->ChangeSoundFunc(String::ToWString("_Sounds/Scene1/Enemy/Missile/Missile warning!.wav"));
		Specker->Play();
		break;
	case 2:
		Specker->ChangeSoundFunc(String::ToWString("_Sounds/Scene1/Enemy/Missile/Missile, break!.wav"));
		Specker->Play();
		break;
	case 3:
		Specker->ChangeSoundFunc(String::ToWString("_Sounds/Scene1/Enemy/Missile/More missiles inbound, shoot them all down!.wav"));
		Specker->Play();
		break;
	case 4:
		Specker->ChangeSoundFunc(String::ToWString("_Sounds/Scene1/Enemy/Missile/Warning inbound missile.wav"));
		Specker->Play();
		break;
	case 5:
		Specker->ChangeSoundFunc(String::ToWString("_Sounds/Scene1/Enemy/Missile/Warning missile.wav"));
		Specker->Play();
		break;
	default:
		break;
	}
}

void GameManager::MissileDestroy()
{
	random_device rd;
	uniform_int_distribution<int> index(0, 10);
	switch (index(rd))
	{
	case 0:
		Specker->ChangeSoundFunc(String::ToWString("_Sounds/Scene1/Enemy/Missile/Destroy/Nice shooting missile goes down!.wav"));
		Specker->Play();
		break;
	default:
		break;
	}
}

void GameManager::SAMDestroy()
{
	random_device rd;
	uniform_int_distribution<int> index(0, 10);
	switch (index(rd))
	{
	case 0:
		Specker->ChangeSoundFunc(String::ToWString("_Sounds/Scene1/Enemy/SAM/SAM destroyed!.wav"));
		Specker->Play();
		break;
	case 1:
		Specker->ChangeSoundFunc(String::ToWString("_Sounds/Scene1/Enemy/SAM/SAM destroyed.wav"));
		Specker->Play();
		break;
	default:
		break;
	}
}

void GameManager::SAMDestroy(int size)
{
	switch (size)
	{
	case 0:
		Specker->ChangeSoundFunc(String::ToWString("_Sounds/SFX/END.wav"));
		Specker->Play();
		Win();
		isTargetAllDown = true;
		break;
	case 1:
		Specker->ChangeSoundFunc(String::ToWString("_Sounds/Scene1/Enemy/SAM/1 target remaining.wav"));
		Specker->Play();
		break;
	case 2:
		Specker->ChangeSoundFunc(String::ToWString("_Sounds/Scene1/Enemy/SAM/2 targets remaining.wav"));
		Specker->Play();
		break;
	case 3:
		Specker->ChangeSoundFunc(String::ToWString("_Sounds/Scene1/Enemy/SAM/3 targets remaining.wav"));
		Specker->Play();
		break;
	case 4:
		Specker->ChangeSoundFunc(String::ToWString("_Sounds/Scene1/Enemy/SAM/4 targets remaining.wav"));
		Specker->Play();
		break;
	case 5:
		Specker->ChangeSoundFunc(String::ToWString("_Sounds/Scene1/Enemy/SAM/5 targets remaining.wav"));
		Specker->Play();
		break;

	default:
		break;
	}
}

void GameManager::MIGDestroy()
{
	random_device rd;
	uniform_int_distribution<int> index(0, 10);
	switch (index(rd))
	{
	case 0:
		Specker->ChangeSoundFunc(String::ToWString("_Sounds/Scene1/Enemy/MIG/Destroy/Nice kill.wav"));
		Specker->Play();
		break;
	case 1:
		Specker->ChangeSoundFunc(String::ToWString("_Sounds/Scene1/Enemy/MIG/Destroy/Nice shooting!.wav"));
		Specker->Play();
		break;
	case 2:
		Specker->ChangeSoundFunc(String::ToWString("_Sounds/Scene1/Enemy/MIG/Destroy/Nyce kill.wav"));
		Specker->Play();
		break;
	case 3:
		Specker->ChangeSoundFunc(String::ToWString("_Sounds/Scene1/Enemy/MIG/Destroy/TARGET DESTROYED!!!.wav"));
		Specker->Play();
		break;
	case 4:
		Specker->ChangeSoundFunc(String::ToWString("_Sounds/Scene1/Enemy/MIG/Destroy/Target downed.wav"));
		Specker->Play();
		break;
	case 5:
		Specker->ChangeSoundFunc(String::ToWString("_Sounds/Scene1/Enemy/MIG/Destroy/Target is above operations airspace!.wav"));
		Specker->Play();
		break;
	case 6:
		Specker->ChangeSoundFunc(String::ToWString("_Sounds/Scene1/Enemy/MIG/Destroy/Target is silenced.wav"));
		Specker->Play();
		break;
	default:
		break;
	}
}

void GameManager::Win()
{
	isCarrierTakeOff = false;
	scriptIndex = 20;
}

void GameManager::Lose()
{
	player->SetisRender(false);
	isCarrierTakeOff = false;
	scriptIndex = 30;
}
