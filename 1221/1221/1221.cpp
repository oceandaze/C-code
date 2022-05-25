// 1221.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "String.h"
using namespace std;

class A
{
public:
	A(int x) :a(x){}
	friend void Test(A&o)
	{
		cout << "Test调用" << o.a << endl;
	}
private:
	int a;
	friend  void  output(A & o);
};

void  output(A & o)
{
	cout << o.a << endl;
}

int add(int a ,int b)
{
	return a + b;
}
double add(double a, double b)
{
	return a + b;
}

char* add(char*a ,char*b)
{
	strcat_s(a, 100, b);
	return a;
}

class B
{
public:
	B(int x):a(x) {}
	void print() { cout << a << endl; }
	void print() const;
private:
	int a;
};

void B::print()const
{
	cout << "const" << a << endl;
}
int main1()
{
// 	A t(100);
// 	output(t);
// 	Test(t);
// 	char str[100] = {"hello world"};
// 	cout << add(1, 2) << endl;
// 	cout << add(2.2, 3.3) << endl;
// 	cout << add((double)2, 3.3) << endl;
// 	cout << add(str, "小明") << endl;

	B b1(2);
	
	b1.print();
	const B &b2 = b1;//取别名
	b2.print();
    return 0;
}

int main()
{

	String s1("he");
	int a = -2345;
	s1.cat(a);
	s1.output();
	s1.cat("world");
	s1.output();
	cout<<boolalpha<<s1.equal("he2345world")<<endl;
	//String s2(nullptr);
	String s2("he");

	s2.cat(-356278.222);
	s2.output();
	cout << boolalpha << s2.equal(s1) << endl;

	String s3(s1);
	s3.output();
	cout << boolalpha << s3.equal(s1) << endl;

	double c = 1.2;
	cout << c << endl;
	return 0;
}