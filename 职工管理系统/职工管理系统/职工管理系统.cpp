// 职工管理系统.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <iostream>

using namespace std;


// void test()
// {
// 	Worker * worker = NULL;
// 	worker = new Employee(1, "张三", 1);
// 	worker->showInfo();
// 	delete worker;
// 
// 	worker = new Manager(2, "李四", 2);
// 	worker->showInfo();
// 	delete worker;
// 
// 	worker = new Boss(3, "王五", 3);
// 	worker->showInfo();
// 	delete worker;
// }

int main()
{
	workerManager wm;
	int choice = 0;
	while (true)
	{
		wm.Show_Menu();
		cout << "请输入你的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出系统
			return 0;
			break;
		case 1: //添加职工

			wm.Add_Emp();
			break;
		case 2: //显示职工
			break;
		case 3: //删除职工
			break;
		case 4: //修改职工
			break;
		case 5: //查找职工
			break;
		case 6: //排序职工
			break;
		case 7: //清空文件
			break;
		default:
			system("cls");
			break;
		}
	}

    return 0;
}

