#pragma once
#include "User.h"
class App
{
public:
	App();
	~App();
	void run();
	void show();
	void add();
	User *creatuser(int n) const;

private:
	User *users[1024];
	int index;
};

