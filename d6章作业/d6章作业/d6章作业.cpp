// d6章作业.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;
class Point{
public: Point(){ x=0;y=0;
		}
		Point(double a,double b){
		x=a;y=b;
		}
		double r()
		{
			return sqrt(a*a + b*b);
		}
		double theta()
		{	
			return arctanf(y/x);
		}	
		double distance(const Point& p)
		{
			return sqrt(fabs(x*x-p.x^2)+fabs(y^2-p.y^2));
		}
		Point relative(const Point &p)//计算相对于p点的相对坐标
		{
			Point rel;
			rel.x=2*p.x - x;
			rel.y=2*p.y - y;
			return rel;
		}
		bool is_above_left(const Point &p)//判断是否在p点左上方
		{
			return((x <p.x) && (y > p.y));
		}
private:double x,y;
}

