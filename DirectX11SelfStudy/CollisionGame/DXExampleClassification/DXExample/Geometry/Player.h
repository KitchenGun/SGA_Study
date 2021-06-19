#pragma once
#include "Square.h"
class Player :
	public Square
{
public:
	Player(D3DXVECTOR3 position, D3DXVECTOR3 size, float rotation);
	~Player();

	void PlayerCtrl();
	

	void Move(D3DXVECTOR3 position) override;

	void Update() override;

private:
	bool isMoveVertical=false;
};

