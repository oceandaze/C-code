#pragma once
#include <string>
#include <vector>
using namespace std;

class Sql
{
public:
	Sql();
	~Sql();

	void build(const string &fileName);

private:
	string getFilename(const string &fileName) const;
	void split(const string &str, vector<string> &arr);
};

