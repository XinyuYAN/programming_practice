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
      if(str[i+j] != p[j] )//说明两个字符不相等
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
      strcpy(p,str+i+j);//新建数组拷贝剩余数组
      strcpy(str+i,rep);
      strcat(str+i+len_rep,p);
      delete []p;
      len=strlen(str);
     }
    }
   }
  }
  bool search(char *a)//实现搜索子串的功能
  {
	int len =strlen(str);
	char *temps = new char[len+1];
	strcpy(temps,str);
	char *tempa = new char[strlen(a)+1];
	strcpy(tempa,a);
	for(int i=0;i<len;i++)
	{
		if(a[0] == '-')//一开始遇到转义符号
			if(a[1] == str[i])//寻找到是否有匹配的符号
				if(search_left(temps+i+1,tempa+2)) 
					return true;
		if(a[0] == str[i])
		{
			if(search_left(temps+i+1,tempa+1))
				return true;
		}
		if(a[0] == '*')//说明代表任意字符
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
 // bool special_search(char *str,char *a)//必须严格匹配
 // {
	//int i=0;
	//if(str[i] == a[i])//基本字符串功能
	//{
	//	if(strlen(a)==1)//说明该字符串匹配完成
	//		return true;
	//	else if(strlen(str) == 1)//说明待比较字符串已经到头
	//		return false;
	//	else if(special_search(str+1,a+1))
	//		return true;
	//}
	//if(a[i] == '-')//eg:(-.b.c)
	//{
	//	if(a[i+1] == str[i])
	//		{
	//			if(strlen(a)==1)//说明该字符串匹配完成
	//				return true;
	//			else if(strlen(str) == 1)//说明待比较字符串已经到头
	//				return false;
	//			else if(special_search(str+1,a+2))
	//				return true;
	//		}
	//}
	//if(a[i] == '*')//(任意多的元素)
	//{
	//	for(int j=i;j<strlen(str);j++)
	//		if(a[i+1] == str[j])
	//		{
	//			if(strlen(a)==1)//说明该字符串匹配完成
	//				return true;
	//			else if(strlen(str) == 1)//说明待比较字符串已经到头
	//				return false;
	//			else if(special_search(str+1+j,a+2))
	//				return true;
	//		}
	//}
	//if(a[i] == '.')//只能有一个元素
	//{
	//	if(a[i+1] == str[i])
	//		{
	//			if(strlen(a)==1)//说明该字符串匹配完成
	//				return true;
	//			else if(strlen(str) == 1)//说明待比较字符串已经到头
	//				return false;
	//			else if(special_search(str+1,a+2))
	//				return true;
	//		}
	//}
	//else 
	//	return false;


 // }
   bool search_left(char *str,char *a)//必须严格匹配
  {
	int i=0,j=0;
	int len=strlen(str);
	int lena=strlen(a);
	for(;i<lena,j<len;i++,j++)//基本字符串功能
	{
	L1:	if(a[i] == '.')
			i++,j++;
		if(a[i] == '*')
		{
			i++;//指向下一个数	
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