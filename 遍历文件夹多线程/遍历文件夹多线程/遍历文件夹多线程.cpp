// 遍历文件夹多线程.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Dir.h"

//  1、使用多线程，分别遍历多个目录获取文件列表，将汇总后的列表按文件大小降序排序，打印前10个文件。
// class Dir
// {
// public:
// void find(const vector<string> &path);
// };
int main()
{
	Dir dir;
	dir.find({"D:","F:" });
    return 0;
}

