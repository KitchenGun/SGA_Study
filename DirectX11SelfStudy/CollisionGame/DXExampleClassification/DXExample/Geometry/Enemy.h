#pragma once
class Enemy:public Square
{
public:
	Enemy(D3DXVECTOR3 position, D3DXVECTOR3 size, float rotation);
	~Enemy();

	void Move(D3DXVECTOR3 position) override;
	void Action();
	void Update() override;

	void SetisTouchEdge(bool value) { isTouchEdge = value; }
private:
	float r=0, g=0, b=0;
	bool isDirX = true;
	bool isTouchEdge = true;
	int nRNGSpeed = 0;
};