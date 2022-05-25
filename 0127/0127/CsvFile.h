#pragma once
#include "FileType.h"
class CsvFile :
	public FileType
{
public:
	CsvFile();
	~CsvFile();
	virtual void write(vector<PAIR> v) override;
};

