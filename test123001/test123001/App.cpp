#include "stdafx.h"
#include "App.h"
#include <iostream>
#include "FileListTask.h"
#include "UploadTask.h"
#include "DownloadTask.h"
using namespace std;

App::App()
{
	pos = 0;
}


App::~App()
{
}

void App::run()
{
	while (true) 
	{
		cout << "1、添加任务      2、显示所有任务     3、退出系统"
			<< "\n:";
		int n;
		cin >> n;
		if (n == 1) {
			add();
		}
		else if (n == 2) {
			show();
		}
		else if (n == 3) {
			break;
		}
	}
}

void App::add()
{
	cout << "1、文件列表	 2、上传文件	 3、下载文件\n:";
	int n;
	cin >> n;
	Task *pTask = createTask(n);
	if (pTask != nullptr) {
		pTask->input();
		taskList[pos++] = pTask;
	}
}

void App::show()
{
	for (int i = 0; i < pos; ++i) {
		taskList[i]->output();
	}
}

Task * App::createTask(int n) const
{
	if (n == 1) return new FileListTask;
	else if (n == 2) return new UploadTask;
	else if (n == 3) return new DownloadTask;
	return nullptr;
}
