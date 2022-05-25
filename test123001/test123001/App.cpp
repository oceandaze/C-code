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
		cout << "1���������      2����ʾ��������     3���˳�ϵͳ"
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
	cout << "1���ļ��б�	 2���ϴ��ļ�	 3�������ļ�\n:";
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
