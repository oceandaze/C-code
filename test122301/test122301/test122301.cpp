// test122301.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "String.h"
#include "Student.h"
using namespace std;

class A
{
public:
	friend ostream &operator<<(ostream &out, const A& a1);
	friend istream &operator>>(istream &in, A& a1);

	A(int a) {
		this->a = a;
	}
private:
	int a;
};

istream &operator>>(istream &in, A& a1)
{
	in >> a1.a;
	return in;
}

ostream &operator<<(ostream &out, const A& a1)
{
	out << a1.a;
	return out;
}



int main1()
{
	int a = 0;
	//cout << a;

	A a1(10);
	//a1 << cout;
	cout << a1 << endl;
	//--------
	// void << endl => cout << endl;

	cout << "请输入数据：";
	A a2(0);
	cin >> a2;
	cout << "a2=" << a2 << endl;
    return 0;
}

int main2()
{
	Student s1;
	cout << "请输入学生信息，格式：姓名 年龄\n";
	cin >> s1;
	cout << s1 << endl;
	return 0;
}

int cmp1(const void * p1, const void * p2)
{
	const Student *s1 = (const Student *)p1;
	const Student *s2 = (const Student *)p2;

	return *s1 > *s2;
}

int main3()
{
	int n;
	cout << "请输入学生个数：";
	cin >> n;
	Student * p = new Student[n];
	for (int i = 0; i < n; ++i) {
		cout << "请输入第" << i + 1 << "学生信息，格式：姓名 年龄\n";
		cin >> p[i];
	}

	//排序
// 	for (int i = 0; i < n - 1; ++i) {
// 		for (int j = 0; j < n - 1 - i; ++j) {
// 			if (p[j + 1] < p[j]) {
// 				/*Student temp = p[j];*/
// 				swap(p[j], p[j + 1]);
// 			}
// 		}
// 	}
	qsort(p, n, sizeof(Student), cmp1);

	//输出
	cout << "姓名\t年龄\n";
	for (int i = 0; i < n; ++i) {
		cout << p[i] << endl;
	}

	return 0;
}
int sum(int a,int b)
{
	int n = a + b;
	return n;
}
int main()
{
	int c = sum(1,2);
	cout << c << endl;
	return 0;
}