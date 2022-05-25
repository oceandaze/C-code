#include "stdafx.h"
#include "File.h"
#include <iostream>

using namespace std;
File::File(const char *n)
{
	errno_t err;
	err = fopen_s(&p, "1.txt", "w+");
	if (err==0)
	{
		cout << "文件打开成功" << endl;
	}
	else
	{
		cout << "文件打开失败" << endl;
		//exit(0);类中禁用
	}
}

void File::write(const char *c)
{
	//fputs(c, p);
	fwrite(c,1,strlen(c),p);
}


File::~File()
{
	fclose(p);
	cout << "文件关闭成功" << endl;
}
