#pragma once
#include "User.h"
class Admin :
	public User
{
public:
	Admin();
	~Admin();
	virtual void input();
	virtual void show();
};

