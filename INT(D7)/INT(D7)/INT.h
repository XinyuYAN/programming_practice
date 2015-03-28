#include <iostream>
#include <cstring>
using namespace std;

class INT
{
private:int len;
		char *str;
public:
	INT()
	{	
		str = NULL;
		len = 0;
	}//构造函数
	INT(char *a)
	{
		str = new char[strlen(a)+1];
		len = strlen(a);
		strcpy(str,a);
	}
	INT (const INT& a)
	{
		len=a.len;
		str=new char[strlen(a.str)+1];
		strcpy(str,a.str);
	}
	INT (int a)
	{
		int i;
		bool sign=false;
		str = new char[20];
		memset (str,0,20);
		if(a <0)
		{
		sign=true;
			str[0]='-';
		}
		for(i=sign;a/10!=0;a=a/10,i++)
			str[i]=a % 10+48;
		str[i]=a%10+48;
		int n;
		n=strlen(str);
 		for(i=0;i<n/2;i++)
		{char t=str[i];str[i]=str[n-1-i];str[n-1-i]=t;}
		len=strlen(str);
}
	~INT()
	{
		delete str;
		str = NULL;
	};//析构函数
	void display();//显示函数
	friend INT operator +  (const INT& a1, const INT& a2);
	friend INT operator - (const INT& a,const INT& ba);
	friend INT operator * (const INT& a,const INT& b);
	friend INT operator / (const INT& a,const INT& b);
};

