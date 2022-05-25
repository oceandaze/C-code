#include "stdafx.h"
#include "App.h"
#include <regex>
#include <iostream>
#include "FileType.h"
#include "TxtFile.h"
#include "CsvFile.h"
#include "HtmlFile.h"
struct CmpByValue
{
	bool operator()(const PAIR &a, const PAIR &b) {
		return a.second.second > b.second.second;
	}

};
App::App(const string &path)
{
	map<string, pair<int, int>> m;
	file.open(path);
	if (!file.is_open())
	{
		return;
	}
	string line;
	getline(file, line);
	smatch math;
	string::const_iterator iter = line.cbegin();
	while (regex_search(iter, line.cend(), math, regex("(3DBNZU|3aaHsb)\">(\\S+)</.*?11uzll\">(\\d+)</.*?11uzll\">(\\d+)</")))
	{
		iter = math[0].second;
		m[math[2]] = make_pair(stoi(math[3]), stoi(math[4]));
	}
	copy(m.begin(), m.end(), back_inserter(v));
	sort(v.begin(),v.end(),CmpByValue());
}


App::~App()
{
}

void App::output() const
{
	for (auto i:v)
	{
		cout << "地区：" << i.first << "	";
		cout << "新增本土：" << i.second.first << "	";
		cout << "现有病例：" << i.second.second << endl;
		cout << "---------------------------\n";
	}
}

void App::save()
{
	cout << "请输入要保存的文件类型：1、txt  2、csv  3、html" << endl;
	int input;
	FileType *p = nullptr;
	while (1)
	{
		cin >> input;
		if (input == 1)
		{
			p = new TxtFile;
			break;
		}
		else if (input == 2)
		{
			p = new CsvFile;
			break;
		}
		else if (input == 3)
		{
			p = new HtmlFile;
			break;
		}
		else
		{
			cout << "输入有误，请重新输入" << endl;
		}
	}
	p->write(v);
	delete p;
	
}
