// 1222.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "Student.h"
#include "String.h"


using namespace std;

class A
{
public:
	A(int a)
	{
		this->a = a;
	}
	void output()
	{
		cout << a << endl;
	}

	A operator+(const A &other) const
	{
		A temp = *this;
		temp.a += other.a;
		return temp;
	}

	A operator-(const A &other) const
	{
		A temp = *this;
		temp.a -= other.a;
		return temp;
	}
	A operator*(const A &other) const
	{
		A temp = *this;
		temp.a *= other.a;
		return temp;
	}
	A operator/(const A &other) const
	{
		A temp = *this;
		if (other.a!=0)
		{
			temp.a /= other.a;
			return temp;
		}
	}

	A operator%(const A &other) const
	{
		A temp = *this;
		if (other.a != 0)
		{
			temp.a %= other.a;
			return temp;
		}
	}

	bool operator <(const A &other) const
	{
		return a<other.a;
	}
	bool operator >(const A &other) const
	{
		return a > other.a;
	}
	bool operator ==(const A &other) const
	{
		return a == other.a;
	}
	bool operator !=(const A &other) const
	{
		return a != other.a;
	}

	A & operator+=(const A &other) 
	{
		this->a += other.a;
		return *this;
	}
	A & operator-=(const A &other)
	{
		this->a -= other.a;
		return *this;
	}
	A & operator*=(const A &other)
	{
		this->a *= other.a;
		return *this;
	}
	A & operator/=(const A &other)
	{
		if (other.a!=0)
		{
			this->a /= other.a;
			return *this;
		}
	}

private:
	int a;
};
/*
1��ʵ��һ��ѧ����
���������У�Ҫ���û�����ѧ�����������������ѧ������
��̬����ѧ�����󣬰���������(����ʽ���û�ѡ��)����������

Ҫ��������Ĺ�����ʹ�����������ɱȽϲ���


2��ʵ��һ��String�࣬Ҫ�����£�
1������ += �� + ��[](��ҪҪ˼��)���������

ʹ��ָ��ʵ��, ���������ɸ�����Ҫ�Լ����*/
void sort(Student*stu, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (stu[j]> stu[j + 1])
			{
				Student temp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = temp;
			}
		}
	}
}
int main1()
{
	int n = 0;
	cout << "������ѧ������" << endl;
	cin >> n;
	Student *stu = new Student[n];
	char name[32] = {0};
	int age = 0;
	for (int i=0;i<n;i++)
	{
		cout << "������ѧ��"<<i+1<<"����Ϣ" << endl;
		cin >> name >> age;
		stu[i].input(name, age);
	}
	sort(stu,n);
	for (int i = 0; i < n; i++)
	{
		stu[i].output();
	}
	delete[] stu;
	return 0;
}


int main()
{
	String s1("1234");
	s1.output();

	s1 += "abc";
	s1.output();
	String s3=s1 + "def";
	s3.output();
	cout << s3[5] << endl;
	s3[5] = 'A';
	cout << s3[5] << endl;
	const String s4("abcdef");
	cout << s4[5] << endl;
	return 0;
}

int main2()
{
// 	A a1(1);
// 	A  a2(2);
// 	A a3 = a1 + a2;
// 	a3.output();
// 	
// 	a3 = a1 + a1;
// 	a3.output();
// 
// 	a2 = a2 + a2;
// 	a2.output();
// 
// 	A a4 = a1*a2;
// 	a4.output();
// 
// 	a4 = a1 / a2;
// 	a4.output();
// 
// 	a4 = a1 % a2;
// 	a4.output();
// 
// 
// 
// 	cout << boolalpha << (a1 < a2) << endl;
// 	cout << boolalpha << (a1 > a2) << endl;
// 	cout << boolalpha << (a1 == a2) << endl;
// 	cout << boolalpha << (a1 != a2) << endl;
// 	A b1(2);
// 	A b2(4);
// 
// 	b1 += b2;
// 	b1.output();
// 	b1 -= b2;
// 	b1.output();
// 	b1 *= b2;
// 	b1.output();
// 	b1 /= b2;
// 	b1.output();

	Student	  s1("���1",21);
	Student s2("���2", 23);

	if (s1<s2)
	{
		s1.output();
		cout << "С" << endl;
	}
	else
	{
		s2.output();
		cout << "С" << endl;
	}

	if (s1==s2)
	{
		cout << "���" << endl;
	}
	else
	{
		cout << "�����" << endl;
	}
    return 0;
}

