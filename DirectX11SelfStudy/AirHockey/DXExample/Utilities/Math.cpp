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
		cout << "충돌" << endl;
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
	//지역 구분
	if (CircleEdge.POINT.x < Edge.LT.x)
	{
		if (CircleEdge.POINT.y > Edge.LT.y)
		{
			dir = Direction::TL;//좌상단
		}
		else if (CircleEdge.POINT.y < Edge.RB.y)
		{
			dir = Direction::BL;//좌하단
		}
		else
		{
			dir = Direction::LEFT;//좌측
		}
	}
	else if (CircleEdge.POINT.x > Edge.RB.x)
	{
		if (CircleEdge.POINT.y > Edge.LT.y)
		{
			dir = Direction::TR;//우상단
		}
		else if (CircleEdge.POINT.y < Edge.RB.y)
		{
			dir = Direction::BR;//우하단
		}
		else
		{
			dir = Direction::RIGHT;//우측
		}
	}
	else
	{
		if (CircleEdge.POINT.y > Edge.LT.y)
		{
			dir = Direction::TOP;//우상단
		}
		else if (CircleEdge.POINT.y < Edge.RB.y)
		{
			dir = Direction::BOTTOM;//우하단
		}
		else
		{
			dir = Direction::NONE;
		}
	}
	float angle = 0;
	//atan2를 사용하여서 이동벡터의 기울기 각도를 구함
	angle = atan2(c1->GetVecDir().y, c1->GetVecDir().x);
	//지역에 따른 연산
	switch (dir)
	{
	case Direction::NONE://포함
	{
		return true;
	}
	case Direction::TOP://상
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
	case Direction::RIGHT://우
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
	case Direction::BOTTOM://하
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
	case Direction::LEFT://좌
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
	//atan2를 사용하여서 이동벡터의 기울기 각도를 구함
	angle = atan2(c1->GetVecDir().y, c1->GetVecDir().x);

	if (CircleEdge.POINT.y + CircleEdge.RADIUS > WinMaxHeight)//위에 충돌
	{
		c1->SetVecDir({ c1->GetVecDir().x, c1->GetVecDir().y*-1,0 });
	}
	else if (CircleEdge.POINT.y - CircleEdge.RADIUS < 0)//아래 충돌
	{
		c1->SetVecDir({ c1->GetVecDir().x, c1->GetVecDir().y*-1,0 });
	}
	else if (CircleEdge.POINT.x + CircleEdge.RADIUS > WinMaxWidth)//우측 충돌
	{
		c1->SetVecDir({ c1->GetVecDir().x*-1, c1->GetVecDir().y,0 });
	}
	else if (CircleEdge.POINT.x - CircleEdge.RADIUS < 0)//좌측 충돌
	{
		c1->SetVecDir({ c1->GetVecDir().x*-1, c1->GetVecDir().y,0 });
	}
}

