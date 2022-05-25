#pragma once
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class UnPackFile
{
public:
	UnPackFile(const string &path);
	~UnPackFile();
	void save(const string &path);
private:
	ifstream file;
	char * v[1024];
	long long fileLens[1024];
	string filename[1024];
	int cnt;
};

