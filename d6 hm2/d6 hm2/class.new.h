#include <iostream>
using namespace std;
class Intset
{
private:
	struct element
	{
		int num;//�������
		element *next;//ָ��
	};
	element* first;
public:
	Intset();//����
	Intset(const Intset &s);//�������캯��
	~Intset();//��������
	bool is_empty() const; //�ж��Ƿ�Ϊ�ռ�
	int size() const;//��ȡԪ�ظ���
	bool is_element(int e)const;//�ж�e�Ƿ����ڸü���
	bool is_subset(const Intset& s) const;//�ж�s�Ƿ�����ڼ���
	bool is_equal(const Intset& s) const;//�жϼ����Ƿ����
	Intset& insert(int e);//��e��ӵ�������
	Intset& remove(int e);//��e�Ӽ�����ɾ��
	void display()const;//��ʾ�����е�����Ԫ��
	Intset union2(const Intset& s) const;//���㼯�ϵĲ���
	Intset intersection2(const Intset& s)const; //���㼯�ϵĽ���
	Intset difference2(const Intset& s)const;//���㼯�ϵĲ�
};
Intset :: Intset()
{
	element *p=new element;//������ͷ�ڵ�
	p->next = NULL;
	first= p;
}

Intset :: ~Intset()
{
	element *temp=first;
	for(element *p= temp; p != NULL;)
	{
		temp =p;
		p =p->next;
		delete temp;
	}
}
Intset :: Intset(const Intset &s)
{
	element *newer=new element;//������ͷ�ڵ�
	newer->next = NULL;
	first= newer;
	for(element *temp = s.first->next;temp != NULL;temp = temp->next)
	{
		element * newer=new element;
		newer ->num = temp->num;
		newer->next = first->next;
		first->next = newer;
	}
}
Intset& Intset :: insert(const int m)
{
	element *temp =new element;
	temp->num = m;
	temp -> next = first->next;
	first->next = temp;//��Ԫ�ز����ڱ�ͷ
	return *this;
}
Intset& Intset :: remove(int e)
{
	if(Intset ::is_element(e) == 0)
		cout << "�޸�Ԫ��" << endl;
	else 
	{
		element *pre=first;
		for(element *temp = first->next;temp != NULL;pre=temp,temp = temp->next)
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
	for( element *temp=first->next;temp != NULL;temp=temp->next)
		cout << temp->num << ",";
	cout << endl;
}
bool Intset :: is_empty() const
{
	if(first->next != NULL)
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
	for(element *temp = first ->next; temp != NULL;temp = temp->next)
		count++;
	return count;
}
bool Intset ::is_element(int e)const
{
	for(element *temp = first->next;temp != NULL;temp = temp->next)
		if(e == temp->num)
			return true;
	return false;
}
bool Intset ::is_subset(const Intset& s) const//�ж�s�Ƿ�����ڼ���
{
	element *tempa,*tempb;
	for(tempb = s.first->next;tempb != NULL; tempb = tempb->next)
		{
			for(tempa = this->first->next;tempa != NULL;tempa =tempa->next)
				if(tempb ->num == tempa ->num)
					break;
			if(tempa == NULL)
				return false;
		}
	return true;
}
bool Intset :: is_equal(const Intset& s) const
{
	element *tempa,*tempb;
	int count=0;
	for(tempb = s.first->next;tempb != NULL; tempb = tempb->next)
		for(tempa = this->first->next;tempa != NULL;tempa =tempa->next)
			if(tempb ->num == tempa ->num)
					{	
						count++;
						break;
					}
		if(tempa == NULL)
			return false;
	if (tempb == NULL && count == size())
		return true;
	else return false;
}
Intset Intset :: union2(const Intset& s) const//���㼯�ϵĲ���
{
	element *last=NULL,*tempb,*tempa;
	if(is_subset(s))
		return *this;
	for(last= this->first->next;last->next != NULL;last=last->next);//lastָ���β
	for (tempb=s.first->next;tempb != NULL;tempb=tempb->next)
	{
		for(tempa=this->first->next;tempa != NULL; tempa=tempa->next)
			if(tempa->num == tempb->num)
				break;
		if(tempa == NULL)//˵����Ԫ����c��û�ж�Ӧ���������ӵ�c����β
		{
			element *temp =new element;
			temp->num = tempb->num;
			temp->next = NULL;
			last->next=temp;
			last=temp;
		}
	}
	return *this;
}
Intset Intset :: intersection2(const Intset& s)const //���㼯�ϵĽ���
{
	element *tempa,*tempb,*pre;
	for(pre = this->first,tempa=pre->next;tempa != NULL;pre=tempa,tempa =tempa->next)
		{
			for(tempb = s.first->next;tempb != NULL; tempb = tempb->next)	
				if(tempb ->num == tempa ->num)
					break;
			if(tempb == NULL)//˵����Ԫ����b��û�У��ӽ�����ɾȥ
				{
					element *temp;
					pre->next=tempa->next;
					temp = tempa;
					tempa=pre;
					delete temp;
				}
		}
	if(this->first->next == NULL)
		cout << "A^B = none" << endl;
	return *this;
}
Intset Intset ::difference2(const Intset& s)const//���㼯�ϵĲ�
{
	element *tempa,*tempb,*pre;
	for(pre = this->first,tempa=pre->next;tempa != NULL;pre=tempa,tempa =tempa->next)
		{
			for(tempb = s.first->next;tempb != NULL; tempb = tempb->next)	
				if(tempb ->num == tempa ->num)//��b���У���Ӽ�����ɾȥ
				{	
					element *temp;
					pre->next=tempa->next;
					temp = tempa;
					tempa=pre;
					delete temp;
					break;
				}
		}
	if(this->first->next == NULL)
		cout << "A-B = NONE" << endl;
	return *this;
}
