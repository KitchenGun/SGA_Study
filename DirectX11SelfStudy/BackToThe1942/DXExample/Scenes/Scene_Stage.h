#pragma once

class Stage :public Scene
{
public:
	Stage();
	~Stage();

	void Init() override;
	void Update() override;
	void PreRender() override;
	void Render() override;
	void PostRender() override;

	void BulletUpdate(BulletManager* BM);
	void BulletRender(BulletManager* BM);
private:
	TextureRect* background=nullptr;
	Texture2D* mapTex=nullptr;
	Player* animRect=nullptr;
	PlayerAfterBurner* subAnimRect=nullptr;
private:
	//°ü¸®ÀÚ °´Ã¼
	SAMSpawner* SAMSites=nullptr;
	BulletManager* PlayerBM=nullptr;
	BulletManager* EnemyBM=nullptr;
	GameManager* GM=nullptr;
};