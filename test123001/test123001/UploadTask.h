#pragma once
#include "Task.h"
class UploadTask :
	public Task
{
public:
	UploadTask();
	~UploadTask();

	virtual void input();
	virtual void output() const;

private:
	char name[16];
};

