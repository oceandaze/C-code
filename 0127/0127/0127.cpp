// 0127.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <map>
#include <vector>
#include "App.h"
using namespace std;


int main1()
{
	ifstream file("11.log");
	string line;
	while (getline(file,line))
	{
		string name;
		string time;
		smatch math;
		if (regex_search(line,math,regex("(\\d+-\\d+-\\d+)\\s(\\d+:\\d+:\\d+\\.\\d+).*=(\\w+)")))
		{
			cout << "���ڣ�" << math[1] << endl;
			cout << "ʱ�䣺" << math[2] << endl;
			cout << "�û�����" << math[3] << endl;
			cout << "---------------------------\n";
		}
	}
    return 0;
}

typedef pair<string, pair<int, int>> PAIR;
struct CmpByValue
{
	bool operator()(const PAIR &a,const PAIR &b) {
		return a.second.second > b.second.second;
	}
	
};
int main2()
{
	map<string, pair<int, int>> m;
	ifstream file("new.txt");
	string line;
	getline(file, line);
	smatch math;
 	string::const_iterator iter = line.cbegin();
	while (regex_search(iter,line.cend(),math,regex("(3DBNZU|3aaHsb)\">(\\S+)</.*?11uzll\">(\\d+)</.*?11uzll\">(\\d+)</")))
	{
		iter = math[0].second;
		m[math[2]] = make_pair(stoi(math[3]), stoi(math[4]));		
	}
	vector<PAIR> v(m.begin(),m.end());
	sort(v.begin(), v.end(), CmpByValue());
	for (auto i : v)
	{
		cout << "������" << i.first << "	";
		cout << "����������" << i.second.first << "	";
		cout << "���в�����" << i.second.second << endl;
		cout << "---------------------------\n";
	}

	return 0;
}


int main()
{
	App app("new.txt");
	//app.output();
	app.save();
	return 0;
}