INT operator + (const INT& a1,const INT& a2)
{
	INT c;
	c.str=new char[a1.len +a2.len+1];
	memset(c.str,0,a1.len+a2.len+1);
	c.len=strlen(c.str);
	bool sign1,sign2,in;
	int temp;
	sign1=sign2=false;
	in=false;
	if(a1.str[0] == '-')
		sign1 = true;
	if(a2.str[0] == '-')//如果有一项为负数
		sign2 = true;
	if(sign1 ^ sign2)
	{
		if(sign1 == true)
		{
			INT a;
			a.str=new char[100];
			INT ba(a2);
			strcpy(a.str,a1.str+1);
			a.len = strlen(a.str);
			INT e(ba-a);
			return e;
		}
		if(sign2 == true)
		{
			INT a(a1);
			INT ba;
			ba.str= new char[100];
			strcpy(ba.str,a2.str+1);
			ba.len=strlen(ba.str);
			INT e(a-ba);
			return e;
		}
	}
	//	return (a1-a2);//调用减法重载
	else//说明同正 或同负
	{
		int lenc;
		if(a1.len> a2.len)
			lenc=a1.len;
		else 
			lenc=a2.len;
		if(sign1 == true)
			c.str[0]='-';
		int i,j;
		for(i=a1.len-1,j=a2.len-1;i>=sign1 && j>=sign2;i--,j--,lenc--)
		{
			temp=a1.str[i]+a2.str[j]+in-96;//临时存放每一位相加结果
			in=false;
			if(temp >= 10)
					in=true;//有进位
			c.str[lenc]=temp % 10 +48;
		}//循环完成加法
		if((a1.len == a2.len) && in==true)
				c.str[lenc]=49;
		else c.str[lenc]=' ';
		if(a1.len > a2.len)
			{
				for(;i>=sign1;i--,lenc--)
				{	
					temp=a1.str[i]+in-48;//临时存放每一位相加结果
					in=false;
					if(temp >= 10)
						in=true;//有进位
					c.str[lenc]=temp % 10 +48;
				}
				if(in == true)
					c.str[lenc]=49;
				else c.str[lenc]=' ';
			}
		else
			{
				for(;j>=sign2;j--,lenc--)
				{	
					temp=a2.str[j]+in -48;//临时存放每一位相加结果
					in=false;
					if(temp >= 10)
						in=true;//有进位
					c.str[lenc]=temp % 10 +48;
				}
				if(in == true)
					c.str[lenc]=49;
				else c.str[lenc]=' ';
			}
	}
	c.len=strlen(c.str);
	return c;
}
INT operator - (const INT& a,const INT& ba)
{
	INT c;
	c.str=new char[10];
	memset(c.str,0,a.len+ba.len+1);
	bool sign1,sign2;
	sign1=sign2=false;
	if(a.str[0] == '-')
		sign1 = true;
	if(ba.str[0] == '-')//如果有一项为负数
		sign2 = true;
	if(sign1 != sign2)//说明异号
	{
		INT d;
		d.str=new char[a.len+ba.len+1];//将符号转变 ///?????????????为什么！！！！！！！！！！！定义成strlen（+）+1就不能成功析构？
		memset(d.str,0,a.len+ba.len+1);
		if(ba.str[0] == '-')	
			strcpy(d.str,ba.str+1);//拷贝被减数
		else
		{
			d.str[0]='-';
			strcpy(d.str+1,ba.str);//将ba变成负数
		}
		d.len=strlen(d.str);
		INT e(a);
		INT f(e+d);
		return f;
	}
	else //说明同号
	{
		
		char*t1,*t2;//存放被减数和减数
		t1=new char[a.len+1];
		strcpy(t1,a.str);
		t2=new char[ba.len+1];
		strcpy(t2,ba.str);
		if(t1[0] == '-')//说明两个数是负数
		{
			if(a.len < ba.len)//说明被减数大于减数
			{
L1:				t1=new char[ba.len+1];
				strcpy(t1,ba.str+1);//不再需要符号
				t2=new char[a.len+1];
				strcpy(t2,a.str+1);
				c.str[0]=' ';//先把负号存起来
			}
			else 
			{
				if(a.len == ba.len)
					for(int i=0;i<a.len;i++)
						if(a.str[i] < ba.str[i])//说明被减数大于减数
							goto L1;
					c.str[0]='-';
					t1=new char[a.len+1];
					strcpy(t1,a.str+1);
					t2=new char[ba.len+1];
					strcpy(t2,ba.str+1);
			}
		}
		else 
		{
			if(a.len < ba.len)//说明被减数小于减数的情况
			{
L2:				t2=new char[a.len+1];
				strcpy(t2,a.str);
				t1=new char[ba.len+1];
				strcpy(t1,ba.str);
				c.str[0]='-';//先把负号存起来
			}//交换减数和被减数
			else
			{
				if(a.len == ba.len)
						for(int i=0;i<a.len;i++)
						if(a.str[i] < ba.str[i])//说明被减数小于减数
							goto L2;
						else break;
				c.str[0]=' ';
			}
		}
		int i,j,lenc,temp;
		bool in=false;
		lenc=strlen(t1);
		for(i=strlen(t1)-1,j=strlen(t2)-1;j>=0;i--,j--,lenc--)
		{
			temp=t1[i]-t2[j]-in;//临时存放每一位相加结果
			in=false;
			if(temp < 0)
			{
				in=true;//有借位
				temp+=10;
			}
			c.str[lenc]=temp % 10 +48;
		}//循环完成减法
		if(strlen(t1)> strlen(t2))
		{
			for(;i>=0;i--,lenc--)
			{	
				temp=t1[i]-in-48;//临时存放每一位相加结果
				in=false;
				if(temp < 0)
				{
					in=true;//有进位
					temp+=10;
				}
				c.str[lenc]=temp % 10 +48;
			}
		}

	}
	c.len=strlen(c.str);
	if(c.str[0]== ' ')
	{
		for(int i=1;i<=c.len;i++)
			c.str[i-1]=c.str[i];
		c.len-=1;
	}
	int pre=0;
	int i;
	if(c.str[pre] == '0')
	{
		for(i=1;i<c.len;i++)
		if(c.str[pre]=='0' && c.str[i] != 0)//此处对应前面的i个0
				break;
		if(i != c.len || c.str[c.len]=='0')
		{
			char *p=new char[c.len];
			strcpy(p,c.str+i);
			strcpy(c.str,p);
		}
		c.len=strlen(c.str);
	}
	return c;
}
INT operator *(const INT& a,const INT& b)
{
	INT c;
	c.str=new char[100];
	memset(c.str,0,100);
	c.len=strlen(c.str);
	bool sign1,sign2;
	int lenc,in,temp;
	int j,i;
	sign1=sign2=false;
	in=false;
	if(a.str[0] == '-')
		sign1 = true;
	if(b.str[0] == '-')//如果有一项为负数
		sign2 = true;
	for(j=b.len-1;j>=sign2;j--)
	{
		bool addin=false;
		in=0;
		for(i=a.len-1,lenc=a.len+j+1-sign1-sign2;i>=sign1;i--,lenc--)
		{	
			temp=in+(b.str[j]-48)*(a.str[i]-48);
			in= temp/10;
			temp=addin+temp % 10 + c.str[lenc];
			addin=temp/10;
			c.str[lenc]=temp%10;
		}
		if(in !=0 || addin)
		{
			temp=in+addin+c.str[lenc];
			c.str[lenc]=temp%10;
		}
	}
	lenc=a.len+b.len-sign1-sign2;
	for(int m=1;m<=lenc;m++)
	{
		c.str[m]+=48;
	}
	if(sign1 ^ sign2)
		c.str[0]='-';
	else c.str[0]=' ';
	c.len=strlen(c.str);
	return c;
}
INT operator / (const INT& a,const INT& b)//循环减
{
	INT c;
	c.len=1;
	c.str=new char[a.len+2];
	memset(c.str,0,a.len+2);
	bool sign1,sign2,in;
	int j,i,lenc;
	sign1=sign2=false;
	if(a.str[0] == '-')
		sign1 = true;
	if(b.str[0] == '-')//如果有一项为负数
		sign2 = true;
	if(a.len-sign1 < b.len-sign2)//说明被减数小于减数
		{
L1:			c.str[0]='0';
			return c;
		}
	else if(a.len-sign1 == b.len-sign2)
	{
		for(int m=0;m<a.len-sign1;m++)
			if(a.str[m] < b.str[m])
				goto L1;
	}
	//现在说明被除数大于除数了
	INT d;
	d.str=new char[a.len+1];
	memset(d.str,0,a.len+1);
	strcpy(d.str,a.str+sign1);
	d.len=strlen(d.str);
	INT e;
	e.str=new char[b.len+1];
	memset(e.str,0,b.len+1);
	strcpy(e.str,b.str+sign2);
	e.len=strlen(e.str);
	in = true;
	lenc = a.len;
	for(i=0;in == true;i++)
	{
		INT f(d-e);
		if(f.str[0]=='-')//说明减多了
			break;
		strcpy(d.str,f.str);
		d.len=strlen(d.str);
		f.len=strlen(f.str);
	}
	INT g(i);
	if(sign1 ^ sign2)
			c.str[0] = '-';
	else
			c.str[0] = ' ';
	strcat(c.str,g.str);
	return c;
}
void INT :: display()
{
	cout << str << endl;
}