// 0104.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "Vector.h"
#include "Stack.h"
#include "Queue.h"
using namespace std;
/*
1、实现一个Vector模板类，要求如下：
1) 无参构造函数;
2)size()   可以获得数组中元素的个数
3)push_back(T v);  可以将v保存到数组中
4)at(int index); 可以访问指定下标元素
5)front(); 可以访问第一个元素
6)back(); 可以访问最后一个元素
7)empty()  可以获得数组是否为空
8)equal 相等判断
9)output输出所有元素
10)erase(int index); 删除指定下标元素
11）下标运算符重载
内部用指针来动态管理内存*/

/*
2、实现一个Stack类模板，栈（先进后出的数据结构），实现以下功能：
1)、top() 获取栈顶元素
2）、push()栈顶保存元素
3）、pop()删除栈顶元素
4）、empty()判断栈是否为空
5）、size()获取元素个数
内部可以使用数组来存储数据

3、实现一个Queue类模板，队列（先进先出的数据结构），实现以下功能：
1）、font() 获取头部元素
2）、back() 获取尾部元素
3）、push()尾部保存元素
4）、pop()删除头部元素
5）、empty()判断队列是否为空
6）、size()获取元素个数
内部可以使用数组来存储数据*/


class student
{

private:
	char name[32];
};
int main1()
{
	int arr[] = { 2,1,3 };
	Vector<int> v1(arr, 3);
	v1.push_back(3);
	v1.output();

	double arr2[] = { 2.1,1.1,3.3 };
	Vector<double>	v2(arr2,3);
	v2.push_back(5.5);
	v2.output();

	Vector<student> v3;
	v3.at(0);

    return 0;
}

int main2()
{
	Stack<int> s1;
	s1.push(2);
	s1.push(3);

	cout << "s1.top()=" << s1.top() << endl;
	cout << "s1.size()=" << s1.size() << endl;
	s1.pop();
	cout << s1.top() << endl;
	cout << "s1.size()=" << s1.size() << endl;
	s1.pop();
	cout << "s1.empty()="<<boolalpha << s1.empty() << endl;

	Stack<double> s2;
	s2.push(2.1);
	s2.push(3.2);
	cout << "s2.top()=" << s2.top() << endl;
	cout << "s2.size()=" << s2.size() << endl;
	return 0;
}

int main()
{
	Queue<int> q1;
	q1.push(2);
	q1.push(4);
	q1.push(6);
	cout<<"q1.font()="<<q1.font()<<endl;
	cout << "q1.back()=" << q1.back() << endl;
	q1.pop();
	q1.popTail();
	cout << "q1.font()=" << q1.font() << endl;
	cout << "q1.back()=" << q1.back() << endl;
	cout << "q1.size()=" << q1.size() << endl;
	cout << "q1.empty()=" << boolalpha << q1.empty() << endl;

	Queue<double> q2;
	q2.push(2.5);
	q2.push(4.2);
	q2.push(6.6);
	q2.push(7.1);
	cout << "q2.font()=" << q2.font() << endl;
	cout << "q2.back()=" << q2.back() << endl;
	q2.pop();
	q2.popTail();
	cout << "q2.font()=" << q2.font() << endl;
	cout << "q2.back()=" << q2.back() << endl;
	return 0;
}																	