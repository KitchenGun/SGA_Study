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

bool Math::CircleIntersect(Ball * c1, Square * r1)
{
	RectEdges Edge = r1->GetTransformedCoord();
	CircleEdges CircleEdge = c1->GetTransformedCoord();
	Direction dir=Direction::NONE;
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
	else if(CircleEdge.POINT.x > Edge.RB.x)
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
			return true;
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
			if (angle < D3DXToRadian(0.0f))//위에서 꽂히는 경우
			{
				c1->SetVecDir({ -cosf(abs(D3DXToRadian(90.0f) + angle)), -sinf(abs(D3DXToRadian(90.0f) + angle)), 0 });
			}
			else//아래에서 꽂히는 경우
			{
				c1->SetVecDir({ -cosf(abs(D3DXToRadian(90.0f) - angle)), sinf(abs(D3DXToRadian(90.0f) - angle)), 0 });
			}
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
			//c1->SetVecDir({ cosf(abs(angle)), sinf(abs(angle)), 0 });
			return true;
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
			if (angle < D3DXToRadian(0.0f))//위에서 꽂히는 경우
			{
				c1->SetVecDir({ cosf(D3DXToRadian(180.0f) + angle), -sinf(D3DXToRadian(180.0f) + angle), 0 });
			}
			else//아래에서 꽂히는 경우
			{
				c1->SetVecDir({ cosf(D3DXToRadian(180.0f) - angle), sinf(abs(D3DXToRadian(180.0f) - angle)), 0 });
			}
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

bool Math::PlayerIntersect(Ball * c1, Square * r1)
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
	
	float angle = atan2(c1->GetVecDir().y, c1->GetVecDir().x);
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
			
			if (Edge.POINT.x - CircleEdge.POINT.x < 0)
			{//우측 충돌
				c1->SetVecDir({ cosf(abs(angle + D3DXToRadian(30))), sinf(abs(angle + D3DXToRadian(30))), 0 });
				cout << angle <<D3DXToDegree(angle)<<" 우측 "<< D3DXToDegree(angle + D3DXToRadian(30)) << endl;
			}
			else
			{//왼쪽 충돌
				c1->SetVecDir({ cosf(abs(angle+D3DXToRadian(-30))), sinf(abs(angle + D3DXToRadian(-30))), 0 });
				cout << angle << D3DXToDegree(angle) << " 좌측 " << D3DXToDegree(angle - D3DXToRadian(30)) << endl;
			}
			return true;
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
			c1->SetVecDir({ cosf(abs(angle + D3DXToRadian(60))), sinf(abs(angle + D3DXToRadian(60))), 0 });
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
			return true;
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
			c1->SetVecDir({ cosf(abs(angle + D3DXToRadian(-60))), sinf(abs(angle + D3DXToRadian(-60))), 0 });
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
			return true;
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
		MessageBox(handle, L"Lose" , L"Result", MB_OK);
		//c1->SetVecDir({ cosf(abs(angle)), sinf(abs(angle)), 0 });
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


