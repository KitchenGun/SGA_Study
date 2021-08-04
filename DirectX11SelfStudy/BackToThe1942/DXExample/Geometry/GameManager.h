#pragma once

class GameManager
{
public:
	GameManager(Player* player,BulletManager* playerBulletManager,BulletManager* enemyBulletManager,SAMSpawner* samSpawnManager,MIGSpawner* migSpawnManager);
	~GameManager();

	void Update();

private:
	Player* player;
	BulletManager* PBM;
	SAMSpawner* SSM;
	MIGSpawner* MSM;
	BulletManager* EBM;

private:
	float deltaTime = 0.0f;
	float SpawnRate = 1 / 0.3f;
private:
};