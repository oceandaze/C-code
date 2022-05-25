#include "stdafx.h"
#include "GetFileList.h"
#include <iostream>
using namespace std;

GetFileList::GetFileList()
{
}


GetFileList::~GetFileList()
{
}

void GetFileList::show()
{
	cout << "输入要获取文件列表的目录：\n";
	cin >> str;
}
