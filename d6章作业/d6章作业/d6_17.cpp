#include <iostream>
using namespace std;
class Intset
{
private: int*p;
public:
	Intset()
	{
		int n=0;//���캯��
		cin >> "����Ԫ�ظ���" >> n;
		p = new int[n],i=0;
		do 
		{	
			cin >> "�����" >> i+1 >> "��Ԫ��" >> p[i];
			i++;
		}
		while ( i < n);
	}
	Intset(const Intset &s);//�������캯��
	~Intset()//��������
	{
		delete p;
	}
};

int main()
{
	Intset a;
	//cout << a.is_empty();

}