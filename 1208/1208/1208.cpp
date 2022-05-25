// 1208.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;
void test(int a,int *p,int &b)
{
	a += 1;
	*p += 1;
	b += 1;
}
int main01()
{
	//bool a = true;
	//bool b = false;
// 	int a1 = 0;
// 	int & a2 = a1;
// 	int &b = a2;
// 	a1 = 10;
// 	cout << a2 << endl;
// 	b = 20;
// 	cout << a2 << endl;
// 	int *p;
// 	p = &b;
// 	cout << *p << endl;
// 	cout << p << endl;
// 	cout << &a1 << endl;
// 	cout << &a2 << endl;
// 	int &a3;
// 	int &a4 = 0;

	int a1 = 1;
	int a2 = 2;
	int a3 = 3;
	test(a1,&a2,a3);
	cout << "a1=" << a1 
		<< "\na2=" << a2 
		<< "\na3="<< a3 << endl;
	
    return 0;
}

