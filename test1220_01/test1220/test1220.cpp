// test1220.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "Dir.h"
using namespace std;

int main()
{
// 	cout << "删除文件"
// 		<< (Dir::remove("D:\\var\\QQ图片20210908185217.jpg")
// 		? "成功" : "失败") << endl;
// 
// 	cout << "创建文件夹"
// 		<< (Dir::mkdir("D:\\var\\test1")
// 			? "成功" : "失败") << endl;

	int cnt = Dir::list("D:\\C++\\test");
	cout << "文件个数:" << cnt << endl;

    return 0;
}

