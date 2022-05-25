// 1214.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include "String.h"
using namespace std;

/*
class  String
{
public:
	String(const char *str=nullptr)
	{
		if (str!=nullptr)
		{
			int len = strlen(str) + 1;
			p = new char[len];
			strcpy_s(p, len, str);
		}
		else
		{
			p = nullptr;
		}
		
	}
	void output()
	{
		cout << p << endl;
	}
	
	~String()
	{
		if (p!=nullptr)
		{
			delete[] p;
		}
		cout << "释放\n";
		
	}
private:
	char*p;
};
*/

int main1()
{
	//String s1("ABC hello");
	//s1.output();
	//String s2;
	//s2.output();
	//String s2[4]; //调用四次构造和析构
	//String*p;//为创建对象不调用构造和析构函数
// 	String*q=new String; //	堆上开辟的对象的内存并未释放，需要手动释放才会调用析构函数
// 	delete q;//释放q所指向的内存上的对象
	
	return 0;
}

int main()
{
	String s1("Hello world!");
	//String s1; //无参情况
	s1.cat("ABCD1"); //完成拼接功能
	s1.output(); //输出：Hello world!ABCD1
	cout << s1.size() << endl; //可以输出字符串长度
	return 0;
}