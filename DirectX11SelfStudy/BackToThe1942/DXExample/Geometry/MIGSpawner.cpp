#include "stdafx.h"
#include "MIGSpawner.h"

MIGSpawner::MIGSpawner(BulletManager* EnemyBM)
	:
	EnemyBM(EnemyBM)
{

}

MIGSpawner::~MIGSpawner()
{
	SAFE_DELETE(temp);
	for (Mig25* temp : oMIGList)
	{
		SAFE_DELETE(temp);
	}
}

void MIGSpawner::Update()
{
	for (Mig25* temp : oMIGList)
	{
		if (temp != nullptr)
		{
			temp->Update();
		}
	}

}

void MIGSpawner::Render()
{
	for (Mig25* temp : oMIGList)
	{
		if (temp != nullptr)
		{
			temp->Render();
		}
	}
}

void MIGSpawner::AddMIG(Vector3 SpawnPos)
{
	temp = new Mig25(SpawnPos+Vector3(0,500.0f,0), Vector3(80, 96, 1), 0);
	temp->SetEnemyBM(EnemyBM);
	oMIGList.push_back(temp);
}

void MIGSpawner::RemoveMIG(Mig25* Target)
{
	for (itMIGList = oMIGList.begin(); itMIGList != oMIGList.end(); ++itMIGList)
	{
		if (*itMIGList == Target)
		{
			itMIGList = oMIGList.erase(itMIGList);
			break;
		}
	}
}
