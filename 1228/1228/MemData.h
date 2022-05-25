#pragma once
#include "LoadData.h"
class MemData :
	public LoadData
{
public:
	MemData();
	~MemData();
	virtual int read(Student stu[]) override;
};

