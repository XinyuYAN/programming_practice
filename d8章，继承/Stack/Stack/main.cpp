#include "Stack.h"
#include <iostream>
using namespace std;

int main()
{
	int x=2;
	LinearList a;
	a.insert(10,0);
	a.insert(5,1);
	a.insert(2,1);
	a.insert(4,2);
	a.insert(3,4);
	a.insert(2,4);
	a.display();
	a.remove(x,5);
	a.display();
	a.remove(x,2);
	cout << a.element(1) <<endl;
	cout <<a.element(3) << endl;
	cout << a.search(5);
	cout << a.search(3);
	cout << a.length();
	return 0;
}
