#include "stdafx.h"
#include "UnPackFile.h"
#include <iostream>
using namespace std;


UnPackFile::UnPackFile(const string & path)
{
	file.open(path,ios::binary);
	file.seekg(0, ios::beg);
	cnt = 0;
	while (!file.eof())
	{
		int nFilename = 0;
		file.read((char*)&nFilename, sizeof(int));
		char *name = new char[nFilename];
		memset(name, 0, nFilename);
		file.read(name, nFilename);
		filename[cnt] = name;
		delete[]name;
		file.read((char*)&fileLens[cnt], sizeof(long long));
		char *tmp = new char[fileLens[cnt]];
		memset(tmp, 0, fileLens[cnt]);
		file.read(tmp, fileLens[cnt]);
		v[cnt++]=tmp;
		tmp = nullptr;
	} 
}

UnPackFile::~UnPackFile()
{
}

void UnPackFile::save(const string & path)
{
	for (int i = 0; i < cnt; ++i)
	{
		string filepath = path + "\\"+filename[i];
		ofstream ofile(filepath);
		ofile.write(v[i], fileLens[i]);
	}
	ofstream outfile();
}
