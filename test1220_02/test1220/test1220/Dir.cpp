#include "stdafx.h"
#include "Dir.h"
#include <iostream>
#include <direct.h>
#include <io.h>
using namespace std;

bool Dir::remove(const char * name)
{
	return ::remove(name) == 0;
}

bool Dir::mkdir(const char * name)
{
	return _mkdir(name) == 0;
}

int Dir::list(const char * name, int level)
{
	//_findfirst
	//_findnext
	//_findclose
	if (level == 0) {
		printf("----------------------------------------------------------------------------------------------\n");
		printf("|%-70s|%10s|%10s|\n", "文件名", "大小", "属性");
		printf("----------------------------------------------------------------------------------------------\n");
	}
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
			cnt += list(buffer, level + 1);
			delete[] buffer;
			//cout << "[目录]" << info.name << endl;
		}
		else 
		{
			printf("|%-70s|%10s|%10s|\n", 
				getPath(name, info.name),
				toBigUnit(info.size),
				getAttribName(info.attrib));
			printf("----------------------------------------------------------------------------------------------\n");
		}
		
		++cnt;
	} while (_findnext(ret, &info) == 0);
	_findclose(ret);

	return cnt;
}

const char * Dir::toBigUnit(double val)
{
	static char *unit[] = { "B", "KB", "MB", "GB" };
	int index = 0;
	while (val > 800) {
		val /= 1024.0;
		++index;
	}
	static char buffer[64];
	sprintf_s(buffer, sizeof(buffer),
		"%.2f%s", val, unit[index]);
	return buffer;
}

const char * Dir::getPath(const char * path, const char * name)
{
	static char buffer[512];
	int Len = strlen(path) + strlen(name);
	if (Len>69)
	{
		int len = Len+5;
		char * newpath = new char[len];
		if (strlen(name) >70)
		{
			sprintf_s(buffer, sizeof(buffer), "...%s", name+3);
		}
		else 
		{
			int l1 = Len - 70;
			sprintf_s(newpath, len, "...%s", path+l1+4);
			sprintf_s(buffer, sizeof(buffer), "%s\\%s", newpath, name);
		}	
	}
	else
	{
		sprintf_s(buffer, sizeof(buffer), "%s\\%s", path, name);
	}
	return buffer;
}

const char *Dir::getAttribName(unsigned attrib)
{
	switch (attrib)
	{
	case 0x00:
		return 	  "Normal file";
		break;
	case 0x01:
		return 	  "Read only file";
		break;
	case 0x02:
		return 	  "Hidden file";
		break;
	case 0x04:
		return 	  "System file";
		break;
	case 0x10:
		return 	 "Subdirectory";
		break;
	case 0x20:
		return 	"Archive file";
		break;

	default:
		break;
	}
}
