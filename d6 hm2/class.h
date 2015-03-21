#include <iostream>
using namespace std;
class Intset
{
private:
	int num;//存放数据
	Intset *next;//指针
public:
	Intset();//构造
	Intset(const Intset &s);//拷贝构造函数
	~Intset();//析构函数
	bool is_empty() const; //判断是否为空集
	int size() const;//获取元素个数
	bool is_element(int e)const;//判断e是否属于该集合
	Intset& insert(int e);//将e添加到集合中
	Intset& remove(int e);//将e从集合中删除
	void display()const;//显示集合中的所有元素
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
	//delete this;//为什么this必须要delete掉？
}
Intset :: Intset(const Intset &s)
{
	
}
Intset& Intset :: insert(const int m)
{
	Intset *temp =new Intset;
	temp->num = m;
	temp -> next = this->next;
	this->next = temp;//新元素插入在表头
	return *this;
}
Intset& Intset :: remove(int e)
{
	if(Intset ::is_element(e) == 0)
		cout << "无该元素" << endl;
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
	for(Intset *temp = this ->next; temp != NULL;temp = temp->next)
		count++;
	cout << "元素个数为：" <<count << endl;
	return count;
}
bool Intset ::is_element(int e)const
{
	for(Intset *temp = this->next;temp != NULL;temp = temp->next)
		if(e == temp->num)
			return true;
	return false;
}