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
	cout << "Ԫ�ظ���Ϊ��" <<a.size() << endl;
	cout << "����Ԫ��e" << endl;
	cin >> temp;
	if(a.is_element(temp))
		cout << "����"<< endl;
	else
		{
			cout << "������" <<endl;
			a.insert(temp);
		}
	
	cout << "������ɾ��Ԫ��Ԫ��e" << endl;
	cin >> temp;
	a.remove(temp);
	cout << "ɾ���������Ϊ"<<endl;
	a.display();
	Intset b;
	input(b);
	if(a.is_subset(b))
		cout << "����" << endl;
	else cout << "������" << endl;
	if(a.is_equal(b))
		cout << "�����������" << endl;
	else cout << "not equal" << endl;
	Intset c(a);//����
	c.union2(b);//���ص���c��Ӧ��
	cout << "������" << endl;
	c.display();
	Intset d(a);
	cout << "������" << endl;
	d.intersection2(b);
	d.display();
	Intset e(a);
	cout << "���" << endl;
	e.difference2(b);
	e.display();
	return 0;
}
void input(Intset &a)
{
	int temp=0;
	cout << " ����һ��������ֹͣ����������-1" << endl;
	cin >> temp;
	do
	{
		a.insert(temp);
		cin >> temp;
	}
	while (temp != -1);
}