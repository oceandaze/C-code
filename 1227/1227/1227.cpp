// 1227.cpp : �������̨Ӧ�ó������ڵ㡣
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
	//B*q = &a2;	����
	//B &b2 = a2;		����
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
��дһ����������Բ��Բ����ı�����������
Ҫ��
1. ��1�� ����һ���㣨point���࣬�������ݳ�Աx, y������㣩������Ϊ���࣬������һ��circle�ࣨԲ�ࣩ��
�������ݳ�Աr���뾶��������circle��Ϊֱ�ӻ��࣬������һ��cylinder��Բ���壩�࣬���������ݳ�Աh(��)��
����������ݳ�Ա�ķ������ԡ�
2. ��2�� ��������������Բ��Բ��������������������ĳ�Ա���������������
3. ��3�� ��������������Բ��Բ��������������*/

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
		cout << "Բ���=" << calArea() << endl;
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
		cout << "Բ�������=" << SA
			<< "Բ�����=" << V << endl;
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