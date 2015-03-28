#include <iostream>
#include "funtion.h"
using namespace std;

int main()
{
	int array[5]={1,4,5,7,10};
	int barry[7]={2,3,6,8,11,12,7};
	Intset a(array,5);
	Intset b(barry,7);
	a.print();
	b.print();
	a +=15;
	b-=11;
	a.print();
	b.print();
	Intset c(a & b);
	c.print();
	Intset d(a | b);
	d.print();
	return 0;

}