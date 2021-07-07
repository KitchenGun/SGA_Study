#include "stdafx.h"
#include "Math.h"

bool Math::Intersect(Square *r1, Square *r2)
{
	RectEdges edge1 = r1->GetTransformedCoord();
	RectEdges edge2 = r2->GetTransformedCoord();

	if (edge1.RB.x >= edge2.LT.x && edge1.LT.x <= edge2.RB.x&&edge1.LT.y >= edge2.RB.y && edge1.RB.y <= edge2.LT.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Math::CircleIntersect(Ball * c1, Player * c2)
{
	CircleEdges CircleEdge1 = c1->GetTransformedCoord();
	CircleEdges CircleEdge2 = c2->GetTransformedCoord();

	int Range = sqrtf(powf(CircleEdge1.POINT.x - CircleEdge2.POINT.x, 2) + powf(CircleEdge1.POINT.y - CircleEdge2.POINT.y, 2));

	if (Range <= CircleEdge1.RADIUS + CircleEdge2.RADIUS)
	{
		cout << "�浹" << endl;
		if (!c2->GetIntersect())
		{
			float angle = atan2(CircleEdge1.POINT.y - CircleEdge2.POINT.y, CircleEdge1.POINT.x - CircleEdge2.POINT.x);
			c1->SetVecDir({ cos(angle), sin(angle), 0 });
		}
	}
}

bool Math::CircleIntersect(Ball * c1, Square * r1)
{
	RectEdges Edge = r1->GetTransformedCoord();
	CircleEdges CircleEdge = c1->GetTransformedCoord();
	Direction dir = Direction::NONE;
	//���� ����
	if (CircleEdge.POINT.x < Edge.LT.x)
	{
		if (CircleEdge.POINT.y > Edge.LT.y)
		{
			dir = Direction::TL;//�»��
		}
		else if (CircleEdge.POINT.y < Edge.RB.y)
		{
			dir = Direction::BL;//���ϴ�
		}
		else
		{
			dir = Direction::LEFT;//����
		}
	}
	else if (CircleEdge.POINT.x > Edge.RB.x)
	{
		if (CircleEdge.POINT.y > Edge.LT.y)
		{
			dir = Direction::TR;//����
		}
		else if (CircleEdge.POINT.y < Edge.RB.y)
		{
			dir = Direction::BR;//���ϴ�
		}
		else
		{
			dir = Direction::RIGHT;//����
		}
	}
	else
	{
		if (CircleEdge.POINT.y > Edge.LT.y)
		{
			dir = Direction::TOP;//����
		}
		else if (CircleEdge.POINT.y < Edge.RB.y)
		{
			dir = Direction::BOTTOM;//���ϴ�
		}
		else
		{
			dir = Direction::NONE;
		}
	}
	float angle = 0;
	//atan2�� ����Ͽ��� �̵������� ���� ������ ����
	angle = atan2(c1->GetVecDir().y, c1->GetVecDir().x);
	//������ ���� ����
	switch (dir)
	{
	case Direction::NONE://����
	{
		return true;
	}
	case Direction::TOP://��
	{
		if (CircleEdge.POINT.y - Edge.LT.y <= CircleEdge.RADIUS)
		{
			c1->SetVecDir({ cosf(-abs(angle)), sinf(-abs(angle)), 0 });
			return false;
		}
		else
		{
			return false;
		}
	}
	case Direction::RIGHT://��
	{
		if (CircleEdge.POINT.x - Edge.RB.x <= CircleEdge.RADIUS)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	case Direction::BOTTOM://��
	{
		if (Edge.RB.y - CircleEdge.POINT.y <= CircleEdge.RADIUS)
		{
			c1->SetVecDir({ cosf(-abs(angle)), sinf(-abs(angle)), 0 });
			return false;
		}
		else
		{
			return false;
		}
	}
	case Direction::LEFT://��
	{
		if (Edge.LT.x - CircleEdge.POINT.x <= CircleEdge.RADIUS)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	default:
	{
		float tempX = (Edge.RB.x - Edge.LT.x) / 2;
		float tempY = (Edge.LT.y - Edge.RB.y) / 2;

		float range = sqrt(powf(tempX, 2) + powf(tempY, 2));
		float dis = sqrt(powf(CircleEdge.POINT.x - Edge.POINT.x, 2) + powf(CircleEdge.POINT.y - Edge.POINT.y, 2));
		if (CircleEdge.RADIUS + range >= dis)
		{
			return false;
		}
		else
		{
			return false;
		}
	}
	}
}

void Math::CircleWallIntersect(Ball * c1)
{
	CircleEdges CircleEdge = c1->GetTransformedCoord();
	float angle = 0;
	//atan2�� ����Ͽ��� �̵������� ���� ������ ����
	angle = atan2(c1->GetVecDir().y, c1->GetVecDir().x);

	if (CircleEdge.POINT.y + CircleEdge.RADIUS > WinMaxHeight)//���� �浹
	{
		c1->SetVecDir({ c1->GetVecDir().x, c1->GetVecDir().y*-1,0 });
	}
	else if (CircleEdge.POINT.y - CircleEdge.RADIUS < 0)//�Ʒ� �浹
	{
		c1->SetVecDir({ c1->GetVecDir().x, c1->GetVecDir().y*-1,0 });
	}
	else if (CircleEdge.POINT.x + CircleEdge.RADIUS > WinMaxWidth)//���� �浹
	{
		c1->SetVecDir({ c1->GetVecDir().x*-1, c1->GetVecDir().y,0 });
	}
	else if (CircleEdge.POINT.x - CircleEdge.RADIUS < 0)//���� �浹
	{
		c1->SetVecDir({ c1->GetVecDir().x*-1, c1->GetVecDir().y,0 });
	}
}
