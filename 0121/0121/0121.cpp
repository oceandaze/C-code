// 0121.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>

#include <string>
#include <iostream>
using namespace std;
using namespace stdext;
int main1()
{
	set<int> s1;
	s1.insert(200);
	s1.insert(200);
	s1.insert(100);
	s1.insert(500);
	cout << "" << s1.size() << endl;
	cout << "" << s1.empty() << endl;
	for (auto iter=s1.begin();iter!=s1.end();++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;
	for (auto i:s1)
	{
		cout << i << " ";
	}
	cout << endl;

	auto iter = s1.find(600);
	if (iter!=s1.end())
	{
		cout << *iter << "存在\n";
	}
	else {
		cout << "不存在" << endl;
	}
    return 0;
}

/*需求：输入一行字符串，统计其中使用了多少种字符。*/

int main2()
{
	string s = "acaw,,;";
	cin >> s;
	set<char> s1;
	for (size_t i=0;i<s.size();++i)
	{
		s1.insert(s[i]);
	}
	cout << "共使用了" << s1.size() << "种字符" << endl;
	return 0;
}

int main3()
{
	multimap<string,int> m1;
	m1.insert(make_pair("xiaoming",110));
	m1.insert(make_pair("xiaoming", 119));
	m1.insert(make_pair("xiaoming", 120));
	m1.insert(make_pair("小亮", 123));
	m1.insert(make_pair("小亮", 456));
	cout << m1.size() << endl;
	cout << "删除前\n";
	for (auto i : m1)
	{
		cout << i.first << i.second << endl;
	}
	for (auto iter = m1.begin(); iter != m1.end(); ++iter)
	{
		if (iter->first == "xiaoming"&&iter->second == 119)
		{
			m1.erase(iter);
			break;
		}
	}
	cout << "删除后\n";
	for (auto i : m1)
	{
		cout << i.first << i.second << endl;
	}

	return 0;
}
int main4()
{
	unordered_map<string, int> m1;
	m1.insert(make_pair("xiaoming", 110));
	m1.insert(make_pair("xiaoming", 119));
	m1.insert(make_pair("xiaoming", 120));
	m1.insert(make_pair("小亮", 123));
	m1.insert(make_pair("小亮", 456));
	cout << m1.size() << endl;
	for (auto i : m1)
	{
		cout << i.first << i.second << endl;
	}
	
	return 0;
}


int main5()
{
	multiset<int> m1;
	m1.insert(1);
	m1.insert(1);
	m1.insert(2);
	m1.insert(1);
	m1.insert(2);
	m1.insert(3);
	cout << m1.size() << endl;
	for (auto iter=m1.begin();iter!=m1.end();++iter)
	{
		cout << *iter << endl;
	}
	return 0;
}

int main()
{
	unordered_set<int> m1;
	m1.insert(1);
	m1.insert(1);
	m1.insert(2);
	m1.insert(1);
	m1.insert(2);
	m1.insert(3);
	cout << m1.size() << endl;
	for (auto iter = m1.begin(); iter != m1.end(); ++iter)
	{
		cout << *iter << endl;
	}
	return 0;
}