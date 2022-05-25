// 函数指针test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void fun(void(*draw) (void))
{
	draw();
}
 void draw()
 {
	 cout << "我是自定义draw" << endl;
 }
int main1()
{

	fun(draw);
    return 0;
}


typedef struct opertion
{
	int(*add)(int, int);
	int(*minus)(int, int);
	int(*mult)(int, int);
	int(*divide)(int, int);
}oper;

int addbymoon(int a, int b)
{
	return 10 * a + b;
}
int addbymars(int a, int b)
{
	return 10 * b + a;
}
int myminus(int a, int b)
{
	return a - b;
}
int mymult(int a, int b)
{
	return a* b;
}
int mydivide(int a, int b)
{
	return a /b;
}

oper moonopr = { moonopr.add=addbymoon,
				moonopr.minus = myminus,
				moonopr.mult = mymult,
				moonopr.divide = mydivide,
				};


int main()
{
	cout<<moonopr.add(1, 2)<<endl;
	cout << moonopr.minus(3, 4) << endl;

	cout << moonopr.mult(5, 6) << endl;

	cout << moonopr.divide(10, 5) << endl;
	return 0;

}