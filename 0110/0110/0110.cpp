// 0110.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <xfunctional>
using namespace std;

int main()
{
	string s1 = "123456";
	if (s1=="123456")
	{
		cout << "���" << endl;
	}
	if (s1!="1234567")
	{
		cout<< "�����" << endl;
	}

	if (strcmp(s1.c_str(), "1234")==0)
	{
		cout << "���" << endl;
	}
	else
	{
		cout << "�����" << endl;
	}
	s1.clear();
	cout << "s1.size()=" << s1.size() << endl;
	s1="";
	cout << "s1.size()=" << s1.size() << endl;
	
	s1 = "123456";
	auto iter = find(s1.begin(),s1.end(),'2');
	if (iter!=s1.end())
	{
		cout << "�ҵ�" << *iter << endl;
	}

	iter = find_if(s1.begin(), s1.end(), [](char c) {
		return c > '0'&&c < '9';
	});
	if (iter!=s1.end())
	{
		cout << "�ҵ�" << *iter << endl;
	}
	string s2 = "521shhG23546";
	sort(s2.begin(), s2.end());
	sort(s2.begin(), s2.end(),less<char>());
	sort(s2.begin(), s2.end(), greater<char>());
	sort(s2.begin(), s2.end(), [](const char a, const char b) {
		return a < b;
	});
	for (auto i:s2)
	{
		cout << i << " ";
	}
	cout <<  "\n";

	cout << *max_element(s2.begin(), s2.end()) << endl;
	cout << *min_element(s2.begin(), s2.end()) << endl;
    return 0;
}

