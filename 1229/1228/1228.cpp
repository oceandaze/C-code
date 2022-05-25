// 1228.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "TaskManagement.h"
using namespace std;

int main()
{
	TaskManagement task;

	while (1){
		task.menu();
		int n = 0;
		cin >> n;
		switch (n)
		{
		case 1:
			task.addTask();
			break;
		case 2:
			task.taskList();
			break;
		case 3:
			exit(1);
			break;
		default:
			cout << "输入有误，请重新输入" << endl;
			break;
		}

	}
	return 0;
}