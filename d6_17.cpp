#include <iostream>
#include "d6 hm2\d6 hm2\class.new.h"
using namespace std;

void input(Intset &a);
int main()
{
	Intset a;
	int temp=0;
	input(a);
	a.is_empty();
	a.display();
	cout << "元素个数为：" <<a.size() << endl;
	cout << "输入元素e" << endl;
	cin >> temp;
	if(a.is_element(temp))
		cout << "属于"<< endl;
	else
		{
			cout << "不属于" <<endl;
			a.insert(temp);
		}
	
	cout << "输入需删除元素元素e" << endl;
	cin >> temp;
	a.remove(temp);
	cout << "删除后的序列为"<<endl;
	a.display();
	Intset b;
	input(b);
	if(a.is_subset(b))
		cout << "包含" << endl;
	else cout << "不包含" << endl;
	if(a.is_equal(b))
		cout << "两个集合相等" << endl;
	else cout << "not equal" << endl;
	Intset c(a);//拷贝
	c.union2(b);//返回的是c吧应该
	cout << "并集是" << endl;
	c.display();
	Intset d(a);
	cout << "交集是" << endl;
	d.intersection2(b);
	d.display();
	Intset e(a);
	cout << "差集是" << endl;
	e.difference2(b);
	e.display();
	return 0;
}
void input(Intset &a)
{
	int temp=0;
	cout << " 输入一个数，若停止输入则输入-1" << endl;
	cin >> temp;
	do
	{
		a.insert(temp);
		cin >> temp;
	}
	while (temp != -1);
}