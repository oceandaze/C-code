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
	cout << "�����ļ�,��ʽ������·�� ���ش���\n";
	cin >> path >> count;
}

void DownloadTask::output() const
{
	cout << "��������: �����ļ�       ����·����"
		<< path << "    ���ش���:"
		<< count << "��\n";
}
