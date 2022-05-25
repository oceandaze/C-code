// 1217.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class A
{
private:
	int a;
public:
	A(int n)
	{
		a = n;
	}
	void update(int n)
	{
		a = n;
	}
	void output()  const
	{
		cout << a << endl;
		//a = 10;
	}
};
int main()
{
	const A a1(10);
	//a1.update(20);
	a1.output();
    return 0;
}

