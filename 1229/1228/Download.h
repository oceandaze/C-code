#pragma once
#include "Task.h"
class Download :
	public Task
{
public:
	Download();
	~Download();
	virtual void info();
	virtual void show();
private:
	int cnt;
};

