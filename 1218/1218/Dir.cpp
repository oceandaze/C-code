#include "stdafx.h"
#include "Dir.h"
#include <io.h>
#include <iostream>
#include <direct.h>
#include <windows.h>


using namespace std;

Dir::Dir()
{
}


Dir::~Dir()
{
}

bool Dir::remove(const char  * name)
{
	return DeleteFile(name);
}

bool Dir::mkdir(const char* name)
{
	return _mkdir(name);
}

int Dir::list(const char * path)
{
	struct _finddata_t fileinfo;
	int fileNum = 0;
	long handle = _findfirst(path, &fileinfo);
	if (handle == -1)
	{
		return 0;
	}
	do 
	{
		
		fileNum++;
		cout << fileinfo.name << endl;
		
		
	} while (!_findnext(handle, &fileinfo));
	
	_findclose(handle);
	return fileNum;
}




