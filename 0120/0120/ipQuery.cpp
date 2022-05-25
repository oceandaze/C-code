#include "stdafx.h"
#include "ipQuery.h"
#include <fstream>
#include <iostream>



ipQuery::ipQuery(const string & filename)
{
	ifstream infile(filename);
	string s;
	while (infile>>s)
	{
		string key = s.substr(0, s.find("="));
		string val = s.substr(s.find("=") + 1);
		m[key] = val;
	}
}

void ipQuery::inquire(const string & s)
{
	auto iter = m.find(s);
	if (iter != m.end())
	{
		cout << iter->first << "对应的域名：" << iter->second << endl;

	}
	else
	{
		cout << "ip不存在\n";
	}
}
