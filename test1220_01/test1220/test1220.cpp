// test1220.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "Dir.h"
using namespace std;

int main()
{
// 	cout << "ɾ���ļ�"
// 		<< (Dir::remove("D:\\var\\QQͼƬ20210908185217.jpg")
// 		? "�ɹ�" : "ʧ��") << endl;
// 
// 	cout << "�����ļ���"
// 		<< (Dir::mkdir("D:\\var\\test1")
// 			? "�ɹ�" : "ʧ��") << endl;

	int cnt = Dir::list("D:\\C++\\test");
	cout << "�ļ�����:" << cnt << endl;

    return 0;
}

