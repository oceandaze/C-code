#pragma once
#include "Student.h"
#include "LoadData.h"
class App
{
public:
	App();

	void run(LoadData *p);
private:
	Student stu[100];
	int pos;
};
