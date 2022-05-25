#pragma once
#include "Task.h"
class TaskManagement
{
public:
	TaskManagement();
	~TaskManagement();
	void menu();
	void taskList();
	void addTask();
private:
	Task * job[50];
	int index;
};

