#pragma once
#include "FileType.h"
class HtmlFile :
	public FileType
{
public:
	HtmlFile();
	~HtmlFile();
	virtual void write(vector<PAIR> v) override;
};

