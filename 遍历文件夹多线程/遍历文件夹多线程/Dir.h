#pragma once
#include <list>
#include "File.h"
#include <vector>
#include <string>
#include <iostream>
#include <mutex>
class Dir
{
public:
	typedef	   list<File> FileList;
	Dir();
	~Dir();
	void find(const vector<string> &path);
	void findThread(string path);
	void getFileList(const string & path, FileList & fileList);
private:
	uint64_t m_nTop;
	FileList m_fileList;
	mutex m_listMutex;

};

