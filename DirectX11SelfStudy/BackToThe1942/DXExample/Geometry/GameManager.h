#pragma once

class GameManager
{
public:
	GameManager(Player* player,BulletManager* playerBulletManager,BulletManager* enemyBulletManager,SAMSpawner* samSpawnManager);
	~GameManager();

	void Update();

private:
	Player* player;
	BulletManager* PBM;
	SAMSpawner* SSM;
	BulletManager* EBM;
};