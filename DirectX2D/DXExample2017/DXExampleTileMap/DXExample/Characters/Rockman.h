#pragma once
class Rockman : public AnimationRect
{
public:
	Rockman(Vector3 position, Vector3 size, float rotation);
	~Rockman();
public:
	//���Ŀ� �ٸ� �ִϸ��̼� �߰��� ���� �� ������ override�� ����
	void Move(Vector3 position) override;
public:
	//�����ڿ��� �ִϸ��̼� Ŭ���� ����� �ִϸ��̼��� �߰��ϴ� �Լ�
	void SetAnimation();

private:

};