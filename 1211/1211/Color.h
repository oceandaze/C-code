#pragma once

class Color
{
private:
	char m_name[32];
public:
	void setName(const char * n = "black");
	void infoShow();
};

