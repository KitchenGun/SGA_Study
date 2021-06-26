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
	case Direction::NONE://����
	{
		return true;
	}
	case Direction::TOP://��
	{
		if (CircleEdge.POINT.y - Edge.LT.y <= CircleEdge.RADIUS)
		{
			return true;
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
			return true;
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

bool Math::CircleWallIntersect(Ball * c1)
{
	CircleEdges CircleEdge = c1->GetTransformedCoord();
	float angle = 0;
	float tempX = 0;
	float tempY = 0;
	Vector3 tempVec;

	if (CircleEdge.POINT.y + CircleEdge.RADIUS > WinMaxHeight)//���� �浹
	{
		tempX = CircleEdge.POINT.x - c1->GetVecDir().x;
		tempY = CircleEdge.POINT.y - c1->GetVecDir().y;
		tempVec = (tempX * 0 + tempY * 1)*Vector3(0, 1, 0);
		//r=p+2n(-p.n)

		c1->SetVecDir(tempVec);
		return true;
	}
	else if (CircleEdge.POINT.y - CircleEdge.RADIUS < 0)//�Ʒ� �浹
	{
		tempX = CircleEdge.POINT.x - c1->GetVecDir().x;
		tempY = CircleEdge.POINT.y - c1->GetVecDir().y;
		tempVec = Vector3(tempX, tempY, 0) - 2 * (CircleEdge.POINT.y)*Vector3(tempX, tempY, 0);

		c1->SetVecDir(tempVec);
		return true;
		//angle = atan2(CircleEdge.POINT.y - c1->GetVecDir().y, CircleEdge.POINT.x - c1->GetVecDir().x);
		//angle = D3DXToRadian(90.0f) - angle;
		//cout << D3DXToDegree(angle) << endl;
		//normalizeX = sqrtf(pow((float)CircleEdge.RADIUS*cosf((angle)),2));
		//normalizeY = sqrtf(pow((float)CircleEdge.RADIUS*sinf((angle)), 2));
		//c1->SetVecDir({ CircleEdge.RADIUS*cosf((angle))/normalizeX, CircleEdge.RADIUS*sinf((angle))/ normalizeX, 0 });
		//return true;
	}
	else if (CircleEdge.POINT.x + CircleEdge.RADIUS > WinMaxWidth)//���� �浹
	{
		//angle = atan2(CircleEdge.POINT.y - c1->GetVecDir().y, CircleEdge.POINT.x - c1->GetVecDir().x);
		//angle = - angle;
		//normalizeX = sqrtf(pow((float)CircleEdge.RADIUS*cosf((angle)), 2));
		//normalizeY = sqrtf(pow((float)CircleEdge.RADIUS*sinf((angle)), 2));
		//c1->SetVecDir({ CircleEdge.RADIUS*cosf((angle)) / normalizeX, -CircleEdge.RADIUS*sinf((angle)) / normalizeY, 0 });
		//return true;
	}
	else if (CircleEdge.POINT.x - CircleEdge.RADIUS < 0)//���� �浹
	{
		//angle = atan2(CircleEdge.POINT.y - c1->GetVecDir().y, CircleEdge.POINT.x - c1->GetVecDir().x);
		//angle = - angle;
		//normalizeX = sqrtf(pow((float)CircleEdge.RADIUS*cosf((angle)), 2));
		//normalizeY = sqrtf(pow((float)CircleEdge.RADIUS*sinf((angle)), 2));
		//c1->SetVecDir({ -CircleEdge.RADIUS*cosf((angle)) / normalizeX, CircleEdge.RADIUS*sinf((angle)) / normalizeY, 0 });
		////�й� �޽��� ��� ����
		//return true;
	}
	return false;
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


