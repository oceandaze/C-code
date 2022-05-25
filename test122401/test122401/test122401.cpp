// test122401.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "Vector.h"
using namespace std;

int main1()
{
	Vector v1;
	v1.push_back(111);
	v1.push_back(1);
	v1.push_back(4);
	v1.push_back(99);

	cout << v1 << endl;
	v1[0] = 888;
	cout << "v1.front()=" << v1.front() << endl;
	cout << "v1.back()=" << v1.back() << endl;

	Vector v2;
	v2.push_back(888);
	v2.push_back(1);
	v2.push_back(4);
	v2.push_back(99);
// 	v2 += v1;
// 	cout << "v2 += v1=>" << v2 << endl;
	cout << "v1 + v2=>" << v1 + v2 << endl;
	cout << "v1 == v2=>" << (v1 == v2) << endl;

	cin >> v2;
	cout << "v2=" << v2 << endl;
    return 0;
}



class A
{
public:
	A(int a ){
		this->a = a;
	}
	void output(){
		cout << a << endl;
	}
	A &operator++() {
		++a;
		return *this;
	}

	A operator++(int) {
		A temp = *this;
		++a;
		return temp;
	}

	A &operator--() {
		--a;
		return *this;
	}

	A operator--(int) {
		A temp = *this;
		--a;
		return temp;
	}
private:
	int a;
};

int main()
{
	A a1(1);
	A  a2 = a1++;
	a1.output();
	a2.output();
	--a1;
	a1.output();
	a2++;
	a2.output();
	return 0;
}