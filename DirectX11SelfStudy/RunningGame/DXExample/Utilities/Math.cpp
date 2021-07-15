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

bool Math::GroundIntersect(TextureRect* r1)
{
	Vector2 LT = { r1->GetLB().x , r1->GetLB().y };
	Vector2 RB = { r1->GetLB().z , r1->GetLB().w };
	if (RB.y <= 0)
		return true;
	return false;
}

float Math::Lerpf(float min, float max, float target)
{
	return min+target*(max-min);
}

