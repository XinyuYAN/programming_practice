#include <iostream>
using namespace std;
class Intset
{
private:
	int num;//�������
	Intset *next;//ָ��
public:
	Intset();//����
	Intset(const Intset &s);//�������캯��
	~Intset();//��������
	bool is_empty() const; //�ж��Ƿ�Ϊ�ռ�
	int size() const;//��ȡԪ�ظ���
	bool is_element(int e)const;//�ж�e�Ƿ����ڸü���
	Intset& insert(int e);//��e��ӵ�������
	Intset& remove(int e);//��e�Ӽ�����ɾ��
	void display()const;//��ʾ�����е�����Ԫ��
};
Intset :: Intset()
{
	next = NULL;
}

Intset :: ~Intset()
{
	Intset *temp=this->next;
	this->next = NULL;
	for(Intset *p= temp; p != NULL;)
	{
		temp =p;
		p =p->next;
		delete temp;
	}
	//delete this;//Ϊʲôthis����Ҫdelete����
}
Intset :: Intset(const Intset &s)
{
	
}
Intset& Intset :: insert(const int m)
{
	Intset *temp =new Intset;
	temp->num = m;
	temp -> next = this->next;
	this->next = temp;//��Ԫ�ز����ڱ�ͷ
	return *this;
}
Intset& Intset :: remove(int e)
{
	if(Intset ::is_element(e) == 0)
		cout << "�޸�Ԫ��" << endl;
	else 
	{
		Intset *pre=this;
		for(Intset *temp = this->next;temp != NULL;pre=temp,temp = temp->next)
		if(e == temp->num)
			{
				pre->next = temp ->next;	
				delete temp;
				break;
			}
	}
	return *this;
}

void Intset :: display() const
{
	for( Intset *temp=this->next;temp != NULL;temp=temp->next)
		cout << temp->num << ",";
	cout << endl;
}
bool Intset :: is_empty() const
{
	if(this->next != NULL)
	{
		cout << "�ü��ϲ�Ϊ��" << endl;
		return true; 
	}
	else
	{
		cout << "�ü���Ϊ��"<< endl;
		return false;
	}
}
int Intset :: size() const
{
	int count=0;
	for(Intset *temp = this ->next; temp != NULL;temp = temp->next)
		count++;
	cout << "Ԫ�ظ���Ϊ��" <<count << endl;
	return count;
}
bool Intset ::is_element(int e)const
{
	for(Intset *temp = this->next;temp != NULL;temp = temp->next)
		if(e == temp->num)
			return true;
	return false;
}