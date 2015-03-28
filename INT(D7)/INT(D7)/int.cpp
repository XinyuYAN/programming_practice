#include<iostream>
#include "INT.h"
using namespace std;

int main()
{
	INT a("111");
	a.display();
	INT b("-25");
	b.display();
	INT c("-122");
	INT d("-10");
	//INT d(a+b);
	//d.display();
	INT e(a-b);
	e.display();
	//INT c(a-b);
	//c.display();
	//INT f(a-24);
	//f.display();
	////INT f(a+12);
	//f.display();
	//INT g(a*b);
	//g.display();
	INT h(a/b);
	h.display();
	INT m(c/d);
	m.display();
	return 0;
}