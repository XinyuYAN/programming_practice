#include <iostream>
using namespace std;
class Time
{
public:
	Time()//����
	{
		x=y=z=0;
	}
	Time(int h,int m,int s)//���캯��
	{
		x=h;
		y=m;
		z=s;
	}
	void set(int h,int m,int s)//����ʱ��
	{
		x=h;
		y=m;
		z=s;
	}
	void increment()//ʱ������1��(Ӧ��Ҫ���ǽ�λ)
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
	void display()//��ʾʱ��ֵ
	{
		cout << "hour:" << x << "minute" << y << "second:"<< z;
	}
	bool equal(Time &other_time)//�Ƚ��Ƿ���ĳ��ʱ�����
	{
		return(x==other_time.x && y==other_time.y && z==other_time.z);
	}
	bool less_than(Time &other_time)//�Ƚ��Ƿ�����ĳ��ʱ��
	{
		if(x<other_time.x)
			return true;
		else if(x > other_time.x)
			return false;
		else //��ʱʱ���
			if(y<other_time.y)
				return true;
			else if(y>other_time.y)
				return false;
			else//��ʱ�����
				if(z < other_time.z)
					return true;
				else return false;


	}

private:
	int x,y,z;
};
