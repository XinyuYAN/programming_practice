#include <iostream>
using namespace std;

class IntSet
{
private:
    struct element
    {
        int num;//存放数据
        element *next;//指针
    };
    element* first;
public:
    IntSet();//构造
    IntSet(const IntSet &s);//拷贝构造函数
	IntSet(int intArray[],int length);//给定整形数组构造该类的对象
    ~IntSet();//析构函数
    void print()const;//显示集合中的所有元素
    IntSet union2(const IntSet& s) const;//计算集合的并集
    IntSet intersection2(const IntSet& s)const; //计算集合的交集
	IntSet& operator += (const int e);//将e从集合中加入
	IntSet& operator -= (const int e);//将e从集合中删除
	IntSet operator & (const IntSet& s);//求两个集合的交集；
	IntSet operator | (const IntSet& s);//求并集
};
