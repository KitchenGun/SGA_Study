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
	TextureRect* background;
	Texture2D* mapTex;
	Player* animRect;
	PlayerAfterBurner* subAnimRect;
private:
	SAMSpawner* SAMSites;
private:
	BulletManager* PlayerBM;
	BulletManager* EnemyBM;
};