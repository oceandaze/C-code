#pragma once
#include "User.h"
class NormalUser :
	public User
{
public:
	NormalUser();
	~NormalUser();
	virtual void input();
	virtual void show();
private:
	char contents[100];
	char  userRight[100];

};

