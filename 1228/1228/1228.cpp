// 1228.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "Student.h"
#include "LoadData.h"
#include "App.h"
#include "MemData.h"
#include "Txtdata.h"
#include "TaskManagement.h"
using namespace std;

// class A1
// {
// public:
// 	 virtual void output()
// 	{
// 		cout << "A::output\n";
// 	}
// };
// class B	:public A1
// {
// public:
// 	virtual void output()
// 	{
// 		cout << "B::output\n";
// 	}
// };
// int main1()
// {
// 	A * P = new B;
// 	P->output();
//     return 0;
// }
// int main2()
// {
// // 	Student s1;
// // 	s1.setName("小明");
// // 	s1.setAge(18);
// // 	s1.setSex("男");
// // 	cout << s1 << endl;
// // 	cout << s1.getAge() << endl;
// 
// 	
// 	
// 	LoadData *p = nullptr;
// 	cout << "请选择数据源：\n1、内存\n2、文件" << endl;
// 	int n;
// 	cin >> n;
// 	if (n == 1){
// 		p = new MemData;
// 	}
// 	else if (n==2){
// 		p = new TxtData;
// 	}
// 	App app;
// 	app.run(p);
// 	delete p;
// 	return 0;
// }
// 
// int main3()
// {
// 	TaskManagement task;
// 
// 	while (1){
// 		task.menu();
// 		int n = 0;
// 		cin >> n;
// 		switch (n)
// 		{
// 		case 1:
// 			task.addTask();
// 			break;
// 		case 2:
// 			task.taskList();
// 			break;
// 		case 3:
// 			exit(1);
// 			break;
// 		default:
//			break;
// 		}
// 
// 	}
// 	return 0;
// }


//函数指针示例代码
// int test(int a)
// {
// 	cout << "test-" << a << endl;
// 	return 0;
// }
// 
// 
// int main4()
// {
// 	int(*F1)(int) = test;//函数指针变化
// 	F1(1);
// 
// 
// 	typedef int(*FT)(int);//别名
// 	FT f1 = test;
// 	f1(2);
// 	return 0;
// 
// }

class A
{
public:
	int a;
	int b;
	virtual void test()
	{
		cout << "test->1\n";
	}
	virtual void test1() 
	{
		cout << "test->2\n";
	}
};

int main5()
{

	cout << sizeof(A) << endl;
	typedef void(*Fun)();
	A a1;
	Fun* arr = (Fun*)*(int*)(&a1);
	Fun f1 = arr[0];
	Fun f2 = arr[1];
	f1();
	f2();
	return 0;
}