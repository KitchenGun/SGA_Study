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

bool Math::CircleIntersect(Circle * c1, Square * r2)
{
	CircleInfo edge1 = c1->GetTransformedCoord();
	RectEdges edge2 = r2->GetTransformedCoord();
	//if ()
	//{
	//	return true;
	//}
	//else
	//{
	//	return false;
	//}
	return true;

}
