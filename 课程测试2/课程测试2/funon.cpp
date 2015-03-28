
#include "IntSet.h"

void main()
{
	int a[4] = {1,2,3};
	int b[3] = {1,2,4};
	//int *c = NULL;
	string largeStr;
	int large[2000];
	for (int i = 0;i < 2000;i++)
	{
		large[i] = i;
	}

	cout << "constructor\n";
	IntSet normalSet(b,3);
	cout << "correct: 1 2 4 \n answer: ";
	normalSet.print();
	cout << endl;
	IntSet cocurrent(a,3);
	
	cout << endl;
	cout << "\noperator += " << endl;	
	normalSet += 5;
	cout << "+= 5:  \ncorrect: 1 2 4 5  \n answer: " ;
	normalSet.print();
	cout << endl;
	normalSet += 5;
	cout << "+= 5:  \ncorrect: 1 2 4 5  \n answer: " ;
	normalSet.print();
	cout << endl;

	cout << endl;
	cout << "\noperator -= " << endl;	

	normalSet -= 5;
	cout << "-= 5:  \ncorrect: 1 2 4  \n answer: " ;
	normalSet.print();
	cout << endl;
	normalSet -= 5;
	cout << "-= 5:  \ncorrect: 1 2 4  \n answer: " ;
	normalSet.print();
	cout << endl;
	normalSet -= 1;
	//cout << "-= 1:  \ncorrect: 2 4  \n answer: " ;
	//normalSet.print();
	//cout << endl;
	normalSet -= 2;
	/*cout << "-= 2:  \ncorrect: 4  \n answer: " ;
	normalSet.print();
	cout << endl;*/
	normalSet -= 4;
	//cout << "-= 4:  \ncorrect: empty \n answer: " ;
	cout << "-= 1 -= 2 -= 4:  \ncorrect: empty \n answer: " ;
	normalSet.print();
	cout << endl;

	cout << endl;
	cout << "\noperator | " << endl;	

	IntSet normalSet2(b,3);
	//IntSet unionSet = normalSet | cocurrent;
	cout << "a | b: \ncorrect: 1 2 3 4  \n answer: ";
	(normalSet2 | cocurrent).print();
	cout << endl;

	cout << endl;
	cout << "\noperator & " << endl;	

	//IntSet interS = normalSet & cocurrent;
	cout << "a & b: \ncorrect: 1 2  \n answer: " ;
	(normalSet2 & cocurrent) .print();
	cout << endl;


	cout << endl;
	cout << "\nempty set " << endl;	

	IntSet emptySet(b,0);
	cout << "correct: empty\n answer: " ;
	emptySet.print();
	cout << endl;
	
	//IntSet interEmpty = normalSet & emptySet;
	cout << "a & b:  \ncorrect: empty  \n answer: " ;
	(normalSet2 & emptySet).print();
	cout << endl;
	//IntSet unionEmpty = normalSet | emptySet;
	cout << "a | b:  \ncorrect: 1 2 4  \n answer: " ;
	(normalSet2 | emptySet).print();
	cout << endl;

	cout << endl;
	cout << "\nlarge set " << endl;	

	//为方便看，建议先注释掉该部分
	IntSet largeS(large,2000);
	largeS.print();
	cout << endl;
	cout << "a & b:  \ncorrect: 1 2 4  \n answer: " ;
	(normalSet2 & largeS).print();
	cout << endl;
	
}
IntSet& IntSet ::operator += (const int e)
{
	element *temp =new element;
    temp->num = e;
    temp -> next = first->next;
    first->next = temp;//新元素插入在表头
    return *this;
}
 IntSet& IntSet ::operator -= (const int e)
 {

    element *pre=first;
	element *temp;
    for(temp = first->next;temp != NULL;pre=temp,temp = temp->next)
		if(e == temp->num)
            {
                pre->next = temp ->next;   
                delete temp;
                break;
            }
		if(temp == NULL)//说明没找到需要操作的元素
			cout << " 集合中无该元素，无法删除" << endl;
    return *this;
 }
 IntSet IntSet ::operator & (const IntSet& s)
 {
	IntSet c(*this);
	element *tempa,*tempb,*pre;
	for(pre = c.first,tempa=pre->next;tempa != NULL;pre=tempa,tempa =tempa->next)
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
	if(c.first->next == NULL)
        cout << "A^B = none" << endl;
    return c;
 }
IntSet :: IntSet()
{
    element *p=new element;//创建表头节点
    p->next = NULL;
    first= p;
}

IntSet :: ~IntSet()
{
    element *temp=first;
    for(element *p= temp; p != NULL;)
    {
        temp =p;
        p =p->next;
        delete temp;
    }
}
IntSet :: IntSet(const IntSet &s)
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
IntSet :: IntSet(int intArray[],int length)//从给定整形数组构造一个该类的对象
{
	element *newer=new element;//创建表头节点
    newer->next = NULL;
	first= newer;
    for(int i=0;i<length;++i)
    {
        element * newer=new element;
        newer ->num = intArray[i];
        newer->next = first->next;
        first->next = newer;
    }
}

void IntSet :: print() const
{
    for( element *temp=first->next;temp != NULL;temp=temp->next)
        cout << temp->num << ",";
    cout << endl;
}

IntSet IntSet :: operator | (const IntSet& s)//计算集合的并集
{
	IntSet c(*this);
    element *last=NULL,*tempb,*tempa;
    for(last= c.first->next;last->next != NULL;last=last->next);//last指向表尾
    for (tempb=s.first->next;tempb != NULL;tempb=tempb->next)
    {
        for(tempa=c.first->next;tempa != NULL; tempa=tempa->next)
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
    return c;
}
