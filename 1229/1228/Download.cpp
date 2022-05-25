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
	cout << "请输入下载路径和次数" << endl;
	cin >> str >> cnt;
}

void Download::show()
{
	cout << "任务类型: 下载文件		下载路径:" << str << "		下载次数:" << cnt<<"次" << endl;
}
