// test122301.cpp : �������̨Ӧ�ó������ڵ㡣
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

	cout << "���������ݣ�";
	A a2(0);
	cin >> a2;
	cout << "a2=" << a2 << endl;
    return 0;
}

int main2()
{
	Student s1;
	cout << "������ѧ����Ϣ����ʽ������ ����\n";
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
	cout << "������ѧ��������";
	cin >> n;
	Student * p = new Student[n];
	for (int i = 0; i < n; ++i) {
		cout << "�������" << i + 1 << "ѧ����Ϣ����ʽ������ ����\n";
		cin >> p[i];
	}

	//����
// 	for (int i = 0; i < n - 1; ++i) {
// 		for (int j = 0; j < n - 1 - i; ++j) {
// 			if (p[j + 1] < p[j]) {
// 				/*Student temp = p[j];*/
// 				swap(p[j], p[j + 1]);
// 			}
// 		}
// 	}
	qsort(p, n, sizeof(Student), cmp1);

	//���
	cout << "����\t����\n";
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