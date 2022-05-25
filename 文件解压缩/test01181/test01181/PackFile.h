#pragma once
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class PackFile
{
public:
	PackFile(const string &fileName);
	~PackFile();

	void add(const string &filePath);
	void save();
private:
	string getFileName(const string &filePath) const;
	void write(const string &filePath, ofstream &file);
private:
	string			m_fileName;
	vector<string>	m_fileList;
};

