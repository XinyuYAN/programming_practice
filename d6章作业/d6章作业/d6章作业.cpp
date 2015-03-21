// d6����ҵ.cpp : �������̨Ӧ�ó������ڵ㡣
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
		Point relative(const Point &p)//���������p����������
		{
			Point rel;
			rel.x=2*p.x - x;
			rel.y=2*p.y - y;
			return rel;
		}
		bool is_above_left(const Point &p)//�ж��Ƿ���p�����Ϸ�
		{
			return((x <p.x) && (y > p.y));
		}
private:double x,y;
}

