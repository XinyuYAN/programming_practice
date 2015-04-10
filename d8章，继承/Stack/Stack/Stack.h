#include <iostream>
using namespace std;

class LinearList
{
private:
	struct Node
	{
		int x;
		Node *next;
	};
	int count;//记录该节点所在位置
	Node *first;
public:
	LinearList();//构造函数
	~LinearList();//析构函数
	bool insert(int x,int pos);//在pos位置后插入一个元素x，pos为0时在第一个元素之前插入，成功返回true
	bool remove(int &x,int pos);//删除位置pos处的元素，操作成功返回true
	int element(int pos) const;//返回位置pos处的元素
	int search(int x)const;//查找值为x的元素，返回元素的位置，未找到返回0
	int length() const;//返回元素个数
	void display();
};
class Stack
{
	LinearList list;
public:
	bool en_stack(int i)
	{
		return list.insert(i,0);
	}
	bool de_stack(int &i)
	{
		return list.remove(i,1);
	}
};


LinearList::LinearList()
{
	first = new Node;
	first->next=NULL;
	count =0;
}
LinearList::~LinearList()
{
	for(Node *p=first;p!=NULL;)
	{
		Node* q=p;
		p=p->next;
		delete q;
	}
}
bool LinearList::insert(int x,int pos)
{
	if(pos == 0)//说明在第一个元素之前插入
	{
		Node *temp=new Node;
		temp->x=x;//值存入
		temp->next=first->next;
		first->next=temp;
		count++;
		return true;
	}
	else 
	{
		int i=1;
		Node *search=first->next;//(从第一个元素开始搜查位置)
		while(i<=pos)
		{
			if(i == pos)//说明找到元素
			{
				Node *temp=new Node;
				temp->x=x;//值存入
				temp->next=search->next;//改变链接方式
				search->next=temp;
				count++;
				return true;
			}
			else
			{
				i++;
				search=search->next;
			}
		}
		if(i>count)//说明没找到
			return false;
	}
}
bool LinearList::remove(int &x,int pos)
{
	int i=1;
	Node *search=first->next;//(从第一个元素开始搜查位置)
	Node *pre=first;
	while(i<=pos)
	{
		if(i == pos)//说明找到元素
		{
			if(search->x != x)
				{
					cout << "error,please reput the element's x" << endl;
					return false;
				}
			pre->next=search->next;
			delete search;
			count--;
			return true;
		}
		else
		{
			i++;
			search=search->next;
			pre=pre->next;
		}
	}
	if(i>count)//说明没找到
		return false;
}
int LinearList::element(int pos) const
{
	int i=1;
	Node *search=first->next;//(从第一个元素开始搜查位置)
	while(i<=pos)
	{
		if(i == pos)//说明找到元素
		{
			int x=search->x;
			return x;
		}
		else
		{
			i++;
			search=search->next;
		}
	}
	if(i>count)//说明没找到
	{
		cout << "wrong pos"<<endl;
		return -1;
	}
}
int LinearList::search(int x) const
{
	int i=1;
	Node *search=first->next;//(从第一个元素开始搜查位置)
	while(search !=NULL)
	{
		if(search->x == x)//说明找到元素
		{
			return i;
		}
		else
		{
			i++;
			search=search->next;
		}
	}
	if(search == NULL)//说明没找到
		return 0;
}
int LinearList :: length() const
{
	return count;
}
void LinearList::display()
{
	cout << "共有" << count << "个元素" << endl;
	for(Node *h=first->next;h!=NULL;h=h->next)
		cout << h->x <<endl;
}