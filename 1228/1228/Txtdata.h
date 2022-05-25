#pragma once
#include "LoadData.h"
class TxtData :
	public LoadData
{
public:
	TxtData();
	~TxtData();
	virtual int read(Student stu[]) override;
private:
	FILE *p;
};

