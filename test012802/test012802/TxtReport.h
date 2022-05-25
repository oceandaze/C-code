#pragma once
#include "Report.h"
class TxtReport :
	public Report
{
public:
	TxtReport();
	~TxtReport();
protected:
	virtual void output(vector<vector<string>> &data);
};

