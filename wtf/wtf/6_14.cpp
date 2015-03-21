#include <iostream>
using namespace std;
class Time
{
public:
	Time()//构造
	{
		x=y=z=0;
	}
	Time(int h,int m,int s)//构造函数
	{
		x=h;
		y=m;
		z=s;
	}
	void set(int h,int m,int s)//调整时间
	{
		x=h;
		y=m;
		z=s;
	}
	void increment()//时间增加1秒(应该要考虑进位)
	{
		if(z == 59)
			if (y == 59)
				if (x == 23)
					x=y=z=0;
				else { x++;y=z=0;}
			else {y++;z=0;}
		else
			z+=1;
	}
	void display()//显示时间值
	{
		cout << "hour:" << x << "minute" << y << "second:"<< z;
	}
	bool equal(Time &other_time)//比较是否与某个时间相等
	{
		return(x==other_time.x && y==other_time.y && z==other_time.z);
	}
	bool less_than(Time &other_time)//比较是否早于某个时间
	{
		if(x<other_time.x)
			return true;
		else if(x > other_time.x)
			return false;
		else //此时时相等
			if(y<other_time.y)
				return true;
			else if(y>other_time.y)
				return false;
			else//此时分相等
				if(z < other_time.z)
					return true;
				else return false;


	}

private:
	int x,y,z;
};
