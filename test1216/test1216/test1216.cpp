// test1216.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "String.h"
#include <iostream>
#include "Vector.h"
using namespace std;
char* sum(char* a ,char* b)
{
	int len = strlen(a) + strlen(b) + 1;
	char* sum =new char[len];
	strcpy_s(sum, len, a);
	strcat_s(sum, len, b);
	return sum;
	delete sum;
}
int main1()
{
	String s1("123");
	s1.cat(nullptr);
	s1.output();

	cout << "���ȣ�" << s1.size() << endl;
	cout << "Ϊ�գ�" 
		<< boolalpha
		<< s1.empty() << endl;
	String s2("ABCDEFG");
	cout << "s1.equal(s2)="
		<< boolalpha
		<< s1.equal(s2) << endl;
	s2.substr(1, 40000)
		.output();
    return 0;
}

int main()
{
	int a[] = {1,2,3,4,5};
	Vector v1(a,5);
	
	v1.push_back(6);
	v1.push_back(0);
	cout << "v1Ԫ�ظ�����" << v1.size() << endl;
	cout << "v1��"<<-1<<"��Ԫ�أ�" << v1.at(-1) << endl;
	cout <<"v1��һ��Ԫ�أ�"<< v1.front() << endl;
	cout << "v1���һ��Ԫ�أ�" << v1.back() << endl;
	cout << "v1Ϊ�գ�" <<boolalpha<< v1.empty() << endl;
 	Vector v2;
 	v2.push_back(1);
 	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(4);
	v2.push_back(5);
	v2.push_back(6);
	v2.push_back(0);
	cout << "v2.equal(v1):" << v2.equal(v1)<< endl;
	v1.erase(1);
	v1.output();
	cout << "v1Ԫ�ظ�����" << v1.size() << endl;

	Vector v3;
	v3.push_back(10);
	v3.push_back(12);
	v3.output();
	v3.update(0, 9);
	v3.output();
	cout<<"v3.at(1)="<<v3.at(1);

	return 0;
}
