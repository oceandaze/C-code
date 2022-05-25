#include "stdafx.h"
#include "Dir.h"
#include <thread>
#include <direct.h>
#include <io.h>

Dir::Dir()
{
	m_nTop = 200;
}


Dir::~Dir()
{
}

void Dir::find(const vector<string>& path)
{
	vector<thread*> threads;
	for (const auto &i : path) 
	{
		thread *p = new thread(&Dir::findThread, this, i);
		threads.push_back(p);
	}

	for (thread *p : threads) {
		p->join();
		delete p;
	}

	m_fileList.sort();

	int index = 0;
	for (const auto &i : m_fileList) {
		cout << i << "\n";

		if (++index > m_nTop) {
			break;
		}
	}
}

void Dir::findThread(string path)
{
	FileList fileList;
	getFileList(path, fileList);

	fileList.sort();

	int index = 0;

	m_listMutex.lock();
	for (const auto &i : fileList) {
		m_fileList.push_back(i);

		if (++index > m_nTop) {
			break;
		}
	}
	m_listMutex.unlock();
}

void Dir::getFileList(const string & path, FileList & fileList)
{
	string filePath = path;
	filePath += "\\*";

	_finddata_t info;
	intptr_t ret = _findfirst(filePath.c_str(), &info);

	if (ret == -1) {
		return;
	}
	int cnt = 0;
	do
	{
		string name(info.name);
		if (name == "." 
			|| name == "..")
		{
			continue;
		}

		if (info.attrib & _A_SUBDIR)
		{
			getFileList(path + "\\" + name, fileList);
		}
		else
		{
			fileList.push_back(File(path + "\\" + name, info.size));
		}
	} while (_findnext(ret, &info) == 0);
	_findclose(ret);
}
