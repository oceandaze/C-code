#include "stdafx.h"
#include "Upload.h"


Upload::Upload()
{
}


Upload::~Upload()
{
}

void Upload::info()
{
	cout << "�����뱣��·��������" << endl;
	cin >> str >> uploader;
}

void Upload::show()
{
	cout << "��������: �ϴ��ļ�		����·��:" << str << "		�ϴ���:" << uploader<< endl;
	 		
}
