#pragma once

class User
{
public:
	User();
	~User();
	virtual void input();
	virtual void show();
protected:
	char attribute[32];
	char name[32];
	char pwd[16];
	
};

