#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;
class MergeFile
{
public:
	MergeFile(const string str[],int cnt);
	~MergeFile();
	void merge();
private:
	ofstream file;
	vector<string> arr;
};

