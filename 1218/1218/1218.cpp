// 1218.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include "Dir.h"

using namespace std;

class A 
{
	int a1;
	int a2, a3;
	int a4 = 5;
public:
	A() :a2(1), a3(2)
	{
		a1 = 0;
	}
	void output()
	{
		cout << "a1=" << a1 << endl;
		cout << "a2=" << a2 << endl;
		cout << "a3=" << a3 << endl;
		cout << "a4=" << a4 << endl;
	}
};


class Test
{
public:
	Test(int n) {
		cout << "n=" << n << endl;
	}
	~Test()
	{
		cout << "~Test()����" << endl;
	}
};
class A1
{
	Test t2;
	Test t1;
public:
	A1() :t2(2),t1(1)
	{
		cout << "A1()\n";
	}
	~A1()
	{
		cout << "~A1()����" << endl;
	}
protected:
private:
};

struct A2 
{
	A2()
	{
		cout << "A2()" << endl;
	}
	~A2() {
		cout << "~A2()\n";
	}
//private:
	void output() const
	{
		cout << "123\n";
	}
};

class Student
{
public:

	Student(const char *name,int age)
	{
		this->age = age;
		strcpy_s(this->name,32, name);
	}
	void output()const
	{
		cout << this->name <<" "
			<< this->age << endl;
	}
private:
	char name[32];
	int age;
};


class Point
{
	int x, y;
	static int no;
public:
	Point(int a,int b ):x(a), y(b)
	{
		++no;
	}
	static void print()
	{
		cout << "no=" << no << endl;
		//cout << "x=" << x << endl;	//���ܷ��ʷǾ�̬��Ա����
		//set();//���ܷ��ʷǾ�̬��Ա����������ʹ��thisָ��
	}
	void set()
	{
		cout << "set()\n";
	}
};

class B
{
	static int cnt;
public:
	B()
	{
		cnt++;
	}
	~B()
	{
		cnt--;
	}

	static void  print()
	{
		cout << cnt << endl;
	}
};
int Point::no = 0;

int B::cnt = 0;


void test()
{
	B b1, b2, b3;
	B::print();
}
int main1()
{
// 	A a;
// 	a.output();
	//A1 a;
// 	A2 a2;
// 	a2.output();
// 	Student s1("С��", 18);
// 	Student s2("С��",19);
// 	s1.output();
// 	s2.output();

// 	Point p(1, 10);
// 	cout << Point::no << endl;
// 
// 	Point::no = 5;
// 	cout << Point::no << endl;
// 	Point p1(2, 4);
// 	cout << Point::no << endl;
// 	cout << p1.no << endl;

// 	Point pt(1,10);
// 	Point * p1 = new Point(3, 3);
// 	pt.print();
// 	p1->print();
// 	Point::print();

	B b1, b2, b3;
	test();
	B::print();
    return 0;
}


/*
8��ʵ����Dir 
class Dir {
public: static bool remove(const char* name); //ɾ���ļ� 
		static bool mkdir(const char* name); //�����ļ��� 
		static int list(const char* name); //��ӡָ��Ŀ¼�µ��ļ��б��������ļ����� 
}; */
int main()
{

	bool a = Dir::remove("D:\\C++\\test\\text1.txt");
	cout << boolalpha << a << endl;

	bool b = Dir::mkdir("D:\\C++\\test2");
	cout <<boolalpha<<b << endl;

	int n= Dir::list("D:\\C++\\test\\*.txt");
	cout << n << endl;
	return 0;
}