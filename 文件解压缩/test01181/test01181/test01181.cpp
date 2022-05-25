// test01181.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "PackFile.h"
#include "UnPackFile.h"

int main1()
{	
	string fileName = "123.me";
	PackFile pack(fileName);
// 	pack.add("D:\\vs2015\\010EditorWin64Installer11.0.1.exe");
// 	pack.add("D:\\C++\\01.10.docx");
// 	pack.add("C:\\Users\\Administrator\\Desktop\\111.bmp");
	pack.add("D:\\vs2015\\010EditorWin64Installer11.0.1.exe");
	pack.add("1.txt");
	pack.add("3.jpg");
	pack.save();
    return 0;
}

int main()
{
	string fileName = "123.me";
	UnPackFile pack(fileName);
	pack.save("D:\\test");
	return 0;
}