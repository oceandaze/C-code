// 1211.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Color.h"
#include <iostream>
#include "Book.h"
#include "Student.h"

using namespace std;

inline void test(int a = 5);
void test2(int a, int b, int c = 2);


class 	String
{
public:
	String()
	{
		strcpy_s(str, "小黑");
		cout << "构造\n" << endl;
	}
	void output()
	{
		cout << str << endl;
	}
	void init()
	{
		strcpy_s(str, "小明");
	}
private:
	char str[64];
};
int main()
{
// 	Color c1;
// 	c1.setName("red");
// 	c1.infoShow();
// 	c1.setName();
// 	c1.infoShow();
// 
// 	test();
// 	test(10);
// 	test2(1,2);

	//String s1;
	//String s2[10];
// 	s1.init();
// 	s1.output();
	//String *p = new String[5];
	Book book1;
	book1.output();
	book1.input("C语言从入门到精通", "￥49.7", "明日科技");
	book1.output();

	Book book2("算法图解","￥30","Aditya Bhargava");
	book2.output();

	Student s1;
	s1.output();
	Student s2("周星驰",51);
	s2.output();


	int num = 0;
	cout << "请输入学生人数" << endl;
	cin >> num;
	Student *stu = new Student[num];
	char n[32] = {0};
	int a = 0;
	for (int i=0;i<num;i++)
	{
		cout << "请输入第"<<i<<"个学生的信息" << endl;
		cin >> n>>a;
		stu[i].input(n,a);
	}
	for (int i=0;i<num-1;i++)
	{
		for (int j=0;j<num-1-i;j++)
		{
			if (stu[j].ageCompare(stu[j+1]))
			{
				Student temp(stu[j]);
// 				stu[j].infoCopy(stu[j + 1]);
// 				stu[j + 1].infoCopy(temp);
				stu[j] = stu[j + 1];
				stu[j + 1] = temp;
			}
		}
	}
	for (int i=0;i<num;i++)
	{
		stu[i].output();
	}
	delete[] stu;
    return 0;
}

void test(int a)
{
	cout << a << endl;
}
void test2(int a, int b, int c )
{
	cout << a << " "
		<< b << " "
		<< c << " "
		<<endl;
}