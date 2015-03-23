#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
class String
{
private: char *str;
public:String()
    { 
     str= NULL;
    }
  String(const char *p)
  {
   str = new char[strlen(p)+1];
   strcpy(str,p);
  }
  ~String()
  {
   delete []str;
   str= NULL;
  }
  void delet(char *p)
  {
   int len=strlen(str);
   int p_len = strlen(p);
   for(int i=0;i<len;++i)
   {
    if(str[i] == p[0])
    {
     int j;
     for(j=0;j<p_len;++j)
      if(str[i+j] != p[j] )//˵�������ַ������
       break;
     if( j == p_len)
     {
      strcpy(str+i,str+i+j);
     }    
    }
   }
  }
 void display()
  {
   cout << str << endl;
  }
  void replace(char *a,char *rep)
  {
   int len =strlen(str);
   int len_a = strlen(a);
   int len_rep = strlen(rep);
   for(int i=0;i<len;i++)
   {
    if(str[i] == a[0])
    {
     int j;
     for(j=0;j<len_a;++j)
     {
      if(str[i+j] != a[j])
       break;
     }
     if(j == len_a)
     {
      char *p=new char[strlen(str)+1];
      strcpy(p,str+i+j);//�½����鿽��ʣ������
      strcpy(str+i,rep);
      strcat(str+i+len_rep,p);
      delete []p;
      len=strlen(str);
     }
    }
   }
  }
  bool search(char *a)//ʵ�������Ӵ��Ĺ���
  {
	int len =strlen(str);
	char *temps = new char[len+1];
	strcpy(temps,str);
	char *tempa = new char[strlen(a)+1];
	strcpy(tempa,a);
	for(int i=0;i<len;i++)
	{
		if(a[0] == '-')//һ��ʼ����ת�����
			if(a[1] == str[i])//Ѱ�ҵ��Ƿ���ƥ��ķ���
				if(search_left(temps+i+1,tempa+2)) 
					return true;
		if(a[0] == str[i])
		{
			if(search_left(temps+i+1,tempa+1))
				return true;
		}
		if(a[0] == '*')//˵�����������ַ�
			if(a[1] == str[i])
			{
				if(search_left(temps+i,tempa+1))
					return true;
			}
		if(a[0] == '.')
			if(search_left(temps+1,tempa+1))
				return true;
	}
	return false;
	}
 // bool special_search(char *str,char *a)//�����ϸ�ƥ��
 // {
	//int i=0;
	//if(str[i] == a[i])//�����ַ�������
	//{
	//	if(strlen(a)==1)//˵�����ַ���ƥ�����
	//		return true;
	//	else if(strlen(str) == 1)//˵�����Ƚ��ַ����Ѿ���ͷ
	//		return false;
	//	else if(special_search(str+1,a+1))
	//		return true;
	//}
	//if(a[i] == '-')//eg:(-.b.c)
	//{
	//	if(a[i+1] == str[i])
	//		{
	//			if(strlen(a)==1)//˵�����ַ���ƥ�����
	//				return true;
	//			else if(strlen(str) == 1)//˵�����Ƚ��ַ����Ѿ���ͷ
	//				return false;
	//			else if(special_search(str+1,a+2))
	//				return true;
	//		}
	//}
	//if(a[i] == '*')//(������Ԫ��)
	//{
	//	for(int j=i;j<strlen(str);j++)
	//		if(a[i+1] == str[j])
	//		{
	//			if(strlen(a)==1)//˵�����ַ���ƥ�����
	//				return true;
	//			else if(strlen(str) == 1)//˵�����Ƚ��ַ����Ѿ���ͷ
	//				return false;
	//			else if(special_search(str+1+j,a+2))
	//				return true;
	//		}
	//}
	//if(a[i] == '.')//ֻ����һ��Ԫ��
	//{
	//	if(a[i+1] == str[i])
	//		{
	//			if(strlen(a)==1)//˵�����ַ���ƥ�����
	//				return true;
	//			else if(strlen(str) == 1)//˵�����Ƚ��ַ����Ѿ���ͷ
	//				return false;
	//			else if(special_search(str+1,a+2))
	//				return true;
	//		}
	//}
	//else 
	//	return false;


 // }
   bool search_left(char *str,char *a)//�����ϸ�ƥ��
  {
	int i=0,j=0;
	int len=strlen(str);
	int lena=strlen(a);
	for(;i<lena,j<len;i++,j++)//�����ַ�������
	{
	L1:	if(a[i] == '.')
			i++,j++;
		if(a[i] == '*')
		{
			i++;//ָ����һ����	
			if(a[i] == '.')
				goto L1;
			else
				if(a[i] == '-')
					i++;
				int k;
				for(k=0;k<len-j;k++)
			{
				if(str[j+k] == a[i])
				{
					j+=k;
					break;
				}
			}
			if(k == len-j)
				return false;
		}
		if(a[i] == '-')
		{
			i++;
			if(a[i] != str[j])
				break;
		}
		if(str[j] !=a[i])
			break;
	}
	if(i == lena)
		return true;
	else return false;
   }
};