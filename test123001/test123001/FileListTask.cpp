#include "stdafx.h"
#include "FileListTask.h"
#include <iostream>
using namespace std;

FileListTask::FileListTask()
{

}


FileListTask::~FileListTask()
{

}

void FileListTask::input()
{
	cout << "文件列表, 格式：路径\n";
	cin >> path;
}

void FileListTask::output() const
{
	cout << "任务类型: 文件列表       路径:"
		<< path << endl;
}
