#pragma once
#include "Task.h"
class GetFileList :
	public Task
{
public:
	GetFileList();
	~GetFileList();
	virtual void info();
	virtual void show();
};

