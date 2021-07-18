#pragma once
class Player : public TextureRect
{
public:
	Player(Vector3 position, Vector3 size, float rotation,bool isPlayer);
	~Player();


	void Fire();
	void MoveBarrel();
	void BulletUpdate();
	void Update() override;
	void Render() override;
	bool GetIsFire() { return isFire; }
	void SetIsFire(bool val) { isFire = val; }
private:
	bool isPlayer;
	bool isFire;
	Line* CBarrel;
	GaugeBar* CGaugeBar;
	ProjectileManager* CPjManager;
	//발사 파워
	float fFirePower=0.0f;
	//발사 사운드
	SoundSystem* FireSFX;
	
};