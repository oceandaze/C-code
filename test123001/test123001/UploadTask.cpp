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
	cout << "�ϴ��ļ�����ʽ������·�� �ϴ���\n";
	cin >> path >> name;
}

void UploadTask::output() const
{
	cout << "��������: �ϴ��ļ�       ����·����"
		<< path << "    �ϴ���:"
		<< name << endl;
}
