#include "stdafx.h"
#include "Dir.h"
#include <iostream>
#include <direct.h>
#include <io.h>
using namespace std;

bool Dir::remove(const char * name)
{
	return :: remove(name) == 0;
}

bool Dir::mkdir(const char * name)
{
	return _mkdir(name) == 0;
}

int Dir::list(const char * name)
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
		if (info.attrib == _A_SUBDIR)	//&р╡©ирт
		{
			if ((strcmp(info.name, ".") != 0) && (strcmp(info.name, "..") != 0))
			{
				int len = strlen(name) + 100;
				char *buffer = new char[len];
				sprintf_s(buffer, len, "%s\\%s", name, info.name);
				cnt=list(buffer);
				delete[] buffer;
			}
		}
		else
		{
			if (strcmp(info.name, ".") == 0
				|| strcmp(info.name, "..") == 0)
			{
				continue;
			}

			cout << info.name << endl;
			++cnt;
		}
		
	} while (_findnext(ret, &info) == 0);
	_findclose(ret);

	return cnt;
}
