#include <iostream>
#include <cmath>
using namespace std;
class Point{
public: Point()//构造函数不能忘记。需要初始化
		{
			x=0;y=0;
		}
		Point(double a,double b)
		{
			x=a;y=b;
		}
		double r()
		{
			return sqrt(x*x + y*y);
		}
		double theta()
		{	
			return atan(y/x);
		}	
		double distance(const Point& p)
		{
			return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
		}
		Point relative(const Point &p)//计算相对于p点的相对坐标
		{
			//Point rel;
			double rx,ry;
			rx=2*p.x - x;
			ry=2*p.y - y;
			//return rel;
			return Point(rx,ry);
		}
		bool is_above_left(const Point &p)//判断是否在p点左上方
		{
			//return((x <p.x) && (y > p.y));
			return false;
		}
private:double x,y;
};