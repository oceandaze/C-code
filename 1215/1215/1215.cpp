// 1215.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "String.h"
#include<iostream>
#include "File.h"
using namespace std;

class Student
{
public:
	Student(const char *n,int a)
	{
		strcpy_s(name, n);
		age = a;
	}
	void output()
	{
		cout << "姓名：" << name << "\n年龄：" << age << endl;
	}
private:
	char name[32];
	int age;
};

//int main1()
//{
//	Student s1("小明", 18);
//	s1.output();
//	Student s2(s1);
//	s2.output();
//	Student s3 = s1;
//	s3.output();
//	Student * s4 = new Student("小红",15);
//	s4->output();
//	
//    return 0;
//}
//int main2()
//{
//	String s1("ABC");
//	{
//		String s2(s1);
//		s2.output();
//	}
//	s1.output();
//
//	File f1("1.text");
//	{
//		//File f2 = f1;
//		//f2.Write("abc");
//	}
//	f1.Write("123");
//	f1.Print();
//	
//	return 0;
//}
//
int main()
{
	
	//String s1("大家好，我是渣渣辉");
	//s1.cat(",是兄弟就来玩啊。");
	//cout<< s1.c_str() << endl;

	//String s2(s1);
	//cout << s2.c_str() << endl;
	//cout << s2.size() << endl;
	//cout << s2.empty() << endl;

	//s2.cat("-----");
	//if (s1.equal(s2))
	//{
	//	cout << "s1和s2相同" << endl;
	//}
	//else
	//{
	//	cout << "s1和s2不相同" << endl;
	//}
	String s3("123456");
	String s4 = s3.substr(1,3);
	//String s4(s3.substr(1, 3));
	s4.output();//输出234
	return 0;
}
