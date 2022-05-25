#pragma once
class Dir
{
public:
	Dir();
	~Dir();

	static bool remove(const char * name);
	static bool mkdir(const char * name);
	static int list(const char *name);
};

