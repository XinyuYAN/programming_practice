#include <iostream>
using namespace std;
class Intset
{
private:
	struct element
	{
		int num;//存放数据
		element *next;//指针
	};
	element* first;
public:
	Intset();//构造
	Intset(const Intset &s);//拷贝构造函数
	~Intset();//析构函数
	bool is_empty() const; //判断是否为空集
	int size() const;//获取元素个数
	bool is_element(int e)const;//判断e是否属于该集合
	bool is_subset(const Intset& s) const;//判断s是否包含于集合
	bool is_equal(const Intset& s) const;//判断集合是否相等
	Intset& insert(int e);//将e添加到集合中
	Intset& remove(int e);//将e从集合中删除
	void display()const;//显示集合中的所有元素
	Intset union2(const Intset& s) const;//计算集合的并集
	Intset intersection2(const Intset& s)const; //计算集合的交集
	Intset difference2(const Intset& s)const;//计算集合的差
};
Intset :: Intset()
{
	element *p=new element;//创建表头节点
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
	element *newer=new element;//创建表头节点
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
	first->next = temp;//新元素插入在表头
	return *this;
}
Intset& Intset :: remove(int e)
{
	if(Intset ::is_element(e) == 0)
		cout << "无该元素" << endl;
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
		cout << "该集合不为空" << endl;
		return true; 
	}
	else
	{
		cout << "该集合为空"<< endl;
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
bool Intset ::is_subset(const Intset& s) const//判断s是否包含于集合
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
Intset Intset :: union2(const Intset& s) const//计算集合的并集
{
	element *last=NULL,*tempb,*tempa;
	if(is_subset(s))
		return *this;
	for(last= this->first->next;last->next != NULL;last=last->next);//last指向表尾
	for (tempb=s.first->next;tempb != NULL;tempb=tempb->next)
	{
		for(tempa=this->first->next;tempa != NULL; tempa=tempa->next)
			if(tempa->num == tempb->num)
				break;
		if(tempa == NULL)//说明该元素在c中没有对应的项，将它添加到c的链尾
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
Intset Intset :: intersection2(const Intset& s)const //计算集合的交集
{
	element *tempa,*tempb,*pre;
	for(pre = this->first,tempa=pre->next;tempa != NULL;pre=tempa,tempa =tempa->next)
		{
			for(tempb = s.first->next;tempb != NULL; tempb = tempb->next)	
				if(tempb ->num == tempa ->num)
					break;
			if(tempb == NULL)//说明该元素在b中没有，从交集中删去
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
Intset Intset ::difference2(const Intset& s)const//计算集合的差
{
	element *tempa,*tempb,*pre;
	for(pre = this->first,tempa=pre->next;tempa != NULL;pre=tempa,tempa =tempa->next)
		{
			for(tempb = s.first->next;tempb != NULL; tempb = tempb->next)	
				if(tempb ->num == tempa ->num)//若b中有，则从集合中删去
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
