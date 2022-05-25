#pragma once


#include <iostream>
using namespace std;

class Task
{
public:
	Task();
	~Task();

	virtual void info();
	virtual void show();
protected:
	char str[50];

};

