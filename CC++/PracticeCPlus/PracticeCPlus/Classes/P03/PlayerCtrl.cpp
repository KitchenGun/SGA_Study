#include "PlayerCtrl.h"

//get set
bool Player::GetIsDie()
{
	return isDie;
}
void Player::SetPlayerPos(CMap::Pos a_stPos)
{
	m_stPlayerPos = a_stPos;
}
int Player::GetHP()
{
	return m_HP;
}
//�Է� ó��
void  Player::InputKey(char a_chInput)
{
	switch (a_chInput)
	{
	case 'w':
	{
		if (m_stPlayerPos.Y != 1)
		{
			m_stPlayerPos.Y = m_stPlayerPos.Y - 1;
		}
		break;
	}
	case 'a':
	{
		if (m_stPlayerPos.X != 1)
		{
			m_stPlayerPos.X = m_stPlayerPos.X - 1;
		}
		break;
	}
	case 's':
	{
		if (m_stPlayerPos.Y != 3)
		{
			m_stPlayerPos.Y = m_stPlayerPos.Y + 1;
		}
		break;
	}
	case 'd':
	{
		if (m_stPlayerPos.X != 20)
		{
			m_stPlayerPos.X = m_stPlayerPos.X + 1;
		}
		break;
	}
	default:
	{
		printf("\nw,a,s,d�� �Է����ּ���\n");
	}
	}
	CheckPos();
}
//�浹 ó��
void Player::CheckPos()
{
	//��ֹ�����
	if (CMap::PosCheck(m_stPlayerPos, m_oMap.GetBlockPos()))
	{
		char chTempPosVal = m_oMap.GetPos(m_oMap.GetBlockPos());
		int nTempPosVal = chTempPosVal - 48;//�ƽ�Ű �ڵ� 48���� ���ڳ���
		Hit(nTempPosVal);
		if (isDie)
		{
			return;
		}
		m_oMap.SetNullPos();
		m_oMap.Reset();
		m_stPlayerPos = m_oMap.GetPlayerPos();
	}

	//����������
	if (CMap::PosCheck(m_stPlayerPos, m_oMap.GetItemPos()))
	{
		TakeItem();
		m_oMap.SetNullPos();
		m_oMap.Reset();
		m_stPlayerPos = m_oMap.GetPlayerPos();
	}

	m_oMap.SetPlayerPos(m_stPlayerPos);
	m_oMap.PrintMap();
}
//ü�� ���
void Player::Hit(int a_nDamage)
{
	m_HP -= a_nDamage;
	if (m_HP <= 0)
	{
		isDie = true;
		system("cls");
		printf("\n������ �����մϴ�.\n");
	}
}
//������ ȹ��
void Player::TakeItem()
{
	++m_HP;
}

//������
Player::Player(CMap a_cMap)
	:
	m_oMap(a_cMap),
	m_HP(1)
{
	m_stPlayerPos = a_cMap.GetPlayerPos();
}