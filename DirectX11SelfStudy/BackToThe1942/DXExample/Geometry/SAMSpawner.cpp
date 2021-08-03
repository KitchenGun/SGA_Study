#include "stdafx.h"
#include "SAMSpawner.h"
/*
135	1163
///////////////////
/115	1570
/140	1430
/190	1375
/115	1300-
/220	1160
//전투기 출현 라인
/20	1025
/120	995
/250	935
/165	825
/120	825
/190	750
/120	670
/35	670
/175	450
/135	450
/120	400
/250	345
/240	180
/173	180
/120	180
20	150
60 	150
*/
SAMSpawner::SAMSpawner(Player* Target, BulletManager* EnemyBM)
	:Target(Target),
	EnemyBM(EnemyBM)
{

	AddSAM(Vector3(-20 * 5, -406 * 5, 0));
	AddSAM(Vector3(5 * 5, -266 * 5, 0));
	AddSAM(Vector3(55 * 5, -211 * 5, 0));
	AddSAM(Vector3(-20 * 5, -136 * 5, 0));
	AddSAM(Vector3(85 * 5, 5 * 5, 0));
	//전투기 출현라인
	AddSAM(Vector3(-115 * 5, 130 * 5, 0));
	AddSAM(Vector3(-15 * 5, 160 * 5, 0));
	AddSAM(Vector3(115 * 5, 220 * 5, 0));
	AddSAM(Vector3(30 * 5, 330 * 5, 0));
	AddSAM(Vector3(-15 * 5, 330 * 5, 0));
	AddSAM(Vector3(55 * 5, 405 * 5, 0));
	AddSAM(Vector3(-60 * 5, 485 * 5, 0));
	AddSAM(Vector3(-10 * 5, 485 * 5, 0));
	AddSAM(Vector3(55 * 5, 705 * 5, 0));
	AddSAM(Vector3(0 * 5, 705 * 5, 0));
	AddSAM(Vector3(115 * 5, 810 * 5, 0));
	AddSAM(Vector3(105 * 5, 975 * 5, 0));
	AddSAM(Vector3(35 * 5, 975 * 5, 0));
	AddSAM(Vector3(-15 * 5, 975 * 5, 0));
	AddSAM(Vector3(-115 * 5, 1005 * 5, 0));
	AddSAM(Vector3(-75 * 5, 1005 * 5, 0));
}

SAMSpawner::~SAMSpawner()
{
	SAFE_DELETE(temp);
	for (SAM* temp : oSAMList)
	{
		SAFE_DELETE(temp);
	}
}

void SAMSpawner::Update()
{
	for (SAM* temp : oSAMList)
	{
		if (temp != nullptr)
		{
			temp->Update();
		}
	}

}

void SAMSpawner::Render()
{
	for (SAM* temp : oSAMList)
	{
		if (temp != nullptr)
		{
			temp->Render();
		}
	}
}

void SAMSpawner::AddSAM(Vector3 SpawnPos)
{
	temp = new SAM(SpawnPos, Vector3(100, 100, 1), 0);
	temp->SetTarget(Target);
	temp->SetEnemyBM(EnemyBM);
	oSAMList.push_back(temp);
}

void SAMSpawner::RemoveSAM(SAM* Target)
{
	for (itSAMList = oSAMList.begin(); itSAMList != oSAMList.end(); ++itSAMList)
	{
		if (*itSAMList == Target)
		{
			itSAMList = oSAMList.erase(itSAMList);
			break;
		}
	}
}
