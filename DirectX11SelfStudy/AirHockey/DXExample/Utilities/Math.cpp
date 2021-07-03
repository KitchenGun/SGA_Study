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

	float Range=sqrtf(powf(CircleEdge1.POINT.x - CircleEdge2.POINT.x, 2) + powf(CircleEdge1.POINT.y - CircleEdge2.POINT.y, 2));
	
	if (Range < CircleEdge1.RADIUS + CircleEdge2.RADIUS)
	{

		cout << "충돌" << endl;
		c2->SetIntersect(true);
		Vector3 temp = c2->GetVecDir() - c1->GetVecDir();
		float angle = atan2(temp.y, temp.x);
		cout << D3DXToDegree(atan2(temp.y, temp.x)) << endl;
		c1->SetVecDir({cos(angle), sin(angle), 0});
	}
	else
	{
		c2->SetIntersect(false);
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

