#include "stdafx.h"
#include "TaskManagement.h"
#include <iostream>
#include "Task.h"
#include "GetFileList.h"
using namespace std;

TaskManagement::TaskManagement()
{
	strcpy_s(str1, "D:\\");
	strcpy_s(str2, "C:\\");
	strcpy_s(str3, "D:\\");
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
	cout <<"��������: �ļ��б�		·��:" << str1 << endl
		<< "��������: �ϴ��ļ�		����·��:"<<str2<<"		�ϴ��� : ߹߹\n"
		<< "��������: �����ļ�		����·��:"<<str3<<"		���ش��� : 10��\n";
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
	Task *t=nullptr;
	if (m == 1)
	{
		t = new GetFileList;
		App(t);
		strcpy_s(str1, 50, t->str);
	}
	else if (m == 2)
	{
		cout << "������Ҫ�����ļ�����\n";
		cin >> str2;
	}
	else if (m == 3)
	{
		cout << "������Ҫ���ص��ļ�·����\n";
		cin >> str3;
	}
}

void TaskManagement::App(Task * p)
{
	p->show();
}
