#include "stdafx.h"
#include "File.h"
#include <iostream>

using namespace std;
File::File(const char *n)
{
	errno_t err;
	err = fopen_s(&p, "1.txt", "w+");
	if (err==0)
	{
		cout << "�ļ��򿪳ɹ�" << endl;
	}
	else
	{
		cout << "�ļ���ʧ��" << endl;
		//exit(0);���н���
	}
}

void File::write(const char *c)
{
	//fputs(c, p);
	fwrite(c,1,strlen(c),p);
}


File::~File()
{
	fclose(p);
	cout << "�ļ��رճɹ�" << endl;
}
