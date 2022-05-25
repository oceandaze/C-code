#pragma once
#include "Task.h"
class DownloadTask :
	public Task
{
public:
	DownloadTask();
	~DownloadTask();

	virtual void input();
	virtual void output() const;

private:
	int  count;
};

