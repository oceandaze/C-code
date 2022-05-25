// 0120.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <map>
#include <string>
#include <iostream>
#include "ipQuery.h"
using namespace std;

void output(map<int, string> &m1)
{
	for (auto i : m1)
	{
		cout << i.first << "=" << i.second << endl;
	}
}
int main1()
{
	map<int,string> m1;
	m1[1006] = "小明";
	m1[1001] = "小黑";
	m1[1003] = "小白";
	m1[1003] = "小白1";

	m1.insert(make_pair(1000, "小李"));
	m1.insert(make_pair(1000, "小李1"));
	output(m1);
	m1.erase(1006);
	output(m1);
// 	cout << m1.size() << endl;
// 	for (auto iter =m1.begin();iter!=m1.end();++iter)
// 	{
// 		cout << iter->first << "->" << iter->second << endl;
// 	}
// 	cout << "---------------------------" << endl;
	
// 	cout << m1[1003] << endl;
// 	auto iter = m1.find(1009);
// 	if (iter!=m1.end())
// 	{
// 		cout << iter->first << "的值为：" << iter->second << endl;
// 
// 	}
// 	else
// 	{
// 		cout << "key不存在\n";
// 	}

    return 0;
}

int main2()
{
// 	string s = "1.1.12.2=http://www.xxx1.com";
// 	string key = s.substr(0, s.find("="));
// 	string val = s.substr(s.find("=") + 1);
// 	cout << key <<"\t"<< val<<endl;
	ipQuery q1("1.txt");
	q1.inquire("10.1.12.2");
	q1.inquire("192.129.01.02");
	return 0;
}



int main()
{

	int votercnt;
	while (cin >> votercnt) {
		map<string, int> m;
		string key;
		for (int i = 0; i < votercnt; ++i) {
			cin >> key;
			m[key] = 0;
		}
		int candicnt;
		cin >> candicnt;
		int Invalid = 0;
		for (int i = 0; i < candicnt; ++i) {
			cin >> key;
			auto iter = m.find(key);
			if (iter != m.end()) {
				iter->second += 1;
			}
			else {
				Invalid++;
			}
		}
		for (auto i : m) {
			cout << i.first << " : " << i.second << endl;
		}
		cout << "Invalid : " << Invalid << endl;
	}

	return 0;
}