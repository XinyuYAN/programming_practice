#include <iostream>
using namespace std;
class Intset
{
private: int*p;
public:
	Intset()
	{
		int n=0;//构造函数
		cin >> "输入元素个数" >> n;
		p = new int[n],i=0;
		do 
		{	
			cin >> "输入第" >> i+1 >> "个元素" >> p[i];
			i++;
		}
		while ( i < n);
	}
	Intset(const Intset &s);//拷贝构造函数
	~Intset()//析构函数
	{
		delete p;
	}
};

int main()
{
	Intset a;
	//cout << a.is_empty();

}