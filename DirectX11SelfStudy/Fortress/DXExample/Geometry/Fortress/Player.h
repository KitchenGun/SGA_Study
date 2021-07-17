#pragma once
class Player : public TextureRect
{
public:
	Player(Vector3 position, Vector3 size, float rotation);
	~Player();


	void Fire();
	void MoveBarrel();

	void Update() override;
	void Render() override;
private:
	Line* CBarrel;
	GaugeBar* CGaugeBar;
	ProjectileManager* CPjManager;
	//발사 파워
	float fFirePower=0.0f;
};