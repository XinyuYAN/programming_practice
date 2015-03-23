#include "string_fuction.h"
#include <iostream>
using namespace std;
int main()
{
	char *match1="a.b";
	char *match2="a*ba";
	char *match3="a-.b*c.d";
	char *str1="acabac";//(0,1,0)
	char *str2="ccacb.bcccd";//(1,0,0)
	char *str3="aaaaa.bbdecvdeced";//(0,0,1)
	String s1(str1);
	String s2(str2);
	String s3(str3);
// s2.delet("b");
// s2.display();
// s2.replace("ac","a");
// s2.display();
// cout << s1.search(match2) << endl;
	cout << s1.search(match1) << s1.search(match2) <<s1.search(match3)<<endl;
	cout << s2.search(match1) << s2.search(match2) <<s2.search(match3) << endl;
	cout << s3.search(match1) << s3.search(match2)<<s3.search(match3)<<endl;
	return 0;
}