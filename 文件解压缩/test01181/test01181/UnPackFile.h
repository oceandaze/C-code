#pragma once
#include <string>
#include <fstream>
using namespace std;

class UnPackFile
{
public:
	UnPackFile(const string &fileName);
	~UnPackFile();

	void save(const string &path);
private:
	void read(const string &path, ifstream &file);
private:
	string		m_fileName;
};

