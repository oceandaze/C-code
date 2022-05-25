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
	cout << "1��������� 2����ʾ�������� 3���˳�ϵͳ" << endl;
	cout << "------------------" << endl;
}

void TaskManagement::taskList()
{
// 	cout <<"��������: �ļ��б�		·��:" << str1 << endl
// 		<< "��������: �ϴ��ļ�		����·��:"<<str2<<"		�ϴ��� : ߹߹\n"
// 		<< "��������: �����ļ�		����·��:"<<str3<<"		���ش��� : 10��\n";
	for (int i=0;i<index;++i)
	{
		job[i]->show();
	}


}
// void TaskManagement::addTask()
// {
// 	cout << "ѡ��Ҫ�����������\n"
// 		<< "1����ȡ�ļ��б�\t2���ϴ��ļ�\t3�������ļ�" << endl;
// 	int m=0;
// 	cin >> m;
// 	if (m == 1)
// 	{
// 		cout << "����Ҫ��ȡ�ļ��б��Ŀ¼��\n";
// 		cin >> str1;
// 	}
// 	else if (m==2)
// 	{
// 		cout << "������Ҫ�����ļ�����\n";
// 		cin >> str2;
// 	}
// 	else if (m == 3)
// 	{
// 		cout << "������Ҫ���ص��ļ�·����\n";
// 		cin >> str3;
// 	}
// }

void TaskManagement::addTask()
{
	cout << "ѡ��Ҫ�����������\n"
		<< "1����ȡ�ļ��б�\t2���ϴ��ļ�\t3�������ļ�" << endl;
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


