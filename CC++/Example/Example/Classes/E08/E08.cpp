#include "E08.h"

//#define E08_STRUCT 1
//#define E08_UNION 2
#define E08_ENUM 3

#if E08_STRUCT
//PLAYER
/*
typedef Ű���带 ����ϸ� Ư���ڷ����� ���ο� �̸��� �ο��ϴ� ���� ������ ���� 
�⺻�ڷ����� ����Ҷ����� ���� �����ϴ� �������� �������� ���̴� ���� �����ϴ�

ex)
int nPower =0;
typedef int POWER_VALUE;
POWER_VALUE nPower =0;
->���������� �̿��Ͽ��� ����ϴ� ���� ���� �����̴�
typedef int POWER_VALUE;
POWER_VALUE nPower =0;
*/
typedef struct _tagE08STPlayer
{
	short m_ID;
	int m_nHP;
	int m_nLevel;
}E08STPlayer;
//������ func
E08STPlayer E08LevelUp(E08STPlayer a_stPlayer)
{
	a_stPlayer.m_nLevel += 1;
	a_stPlayer.m_nHP += 10;
	return a_stPlayer;
}
//�÷��̾� ���� ���
void E08STPrintPlayerInfo(E08STPlayer a_stPlayer)
{
	printf("�÷��� %d ���� : %d %d \n", a_stPlayer.m_ID, a_stPlayer.m_nLevel, a_stPlayer.m_nHP);
}
#elif E08_UNION
union E08UNData
{
	int m_nData;
	float m_fData;
};
#elif E08_ENUM
//������ Ÿ��
/*
�� ������ ����� ���� �������� ���� ��� ���� ������� +1�� ������ ���� �ڵ����� �ο� �ȴ� 
Ư�� ���� �������� ������ �����Ϸ��� ���ؼ� �ߺ����� �ʴ� ���� ���ϴ� ��� ���� ����

���Ӽ��� ��� ���ؼ� C++11���� �߰��� �������� �������� �������� ���������� ���еȴ� 
�ٽ��� enum���� ������ �ִ�.
�⺻ c ���� �߻��ϴ� �ߺ� ��� ������ �����ϴ� ���� �Ұ��� ������ �������� �������� ����ϸ� 
Ư�� ����� ������ �����ϴ� ���� �����ϱ� ������ ���� �ٸ� �������̶�� �ߺ��� ����� �����ϴ� ���� �����ϴ�
*/
enum class E08ArraySize
{
	NONE = -1,
	DEF_SIZE = 10,
	MAX_VALUE
};

enum class E08ItemType
{
	NONE=-1,
	GOLD,
	WEAPON,
	MAX_VALUE
};
//����Ÿ��
enum class E08WeaponType
{
	NONE = -1,
	GUN,
	SWORD,
	MAX_VALUE
};

#endif // E08_STRUCT
//Ÿ�� ������
//typedef int INT_32;

void E08(int argc, char ** args)
{
	//Ÿ�� ������
	//INT_32 nValue = 0;
#if E08_STRUCT

	printf("�÷��̾� ����ü ũ��%d\n",sizeof(E08STPlayer));
	//����ü�� ũ��� �����Ϸ��� ������ ���ϰ� �ϱ����� ����ü�� �ɹ� ũ�⺸�� ũ�� �ٲ������  �̷��� �߰��Ǵ� ����Ʈ�� �е�����Ʈ����� 
	//�� sizeof�� ����ϴ� ���� ���� ������

	E08STPlayer stPlayerA;
	stPlayerA.m_ID = 1;
	stPlayerA.m_nHP = 10;
	stPlayerA.m_nLevel = 1;
	/*
	����ü ���� ���� �Ϲ� ����ó�� �����ϰ� �ʱ�ȭ���� �����ϴ� ���� ������ 
	�ʱ�ȭ ������ ����ü�� �ɹ����� ������ ����
	*/
	E08STPlayer stPlayerB =
	{
		2,25,1
	};

	/*
	����ü�� �⺻ �ڷ����� ������ ������ �ϴ� ���� �����ϱ� ������ �ش� ����ü�� ����ؼ� �迭�� �����ϴ� �� ���� �����ϴ�.
	*/

	E08STPlayer astPlayers[] = 
	{
	
		{3,35,1},
		{4,30,1}
		
	};

	int nSelPlayerID = 0;
	do
	{
		printf("������ ��� �÷��̾� ���� (1or4) : ");
		scanf("%d", &nSelPlayerID);
		if (nSelPlayerID == 1)
		{
			stPlayerA = E08LevelUp(stPlayerA);
		}
		else if(nSelPlayerID==2)
		{
			stPlayerB = E08LevelUp(stPlayerB);
		}
		else if (nSelPlayerID == 3)
		{
			astPlayers[0] = E08LevelUp(astPlayers[0]);
		}
		else if (nSelPlayerID == 4)
		{
			astPlayers[1] = E08LevelUp(astPlayers[1]);
		}
		printf("������ ��� \n");
		E08STPrintPlayerInfo(stPlayerA);
		E08STPrintPlayerInfo(stPlayerB);
		for (int i = 0; i < sizeof(astPlayers) / sizeof(astPlayers[0]); i++)
		{
			E08STPrintPlayerInfo(astPlayers[i]);
		}
		printf("\n");
	} while (nSelPlayerID != 0);


#elif E08_UNION
	E08UNData unData;
	unData.m_nData = 123456789;
	printf("���� �Ҵ� ���\n");
	printf("���� %d\n",unData.m_nData);
	printf("�Ǽ� %f\n", unData.m_fData);
	unData.m_fData = 3.14f;
	printf("�Ǽ� �Ҵ� ���\n");
	printf("���� %d\n", unData.m_nData);
	printf("�Ǽ� %f\n", unData.m_fData);
#elif E08_ENUM
	//������ ����� ���� ������ Ÿ�ӿ� Ȯ���Ǳ� ������ �ش� ����� ����ؼ� �迭�� ���̸� ����ϴ� ���� �����ϴ�
	//����� ��Ÿ�ӿ� ���� Ȯ�� �Ǳ⶧���� ����δ� �迭�� ���̸� ����ϴ� ���� �Ұ�����
	int anValues[(int)E08ArraySize::DEF_SIZE] = { 0 };

	printf("������ ���\n");

	printf("NONE %d\n", E08ItemType::NONE);
	printf("GOLD %d\n", E08ItemType::GOLD);
	printf("WEAPON %d\n", E08ItemType::WEAPON);
	printf("MAX_VALUE %d\n", E08ItemType::MAX_VALUE);

	E08ItemType eItemType = E08ItemType::GOLD;
	/*
	������ ���� ����� ���� �ڷ����̱� ������ �ش� �������� ����ؼ� ���� ���� ����
	*/
	printf("\n������ ��� �� ���\n");
	printf("eItemType==NONE %d\n", eItemType== E08ItemType::NONE);
	printf("eItemType==GOLD %d\n", eItemType== E08ItemType::GOLD);
	printf("eItemType==WEAPON %d\n", eItemType== E08ItemType::WEAPON);
	printf("eItemType==MAX_VALUE %d\n", eItemType== E08ItemType::MAX_VALUE);
#endif // E08_STRUCT


	

}
