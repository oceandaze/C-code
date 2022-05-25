// 1227.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#define  Pi 3.1415
using namespace std;

// class 	A
// {
// protected:
// 	int a;
// public:
// 	A(int x):a(x)
// 	{
// 		cout << "A::a=" << x << endl;
// 	}
// };
// class B
// {
// protected:
// 	int b;
// public:
// 	B(int x):b(x)
// 	{
// 		cout << "B::b=" << x << endl;
// 	}
// private:
// };
// 
// class C	:public A,public B
// {
// public:
// 	C() :B(20), A(10)
// 	{
// 		cout << "C::C()" << endl;
// 	}
// protected:
// private:
// };

class A
{
public:
	void test(){
		cout << "A::test()a=" << a << endl;
	}
protected:
private:
	int a;
};

class B :virtual public A
{
public:
};

class C :virtual public A
{
public:
};
class D	:public B,public C
{
public:
protected:
private:
};

int main1()
{
// 	B b1;
// 	A*p = &b1;
// 	A &a1 = b1;

	/*A a2;*/
	//B*q = &a2;	错误
	//B &b2 = a2;		错误
// 
// 	B b1;
// 	b1.output();
// 
// 	A*p = &b1;
// 	p->output(20);
	/*C c;*/
	D a1;
	a1.test();
    return 0;
}

/*
编写一个程序计算出圆和圆柱体的表面积和体积。
要求：
1. （1） 定义一个点（point）类，包含数据成员x, y（坐标点），以它为基类，派生出一个circle类（圆类），
增加数据成员r（半径），再以circle作为直接基类，派生出一个cylinder（圆柱体）类，再增加数据成员h(高)。
设计类中数据成员的访问属性。
2. （2） 定义基类的派生类圆、圆柱都含有求表面积和体积的成员函数和输出函数。
3. （3） 定义主函数，求圆、圆柱的面积和体积。*/

class Point
{
public:
	Point(float x=0,float y=0) {
		this->x = x;
		this->y = y;
	}
protected:
private:
	float x;
	float y;
};

class Circle :public Point
{
public:
	Circle(float r=0) {
		this->r = r;
	}
	float calArea(){
		return Pi*r*r;
	}
	void print(){
		cout << "圆面积=" << calArea() << endl;
	}
protected:
	float r;
};

class Cylinder:public Circle
{
public:
	Cylinder(float r,float b):h(b),Circle(r) {
	}
	void calSurface() {
		SA = calArea() * 2 + Pi * 2 * r;
	}
	void calVolume() {
		V = calArea()*h;
	}
	void print(){
		cout << "圆柱表面积=" << SA
			<< "圆柱体积=" << V << endl;
	}

protected:
private:
	float h;
	float SA;
	float V;
};

int main()
{
	Circle c1(5);
	c1.calArea();
	c1.print();

	Cylinder C1(10, 10);
	C1.calSurface();
	C1.calVolume();
	C1.print();
	return 0;
}