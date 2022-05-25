#pragma once
#include "Task.h"

class FileListTask :
	public Task
{
public:
	FileListTask();
	~FileListTask();

	virtual void input();
	virtual void output() const;
};

