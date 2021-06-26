#pragma once
#include "Geometry/Square.h"

class Player :
	public Square
{
public:
	Player(D3DXVECTOR3 position, D3DXVECTOR3 size, float rotation,Color color);
	~Player();

	void PlayerCtrl();


	void Move(D3DXVECTOR3 position) override;

	void Update() override;

private:
	bool isMoveVertical = false;
};