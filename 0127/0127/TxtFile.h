#pragma once
#include "FileType.h"
class TxtFile :
	public FileType
{
public:
	TxtFile();
	~TxtFile();
	virtual void write(vector<PAIR> v) override;
};

