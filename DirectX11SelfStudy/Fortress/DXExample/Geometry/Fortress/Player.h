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
	//�߻� �Ŀ�
	float fFirePower=0.0f;
	//�߻� ����
	SoundSystem* FireSFX;
	
};