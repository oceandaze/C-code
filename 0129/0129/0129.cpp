// 0129.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "String.h"
#include <iostream>
using namespace std;
// int main1()
// {
// 	String s("hello world");
// 	s.output();
// 	cout << s << endl;
// 	cout << "s.size()=" << s. size() << endl;
// 	cout << "s.length()=" << s.length() << endl;
// 	cout << "s.empty()=" << boolalpha<<s.empty() << endl;
// 	s += "123456";
// 	cout << s << endl;
// 	String s1 ="000";
// 	s1 = s + "hello";
// 	cout << s << endl;
// 	cout << s.c_str() << endl;
//     return 0;
// }


int main2()
{
	int  a = 0;
	int &b = a;
	b = 10;
	cout << b << endl;

	return 0;
}
int main3()
{
	int  a = 0;
	const int &b = 8998;
	//b = 10;
	cout << b << endl;

	return 0;
}
int main()
{
	int &&a = 6;
	a = 10;
	cout << "a=" << a << endl;
	return 0;
}
String getInput(const char*p)
{
	String str(p);
	return str;
}

int main4()
{
	String s2 = getInput("123554");
	cout << "s2=" << s2 << endl;
	cout << "--------------" << endl;
	s2 = getInput("5566");
	cout << "s2=" << s2 << endl;
	cout << "--------------" << endl;
	s2 = String("7788");
	cout << "s2=" << s2 << endl;
	return 0;
}