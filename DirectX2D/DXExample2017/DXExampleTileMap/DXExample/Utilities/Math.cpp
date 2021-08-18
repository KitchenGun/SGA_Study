#include "stdafx.h"
#include "Math.h"

#include "Geometry/Line.h"
#include "Geometry/Square.h"
#include "Geometry/Circle.h"
#include "Geometry/FilledCircle.h"
#include "Geometry/TextureRect.h"

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

bool Math::Intersect(Square * rect, Vector3 position)
{
	RectEdges e1 = rect->GetTransformedCoord();
	if (e1.RB.x >= position.x&&e1.LT.x <= position.x&&e1.LT.y >= position.y&&e1.RB.y <= position.y)
		return true;
	else
		return false;
}

bool Math::IntersectOriented(Square * r1, Square * r2)
{
	Vector3 dist = r1->GetPosition() - r2->GetPosition();

	Vector3 r1Up = r1->Up() * r1->GetScale().y*0.5f;
	Vector3 r1Right = r1->Right() * r1->GetScale().x*0.5f;
	
	Vector3 r2Up = r2->Up()*r2->GetScale().y*0.5f;
	Vector3 r2Right = r2->Right() * r2->GetScale().x*0.5f;

	float c = fabs(Dot(dist, r1->Right()));
	float a = fabs(Dot(r2Up, r1->Right()))+fabs((Dot(r2Right,r1->Right())));
	float b = r1->GetScale().x*0.5f;
	if (c > a + b)
		return false;
	c = fabs(Dot(dist, r1->Up()));
	a = fabs(Dot(r2Up, r1->Up())) + fabs((Dot(r2Right, r1->Up())));
	b = r1->GetScale().y*0.5f;
	if (c > a + b)
		return false;
	c = fabs(Dot(dist, r2->Right()));
	a = fabs(Dot(r1Up, r2->Right())) + fabs((Dot(r1Right, r2->Right())));
	b = r1->GetScale().x*0.5f;
	if (c > a + b)
		return false;
	c = fabs(Dot(dist, r2->Up()));
	a = fabs(Dot(r1Up, r2->Up())) + fabs((Dot(r1Right, r2->Up())));
	b = r2->GetScale().y*0.5f;
	if (c > a + b)
		return false;

	return true;
}

Vector2 Math::absVec2(Vector2 val)
{
	float x = abs(val.x);
	float y = abs(val.y);
	return Vector2(x, y);
}

Vector3 Math::absVec3(Vector3 val)
{
	float x = abs(val.x);
	float y = abs(val.y);
	float z = abs(val.z);
	return Vector3(x, y, z);
}

float Math::GetDistance(Vector3 v1, Vector3 v2)
{
	return sqrtf(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2));
}

float Math::Dot(Vector3 v1, Vector3 v2)
{
	return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

