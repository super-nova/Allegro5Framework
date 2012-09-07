#include "UtilDefs.h"

#pragma once

#include "Utils2.h"

namespace Utils2
{
	class Vector2
	{
	public:
		float x;
		float y;


		Vector2(void){}
		~Vector2(void){}
		Vector2(float x, float y)
		{
			this->x = x;
			this->y = y;
		}

		Vector2 operator - (Vector2 minus)
		{
			return Vector2( this->x - minus.x , this->y - minus.y );
		}

		Vector2 operator + (Vector2 minus)
		{
			return Vector2( this->x + minus.x , this->y + minus.y );
		}
	};

	typedef Vector2 Point;

	class Angle
	{
		double ang;
	public:
		Angle(void){}

		Angle(radian rad)
		{
			this->Radian(rad);
		}

		Angle(degree deg)
		{
			this->Degree(deg);
		}

		~Angle(void){}

		radian Radian()
		{
			return ang;
		}

		void Radian(radian rad)
		{
			ang = rad;
		}

		degree Degree()
		{
			return (180 * ang) / M_PI;
		}

		void Degree(degree deg)
		{
			ang = ( M_PI * deg ) / 180.0;
		}
	};

	class Rectangle
	{
	public:
		Vector2 A;
		Vector2 B;
		Vector2 C;
		Vector2 D;

		Rectangle(Vector2 _A, Vector2 _B, Vector2 _C, Vector2 _D)
		{
			A = _A;
			B = _B;
			C = _C;
			D = _D;
		}

		Rectangle(float x1, float y1, float x2, float y2)
		{
			A = Vector2(x1, y1);
			B = Vector2(x2, y1);
			C = Vector2(x1, y2);
			D = Vector2(x2, y2);
		}
	};

	class Triangle
	{
	public:
		Vector2 A;
		Vector2 B;
		Vector2 C;
	};


	double area3(Vector2 p1,Vector2 p2,Vector2 p3);

	bool CheckInside(Vector2 point, Triangle area);

	bool InsidePolygon(Point *polygon,int N,Point p);

	int pnpoly(int npol, float *xp, float *yp, float x, float y);

	bool CheckInside(Vector2 point, Rectangle area, bool ortho = false);

	float Distance(Vector2 p1, Vector2 p2);

	Vector2 Rotate(Vector2 pos, Vector2 center, Angle angle);

	Angle RotateTo(Vector2 curPos, Vector2 tarPos, Angle curAng = (radian)0);



}//end of namespace
