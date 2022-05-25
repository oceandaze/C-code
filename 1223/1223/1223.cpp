// 1223.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "Vector.h"
#include "String.h"
#include "Student.h"
using namespace std;

class A
{
public:
	friend ostream &operator<<(ostream &out ,const A & a1);
	friend istream &operator>>(istream &in,  A & a1);
	A(int a)
	{
		this->a = a;
	}
private:
	int a;
};

ostream &operator<<(ostream &out, const A & a1)
{
	out << a1.a;
	return out;
}
istream &operator>>(istream &in, A & a1)
{
	in >> a1.a;
	return in;
}

/*
5、实现一个Vector类，可以保存多个int类型数据，要求如下：
1) 无参构造函数、有参数构造Vector(const int* p, int cnt);
2)size()   可以获得数组中元素的个数
3)push_back(int v);  可以将v保存到数组中
4)实现 + 、 += 运算符，可以完成两个数组合并
5）输出 << 运算符重载
6）输入 >> 运算符重载
7)empty()  可以获得数组是否为空
8） == 相等运算符重载
9）[]下标访问运算符重载
10) front() 获取第一个元素
11）back获取最后一个元素*/

int main1()
{
	int arr[] = { 2,3,1,4,2,5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	Vector v1(arr,n);
	Vector v2;
	v2.push_bach(8);
	v2.push_bach(9);
	v1 += v2;
// 	cin >> v1;
// 	cout << v1 << endl;;
	Vector v3 = v1 + v2;
	v3.print();

	cout <<"(v1 == v1):"<< boolalpha << (v1 == v1) << endl;
	v1.print();
	v2.print();
	cout << "(v1 != v2):"<<boolalpha << (v1 != v2) << endl;
	v3[1] = 3;
	cout <<"v3[]=" << v3[-1] << endl;
	cout << "v3.front()=" << v3.front() << endl;
	cout << "v3.back()=" << v3.back() << endl;

	Vector v4;
	v4 = v1;
	cout << "v4=" << v4 << endl;
	return 0;
}

void sort(Student*stu, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (stu[j] > stu[j + 1])
			{
				Student temp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = temp;
			}
		}
	}
}
int main()
{
	int n = 0;
	cout << "请输入学生人数" << endl;
	cin >> n;
	Student *stu = new Student[n];
	char name[32] = { 0 };
	int age = 0;
	for (int i = 0; i < n; i++)
	{
		cout << "请输入学生" << i + 1 << "的信息" << endl;
		cin >> name >> age;
		stu[i].input(name, age);
	}
	sort(stu, n);
	for (int i = 0; i < n; i++)
	{
		stu[i].output();
	}

	cout <<"stu[1] == stu[2]"<< boolalpha << (stu[1] == stu[2]) << endl;
	cout << "stu[1] != stu[2]" << boolalpha << (stu[1] != stu[2]) << endl;
	delete[] stu;
	return 0;
	
/*
	张三 2
	李四 3
	李四 3
	*/

}

int main3()
{
	String s1("1234");

	String s2 = s1;

	cout <<"(s1 == s2)"<< boolalpha << (s1 == s2) << endl;
	cout << "(s1 != s2)" << boolalpha << (s1 != s2) << endl;
	return 0;
}

