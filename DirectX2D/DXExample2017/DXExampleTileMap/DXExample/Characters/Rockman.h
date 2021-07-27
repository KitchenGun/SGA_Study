#pragma once
class Rockman : public AnimationRect
{
public:
	Rockman(Vector3 position, Vector3 size, float rotation);
	~Rockman();
public:
	//추후에 다른 애니메이션 추가가 있을 수 있으니 override로 변경
	void Move(Vector3 position) override;
public:
	//생성자에서 애니메이션 클립을 만들고 애니메이션을 추가하는 함수
	void SetAnimation();

private:

};