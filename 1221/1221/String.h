#pragma once
class String
{
	char * ret;
public:
	String(char*str=nullptr);
	String(String&other);
	~String();


	void cat(int );
	void cat(const char *);
	void cat(double);
	void output()const;
	bool equal(const char*);
	bool equal(const String&other);

};

