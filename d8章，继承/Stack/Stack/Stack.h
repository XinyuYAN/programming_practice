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
	int count;//��¼�ýڵ�����λ��
	Node *first;
public:
	LinearList();//���캯��
	~LinearList();//��������
	bool insert(int x,int pos);//��posλ�ú����һ��Ԫ��x��posΪ0ʱ�ڵ�һ��Ԫ��֮ǰ���룬�ɹ�����true
	bool remove(int &x,int pos);//ɾ��λ��pos����Ԫ�أ������ɹ�����true
	int element(int pos) const;//����λ��pos����Ԫ��
	int search(int x)const;//����ֵΪx��Ԫ�أ�����Ԫ�ص�λ�ã�δ�ҵ�����0
	int length() const;//����Ԫ�ظ���
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
	if(pos == 0)//˵���ڵ�һ��Ԫ��֮ǰ����
	{
		Node *temp=new Node;
		temp->x=x;//ֵ����
		temp->next=first->next;
		first->next=temp;
		count++;
		return true;
	}
	else 
	{
		int i=1;
		Node *search=first->next;//(�ӵ�һ��Ԫ�ؿ�ʼ�Ѳ�λ��)
		while(i<=pos)
		{
			if(i == pos)//˵���ҵ�Ԫ��
			{
				Node *temp=new Node;
				temp->x=x;//ֵ����
				temp->next=search->next;//�ı����ӷ�ʽ
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
		if(i>count)//˵��û�ҵ�
			return false;
	}
}
bool LinearList::remove(int &x,int pos)
{
	int i=1;
	Node *search=first->next;//(�ӵ�һ��Ԫ�ؿ�ʼ�Ѳ�λ��)
	Node *pre=first;
	while(i<=pos)
	{
		if(i == pos)//˵���ҵ�Ԫ��
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
	if(i>count)//˵��û�ҵ�
		return false;
}
int LinearList::element(int pos) const
{
	int i=1;
	Node *search=first->next;//(�ӵ�һ��Ԫ�ؿ�ʼ�Ѳ�λ��)
	while(i<=pos)
	{
		if(i == pos)//˵���ҵ�Ԫ��
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
	if(i>count)//˵��û�ҵ�
	{
		cout << "wrong pos"<<endl;
		return -1;
	}
}
int LinearList::search(int x) const
{
	int i=1;
	Node *search=first->next;//(�ӵ�һ��Ԫ�ؿ�ʼ�Ѳ�λ��)
	while(search !=NULL)
	{
		if(search->x == x)//˵���ҵ�Ԫ��
		{
			return i;
		}
		else
		{
			i++;
			search=search->next;
		}
	}
	if(search == NULL)//˵��û�ҵ�
		return 0;
}
int LinearList :: length() const
{
	return count;
}
void LinearList::display()
{
	cout << "����" << count << "��Ԫ��" << endl;
	for(Node *h=first->next;h!=NULL;h=h->next)
		cout << h->x <<endl;
}