// 0211.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Dir.h"
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <windows.h>
using namespace std;
// 1��ʹ�ö��̣߳��ֱ�������Ŀ¼��ȡ�ļ��б������ܺ���б��ļ���С�������򣬴�ӡǰ10���ļ���

int main()
{
	vector<string> path;
	path.push_back("D:\\Ѹ������");
	path.push_back("D:\\test");

	//int cnt = Dir::list("D:\\Ѹ������");
	Dir d1;
	d1.find(path);
	d1.output();
	//cout << "�ļ�����:" << cnt << endl;
    return 0;
}


void workThread()
{
	cout << "�߳�����\n";
	Sleep(5000);
}
void start()
{
	thread t1(workThread);				
	t1.join(); //��Ҫ�ȴ�
	//t1.detach();//���������߳�

}

int main2()
{
	start();
	int c;
	cout << "������\n" << endl;
	cin >> c;
	
	return 0;
}
