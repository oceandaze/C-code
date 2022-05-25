#include "stdafx.h"
#include "Dir.h"
#include <direct.h>
#include <io.h>
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;



mutex g_m;

void Dir::find(const vector<string>& path)
{
// 	vector<thread*> threads;
// 	for (const auto &i :path)
// 	{
// 		thread *p = new thread(&Dir::list,this, i, data, 0);
// 		threads.push_back(p);
// 	}
// 	for (thread *p:threads)
// 	{
// 		p->join();
// 		delete p;
// 	}
// 	thread myThreads[10];
// 	for (int i=0;i<path.size();++i)
// 	{
// 		myThreads[i]= thread(list,path[i],data,0);
// 	}
// 	for (int i = 0; i < path.size(); i++) {
// 		myThreads[i].join();
// 	}

// 	for (int i = 0; i < path.size(); ++i)
// 	{
// 		Dir::list(path[i].c_str(),data, 0);
// 	}
}

int Dir::list(const char * name,  vector<vector<string>> &data,int level)
{
	//_findfirst
	//_findnext
	//_findclose
	
	int len = strlen(name) + 3;
	char *buffer = new char[len];
	sprintf_s(buffer, len, "%s\\*", name);

	_finddata_t info;
	intptr_t ret = _findfirst(buffer, &info);
	delete[] buffer;

	if (ret == -1) {
		return 0;
	}
	int cnt = 0;
	do
	{
		if (strcmp(info.name, ".") == 0
			|| strcmp(info.name, "..") == 0)
		{
			continue;
		}

		if (info.attrib & _A_SUBDIR)
		{
			len = strlen(name)
				+ strlen(info.name)
				+ 2;
			buffer = new char[len];
			sprintf_s(buffer, len, "%s\\%s",
				name, info.name);
			cnt += list(buffer, data, level + 1);
			delete[] buffer;
			//cout << "[Ŀ¼]" << info.name << endl;
		}
		else
		{
			vector<string> item;
			item.push_back(info.name);
			item.push_back(to_string(info.size));
			item.push_back(to_string(info.attrib));
			
			//cout << info.name << info.size << endl;
			//cout << item[0] << item[1] << endl;
			lock_guard <mutex> lock(g_m);
			data.push_back(item);
		}

		++cnt;
	} while (_findnext(ret, &info) == 0);
	_findclose(ret);

	return cnt;
}

void Dir::output()
{
	for (int i=0;i<data.size();++i)
	{
		cout << data[i].at(0) << "   "<<data[i].at(1) << endl;
	}	
}
