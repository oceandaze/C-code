#pragma once

class Task
{
public:
	Task();
	~Task();

	virtual void input();
	virtual void output() const;

protected:
	char		path[64];
};

