#include "E03.h"
namespace E03Space
{
	/*
	C++ �������� ������ ������ ����
	public		�� �ܺ� ��� ���� ���
	protected	�ڽ� Ŭ������ ���� ��� �ܺο����� ���� �Ұ���
	private		Ŭ���� ���ο����� ���� ���
	
	C++Ŭ������ ��� �ɹ��� �⺻������ private �������� ��ȣ�Ǿ��ֱ� ������ ���� �ܺο��� �����ϱ����ؼ���
	�ݵ�� ��ȣ ������ private �� �ƴ� public, protected�� ���������Ѵ�.

	�Ϲ������� Ŭ������ �ɹ� ������ private �������� ��ȣ�ϴ� ���� �����̱� ������ ���� �ش� ������ �ܺο��� ����ϱ� ���ؼ��� 
	�ܺο����� �ش� ������ �����ϱ� ���� �Լ��� �ش� Ŭ������ �����ؾ��Ѵ�. Ư���ɹ������� �����Ҽ��ְ� �ܺο� �����Ǵ� �Լ��� ������ �Լ���� �Ѵ�
	�� ������ �Լ��� Ư���Լ� ������ ���� �ܺη� ��ȯ��Ű�� getter ���η� ��ȯ ��Ű��setter�� ��Ʋ� ��Ī�ϴ� ����̴�. 
	*/
	class CPlayer//Ŭ������ �⺻��ȣ������ private ����ü�� �⺻��ȣ������ public                 
		//������ ����ü�� ������ Ŭ������ �Լ��� ������ ���� �����ϴٰ� ��������   
	{
	public:
		//HP��ȯ�Ѵ�
		int GetHP()
		{
			return m_nHP;
		}
		void SetHP(int a_nHP)
		{
			m_nHP = a_nHP;
		}
		//ATK��ȯ�Ѵ�
		int GetATK()
		{
			return m_nATK;
		}
		void SetATK(int a_nATK)
		{
			m_nATK = a_nATK;
		}

		//���� 
		void Attack(CPlayer *a_pOtherPlayer)
		{
			a_pOtherPlayer->m_nHP -= m_nATK;
		}

	private:
		int m_nHP;
		int m_nATK;
	};

	
	void E03(const int argc, const char ** args)
	{
		CPlayer oPlayerA;
		CPlayer oPlayerB;
		oPlayerA.SetHP(100);
		oPlayerA.SetATK(15);
		oPlayerB.SetHP(50);
		oPlayerB.SetATK(35);


		oPlayerA.Attack(&oPlayerB);
		printf("player a ���� ���\n");
		printf("player a : %d %d \n", oPlayerA.GetHP(), oPlayerA.GetATK());
		printf("player b : %d %d \n", oPlayerB.GetHP(), oPlayerB.GetATK());

		oPlayerB.Attack(&oPlayerA);
		printf("player b ���� ���\n");
		printf("player a : %d %d \n", oPlayerA.GetHP(), oPlayerA.GetATK());
		printf("player b : %d %d \n", oPlayerB.GetHP(), oPlayerB.GetATK());
	}
}
