#include "stdafx.h"
#include "Download.h"


Download::Download()
{
}

Download::~Download()
{
}

void Download::info()
{
	cout << "����������·���ʹ���" << endl;
	cin >> str >> cnt;
}

void Download::show()
{
	cout << "��������: �����ļ�		����·��:" << str << "		���ش���:" << cnt<<"��" << endl;
}
