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
	cout << "����Ҫ��ȡ�ļ��б��Ŀ¼��\n";
	cin >> str;
}

void GetFileList::show()
{
	cout << "��������: �ļ��б�		·��:" << str << endl;
}
