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
	cout << "�ļ��б�, ��ʽ��·��\n";
	cin >> path;
}

void FileListTask::output() const
{
	cout << "��������: �ļ��б�       ·��:"
		<< path << endl;
}
