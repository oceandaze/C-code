#include "stdafx.h"
#include "TaskManagement.h"
#include <iostream>
#include "Task.h"
#include "GetFileList.h"
#include "Upload.h"
#include "Download.h"
using namespace std;

TaskManagement::TaskManagement()
{
	index = 0;
}


TaskManagement::~TaskManagement()
{
}

void TaskManagement::menu()
{
	cout << "------------------" << endl;
	cout << "1、添加任务 2、显示所有任务 3、退出系统" << endl;
	cout << "------------------" << endl;
}

void TaskManagement::taskList()
{
// 	cout <<"任务类型: 文件列表		路径:" << str1 << endl
// 		<< "任务类型: 上传文件		保存路径:"<<str2<<"		上传者 : 吖吖\n"
// 		<< "任务类型: 下载文件		下载路径:"<<str3<<"		下载次数 : 10次\n";
	for (int i=0;i<index;++i)
	{
		job[i]->show();
	}


}
// void TaskManagement::addTask()
// {
// 	cout << "选择要添加任务类型\n"
// 		<< "1、获取文件列表\t2、上传文件\t3、下载文件" << endl;
// 	int m=0;
// 	cin >> m;
// 	if (m == 1)
// 	{
// 		cout << "输入要获取文件列表的目录：\n";
// 		cin >> str1;
// 	}
// 	else if (m==2)
// 	{
// 		cout << "输入需要保存文件名：\n";
// 		cin >> str2;
// 	}
// 	else if (m == 3)
// 	{
// 		cout << "输入需要下载的文件路径：\n";
// 		cin >> str3;
// 	}
// }

void TaskManagement::addTask()
{
	cout << "选择要添加任务类型\n"
		<< "1、获取文件列表\t2、上传文件\t3、下载文件" << endl;
	int m = 0;
	cin >> m;
	//Task * t= nullptr;
	if (m == 1)
	{
		job[index] = new GetFileList;
		job[index++]->info();
	}
	else if (m == 2)
	{												  
		job[index] = new Upload;
		job[index++]->info();
	}
	else if (m == 3)
	{
		job[index] = new Download;
		job[index++]->info();
	}
}


