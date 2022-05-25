#pragma once
#include "Report.h"

class HtmlReport :
	public Report
{
public:
	HtmlReport();
	~HtmlReport();

protected:
	virtual void output(vector<vector<string>> &data);
};

