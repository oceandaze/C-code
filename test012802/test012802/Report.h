#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Report
{
public:
	Report();
	virtual ~Report();

	void run(const string &path);

protected:
	virtual void output(vector<vector<string>> &data) = 0;
protected:
	void analyze(const string &str, vector<vector<string>> &data);
	void sort(vector<vector<string>> &data);
	string findField(const string &data, const string &mark, size_t &left) const;
protected:
	ofstream		m_out;
};

