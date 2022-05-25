#pragma once
#include <map>
#include <string>
using namespace std;
class ipQuery
{
public:
	ipQuery(const string &filename);

	void  inquire(const string &s);
private:
	map<string, string> m;
};

