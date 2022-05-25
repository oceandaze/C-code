#pragma once
#include "Student.h"
class LoadData
{
public:
	LoadData();
	virtual ~LoadData();
	virtual int read(Student stu[])=0;
};

