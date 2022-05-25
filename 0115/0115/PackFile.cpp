#include "stdafx.h"
#include "PackFile.h"
#include <iostream>
using namespace std;


PackFile::PackFile(const string & path)
{
	file.open(path);
}

PackFile::~PackFile()
{
}

void PackFile::add(const string & name)
{
	ifstream infile(name, ios::binary);
	if (!infile)
	{
		cout << "文件打开失败\n";
		return ;
	}
	filename[cnt]=name;
	
	infile.seekg(0, ios::end);//定位文件指针
	fileLens[cnt] = infile.tellg();
	size_t pos=name.find("txt");
	if (pos!=string::npos)
	{
		fileLens[cnt] += 1;
	}
	infile.seekg(0, ios::beg);//定位文件指针
	char *tmp=new char[fileLens[cnt]];
	memset(tmp, 0, fileLens[cnt]);
	infile.read(tmp, fileLens[cnt]);
	v[cnt++] = tmp;
	tmp = nullptr;
}

void PackFile::save()
{
	
	for (int i=0;i<cnt;i++)
	{
		int n = filename[i].size()+1;
		file.write((const char *)&n, sizeof(int));
		file.write(filename[i].c_str(), n);
		file.write((const char *)&fileLens[i], sizeof(fileLens[i]));
		file.write(v[i], fileLens[i]);
	}
}
