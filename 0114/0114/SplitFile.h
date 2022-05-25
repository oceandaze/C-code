#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;
class SplitFile
{
public:
	SplitFile(const string &path);
	~SplitFile();

	void split(int num);
private:
	ifstream file;
	vector<string> arr;
};

