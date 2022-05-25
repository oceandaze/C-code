#pragma once
#include "Task.h"
class Upload :
	public Task
{
public:
	Upload();
	~Upload();
	virtual void info();
	virtual void show();
private:
	char uploader[32];
};

