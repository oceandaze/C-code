// test1217.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Vector.h"
#include <iostream>
#include <vector>
#include<string>
#include <algorithm>
#include "Set.h"
#include "Stack.h"
using namespace std;
int main1()
{
	int p[] = { 1,23,4,6 };
	Vector v1(p, 4);
	v1.output();

	Vector v2 = v1;
	v2.output();
	cout << "v2.size()=" << v2.size() << endl;
    
	v2.push_back(76);
	v2.push_back(54);
	v2.push_back(666);
	

	cout << "v2.at(2)=" << v2.at(2) << endl;
	cout << "v2.front()=" << v2.front() << endl;
	cout << "v2.back()=" << v2.back() << endl;
	cout << "v2.empty()="
		<< boolalpha << v2.empty() << endl;

	cout << "v2.equal()="
		<< boolalpha 
		<< v1.equal(v2) << endl;
	v2.output();
	v2.erase(1000);
	v2.output();

	return 0;
}

int main2()
{
	int a[] = { 2,1,5,4,4,4,6 };
	Set s1(a, 5);
	s1.output();
	s1.insert(2);
	s1.insert(3);
	s1.output();
	cout << "s1.count()=" << s1.count(4) << endl;;
	s1.find(5);

	s1.clear();
	s1.insert(3);
	s1.insert(4);
	s1.insert(6);
	s1.insert(4);
	s1.output();

	cout << "s1.empty() ="<<boolalpha << s1.empty() << endl;
	cout << "s1.size() ="<< s1.size() << endl;
	s1.erase(3);
	cout << "s1.size() =" << s1.size() << endl;
	cout << "s1.count()=" << s1.count(4) << endl;;
	
	s1.output();

	Set s2 = s1;
	s2.output();

// 	string ss("53a21");
// 	sort(ss.rbegin(),ss.rend());
// 	ss += "abc";
// 	cout << ss << endl;
	return 0;
}

int main()
{
	Stack s1;
	s1.push(2);
	s1.push(3);
	s1.push(1);
	s1.push(4);
	s1.pop();
	cout << "s1.top()="<<s1.top() << endl;
	cout <<"s1.empty()=" <<boolalpha<<s1.empty() << endl;
	cout << "s1.size()=" <<  s1.size() << endl;
	cout << "栈中元素打印" << endl;
	s1.output();
	return 0;
}