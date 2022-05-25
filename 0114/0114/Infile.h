#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;
class Infile
{
public:
	Infile(const string &path);
	~Infile();

	void split(const string &str, const string &sp);
	void output() const;
private:
	ifstream file;
	vector<string> arr[1024];
	int cnt;
};

