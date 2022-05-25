#include "stdafx.h"
#include "UploadTask.h"

#include <iostream>
using namespace std;

UploadTask::UploadTask()
{
}


UploadTask::~UploadTask()
{
}

void UploadTask::input()
{
	cout << "上传文件，格式：保存路径 上传者\n";
	cin >> path >> name;
}

void UploadTask::output() const
{
	cout << "任务类型: 上传文件       保存路径："
		<< path << "    上传者:"
		<< name << endl;
}
