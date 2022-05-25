#include "stdafx.h"
#include "DownloadTask.h"
#include <iostream>
using namespace std;

DownloadTask::DownloadTask()
{
}


DownloadTask::~DownloadTask()
{
}

void DownloadTask::input()
{
	cout << "下载文件,格式：下载路径 下载次数\n";
	cin >> path >> count;
}

void DownloadTask::output() const
{
	cout << "任务类型: 下载文件       下载路径："
		<< path << "    下载次数:"
		<< count << "次\n";
}
