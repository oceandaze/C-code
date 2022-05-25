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
	void App(Task*p);
private:
	char str1[50];
	char str2[50];
	char str3[50];
};

