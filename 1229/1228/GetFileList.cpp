#include "stdafx.h"
#include "GetFileList.h"


GetFileList::GetFileList()
{
}


GetFileList::~GetFileList()
{
}

void GetFileList::info()
{
	cout << "输入要获取文件列表的目录：\n";
	cin >> str;
}

void GetFileList::show()
{
	cout << "任务类型: 文件列表		路径:" << str << endl;
}
