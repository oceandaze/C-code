#pragma once
#include<iostream>
#include "worker.h"
using namespace std;


class workerManager
{
public:
	workerManager();
	~workerManager();

	void Show_Menu();
	//增加职工
	void Add_Emp();

private:
	//记录文件中的人数个数
	int m_EmpNum;
	//员工数组的指针
	Worker **m_EmpArray;
};

