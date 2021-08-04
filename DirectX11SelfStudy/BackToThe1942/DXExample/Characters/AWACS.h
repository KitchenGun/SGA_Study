#pragma once
class AWACS : public AnimationRect
{
	AWACS(Vector3 position, Vector3 size, float rotation);
	~AWACS();

	void Update();

	void SetSoundPath(int index);
public:
	void SetTarget(Player* val) { Target = val; }
	void SetGameManager(GameManager* val) { GM = val; }
private:
	int scriptIndex=0;
	SoundSystem* Speaker;

	Player* Target = nullptr;
	GameManager* GM = nullptr;
};