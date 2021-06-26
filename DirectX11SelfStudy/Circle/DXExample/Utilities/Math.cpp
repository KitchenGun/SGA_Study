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

bool Math::CircleIntersect(FilledCircle * c1, Square * r1)
{
	RectEdges Edge = r1->GetTransformedCoord();
	CircleEdges CircleEdge = c1->GetTransformedCoord();
	Direction dir=Direction::NONE;
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
	else if(CircleEdge.POINT.x > Edge.RB.x)
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


	//������ ���� ����
	switch (dir)
	{
	case Direction::NONE:
	{
		cout << "�� �ȿ� ���� �Ǿ� ����" << endl;
		return true;
	}
	case Direction::TOP:
	{
		cout << CircleEdge.POINT.y - Edge.LT.y << CircleEdge.RADIUS;
		if (CircleEdge.POINT.y - Edge.LT.y <= CircleEdge.RADIUS)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	case Direction::RIGHT:
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
	case Direction::BOTTOM:
	{	
		if (Edge.RB.y - CircleEdge.POINT.y <= CircleEdge.RADIUS)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	case Direction::LEFT:
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
		float tempX = (Edge.RB.x - Edge.LT.x)/2;
		float tempY = (Edge.LT.y - Edge.RB.y)/2;
		
		float range=sqrt(powf(tempX, 2) + powf(tempY, 2));
		float dis = sqrt(powf(CircleEdge.POINT.x - Edge.POINT.x, 2) + powf(CircleEdge.POINT.y - Edge.POINT.y, 2));
		if (CircleEdge.RADIUS + range >= dis)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	}
}

Direction Math::TouchEdge(Square * r1)
{
	RectEdges edge1 = r1->GetTransformedCoord();

	if (edge1.LT.y > WinMaxHeight)
	{

		if (edge1.RB.x > WinMaxWidth)
		{
			return Direction::TR;
		}
		else if (edge1.LT.x < 0)
		{
			return Direction::TL;
		}
		else
		{
			return Direction::TOP;
		}
	}
	else if (edge1.RB.y < 0)
	{
		if (edge1.RB.x > WinMaxWidth)
		{
			return Direction::BR;
		}
		else if (edge1.LT.x < 0)
		{
			return Direction::BL;
		}
		else
		{
			return Direction::BOTTOM;
		}
	}
	else if (edge1.RB.x > WinMaxWidth)
	{
		return Direction::RIGHT;
	}
	else if (edge1.LT.x < 0)
	{
		return Direction::LEFT;
	}
	else
	{
		return Direction::NONE;
	}
}


