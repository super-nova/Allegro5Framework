#pragma once

#include "Utils2.h"

namespace Utils2
{

	double area3(Vector2 p1,Vector2 p2,Vector2 p3)
	{
		double area = p1.x * ( p2.y - p3.y );
		area += p2.x * ( p3.y - p1.y );
		area += p3.x * ( p1.y - p2.y );
		area /= 2;
		area = abs(area);
		return area;
	}

	bool CheckInside(Vector2 point, Triangle area)
	{
		float _area = area3(area.A,area.B,area.C);

		float area2 = 0;

		area2 += area3(point,area.A,area.B);
		area2 += area3(point,area.B,area.C);
		area2 += area3(point,area.A,area.C);

		if( area2 == _area ) return true;

		return false;
	}

#define MIN(x,y) (x < y ? x : y)
#define MAX(x,y) (x > y ? x : y)
#define INSIDE 1
#define OUTSIDE 0


	bool InsidePolygon(Point *polygon,int N,Point p)
	{
		int counter = 0;
		int i;
		double xinters;
		Point p1,p2;

		p1 = polygon[0];
		for (i=1;i<=N;i++) {
			p2 = polygon[i % N];
			if (p.y > MIN(p1.y,p2.y)) {
				if (p.y <= MAX(p1.y,p2.y)) {
					if (p.x <= MAX(p1.x,p2.x)) {
						if (p1.y != p2.y) {
							xinters = (p.y-p1.y)*(p2.x-p1.x)/(p2.y-p1.y)+p1.x;
							if (p1.x == p2.x || p.x <= xinters)
								counter++;
						}
					}
				}
			}
			p1 = p2;
		}

		if (counter % 2 == 0)
			return false;
		else
			return true;
	}

	int pnpoly(int npol, float *xp, float *yp, float x, float y)
	{
		int i, j, c = 0;
		for (i = 0, j = npol-1; i < npol; j = i++)
		{
			if( ( ( (yp[i] <= y) && (y < yp[j]) ) ||
				((yp[j] <= y) && (y < yp[i]))) &&
				(x < (xp[j] - xp[i]) * (y - yp[i]) / (yp[j] - yp[i]) + xp[i]))
				c = !c;
		}
		return c;
	}

	bool CheckInside(Vector2 point, Rectangle area, bool ortho)
	{
		using std::cout;
		using std::endl;

		//cout<<"Benchmarking..."<<endl;

		if( ortho )
		{
			//cout<<"Standart Check Algorithm Takes: ";
			timer t;
			t.start();
			if( point.x > area.A.x && point.y > area.A.y && point.x < area.D.x && point.y < area.D.y )
			{
				//cout<<t.getElapsedTimeInMilliSec()<<" ms on OK"<<endl;
				return true;
			}
			//cout<<t.getElapsedTimeInMilliSec()<<" ms on FAIL"<<endl;
			return false;
		}

		/*timer t;

		t.StartCounter();

		float _area = 0;

		_area += area3(area.A,area.B,area.C);
		_area += area3(area.A,area.C,area.D);

		float area2 = 0;

		area2 += area3(point,area.A,area.B);
		area2 += area3(point,area.B,area.D);
		area2 += area3(point,area.A,area.C);
		area2 += area3(point,area.D,area.C);

		float res = area2 - _area;

		if( res < 1.0f && res > -1.0f ) 
		{
		cout<<"Area Check Algorithm Takes: "<<t.GetCounter()<<" ms"<<endl;
		return true;
		}

		return false;*/

		//METHOD 2 - USING LINES

		/*Point pArr[4];

		pArr[0] = area.A;
		pArr[1] = area.B;
		pArr[2] = area.C;
		pArr[3] = area.D;

		timer t;
		t.StartCounter();

		bool ret = InsidePolygon(pArr,4,point);

		if(ret)
		cout<<t.GetCounter()<<" ms"<<endl;

		return ret;*/

		//METHOD 3 - pnpoly

		float xs[4];
		float ys[4];

		xs[0] = area.A.x;
		xs[1] = area.B.x;
		xs[2] = area.C.x;
		xs[3] = area.D.x;

		ys[0] = area.A.y;
		ys[1] = area.B.y;
		ys[2] = area.C.y;
		ys[3] = area.D.y;


		timer t;
		t.start();

		bool ret = pnpoly(4,xs,ys,point.x,point.y);

		//cout<<t.getElapsedTimeInMilliSec()<<" ms"<<endl;

		return ret;

	}

	float Distance(Vector2 p1, Vector2 p2)
	{
		return sqrt( pow(p1.x-p2.x,2) + pow(p1.y-p2.y,2) );
	}

	Vector2 Rotate(Vector2 pos, Vector2 center, Angle angle)
	{
		Vector2 res = pos - center;

		float x = res.x;
		float y = res.y;
		double rad = angle.Radian();

		return Vector2( cos(rad) * x - sin(rad) * y , sin(rad) * x - cos(rad) * y );

		//Rotate:
		//rX = cos(rad) * x - sin(rad) * y;
		//rY = sin(rad) * x - cos(rad) * y
	}

	Angle RotateTo(Vector2 curPos, Vector2 tarPos, Angle curAng)
	{
		Vector2 res = tarPos - curPos;
		return Angle((radian)0);
	}


}//end of namespace
