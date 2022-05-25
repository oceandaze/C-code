#pragma once
#include <string>
#include <vector>
#include <fstream>
using namespace std;
class PackFile
{
public:
	PackFile(const string &path);
	~PackFile();

	void add(const string &filename);
	void save();

private:
	ofstream  file;
	char * v[1024];
	long long fileLens[1024];
	string filename[1024];
	int cnt;
};

