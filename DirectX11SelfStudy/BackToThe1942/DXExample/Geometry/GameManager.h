#pragma once

class GameManager
{
public:
	GameManager(Player* player,BulletManager* playerBulletManager,BulletManager* enemyBulletManager,SAMSpawner* samSpawnManager,MIGSpawner* migSpawnManager);
	~GameManager();

	void Update();
	void SetSoundPath(string path);
	void SetSoundPath(int index);

	void MissileInComing();
	void MissileDestroy();
	void SAMDestroy();
	void SAMDestroy(int size);
	void MIGDestroy();

	void Win();
	void Lose();

private:
	Player* player;
	BulletManager* PBM;
	SAMSpawner* SSM;
	MIGSpawner* MSM;
	BulletManager* EBM;

private:
	float deltaTime = 0.0f;
	float SpawnRate = 1 / 0.3f;
	float sirenRate = 10.0f;
private:
	SoundSystem* Specker;
	int scriptIndex=0;
	bool isCarrierTakeOff = false;
	bool isSiren = true;
	bool isTargetAllDown = false;
};