#pragma once
#include "Report.h"

class CsvReport :
	public Report
{
public:
	CsvReport();
	~CsvReport();


protected:
	virtual void output(vector<vector<string>> &data);
};

