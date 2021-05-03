#include "Map.h"

CMap::Pos CMap::GetPlayerPos()
{
	return Player;
}
void CMap::SetPlayerPos(CMap::Pos a_stPos)
{
	m_sMap[Player.Y].replace(Player.X, 1, " ");
	Player = a_stPos;
	m_sMap[Player.Y].replace(Player.X, 1, "@");
}
void CMap::SetNullPos()
{
	m_sMap[Player.Y].replace(Player.X, 1, " ");
}
CMap::Pos CMap::GetBlockPos()
{
	return Block;
}
CMap::Pos CMap::GetItemPos()
{
	return Item;
}
char CMap::GetPos(CMap::Pos a_stPos)
{
	return m_sMap[a_stPos.Y][a_stPos.X];
}

//�� ���
void CMap::PrintMap()
{
	for (std::string line : m_sMap)
	{
		std::cout << line << std::endl;
	}
}
//�ʱ�ȭ  ��ֹ� ���� -> ������ ���� -> �÷��̾� ��ġ ����
void CMap::Reset()
{
	m_sMap[Block.Y].replace(Block.X, 1, " ");
	m_sMap[Item.Y].replace(Item.X, 1, " ");
	CreateBlock();
	CreateItem();
	CreatePlayer();
}
//��ֹ� ����
void CMap::CreateBlock()
{
	RandomPos(Block);
	int nTemp = RandomNum(8) + 1;
	m_sMap[Block.Y].replace(Block.X, 1, std::to_string(nTemp));
}
//������ ����
void CMap::CreateItem()
{
	do
	{
		RandomPos(Item);
	} while (PosCheck(Item, Block));
	m_sMap[Item.Y].replace(Item.X, 1, "&");
}
//�÷��̾� ����
void CMap::CreatePlayer()
{
	bool bTemp = true;
	do
	{
		RandomPos(Player);
		if (!PosCheck(Player, Block))
			if (!PosCheck(Player, Item))
				bTemp = false;
	} while (bTemp);

	m_sMap[Player.Y].replace(Player.X, 1, "@");
}
//���� ��ǥ ����
CMap::Pos CMap::RandomPos(Pos& Position)
{
	Position.X = RandomNum(19) + 1;//x�� �� ���� ����  �׵θ��� �����ϱ� ���ؼ� +1
	Position.Y = RandomNum(2) + 1;//y�� �� ���� ����

	return Position;
}

//���� ���� ���� ��ȯ
int CMap::RandomNum(int a_nRange)
{
	std::random_device oRandom;
	std::uniform_int_distribution<int> oUniformReal(0, a_nRange);
	return oUniformReal(oRandom);
}