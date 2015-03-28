#include <iostream>
using namespace std;

class IntSet
{
private:
    struct element
    {
        int num;//�������
        element *next;//ָ��
    };
    element* first;
public:
    IntSet();//����
    IntSet(const IntSet &s);//�������캯��
	IntSet(int intArray[],int length);//�����������鹹�����Ķ���
    ~IntSet();//��������
    void print()const;//��ʾ�����е�����Ԫ��
    IntSet union2(const IntSet& s) const;//���㼯�ϵĲ���
    IntSet intersection2(const IntSet& s)const; //���㼯�ϵĽ���
	IntSet& operator += (const int e);//��e�Ӽ����м���
	IntSet& operator -= (const int e);//��e�Ӽ�����ɾ��
	IntSet operator & (const IntSet& s);//���������ϵĽ�����
	IntSet operator | (const IntSet& s);//�󲢼�
};
