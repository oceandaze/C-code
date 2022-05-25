// 0211.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Dir.h"
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <windows.h>
using namespace std;
// 1、使用多线程，分别遍历多个目录获取文件列表，将汇总后的列表按文件大小降序排序，打印前10个文件。

int main()
{
	vector<string> path;
	path.push_back("D:\\迅雷下载");
	path.push_back("D:\\test");

	//int cnt = Dir::list("D:\\迅雷下载");
	Dir d1;
	d1.find(path);
	d1.output();
	//cout << "文件个数:" << cnt << endl;
    return 0;
}


void workThread()
{
	cout << "线程启动\n";
	Sleep(5000);
}
void start()
{
	thread t1(workThread);				
	t1.join(); //需要等待
	//t1.detach();//分离对象和线程

}

int main2()
{
	start();
	int c;
	cout << "请输入\n" << endl;
	cin >> c;
	
	return 0;
}
