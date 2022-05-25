#include "stdafx.h"
#include "Sql.h"
#include <fstream>
#include <iostream>
using namespace std;

Sql::Sql()
{
}


Sql::~Sql()
{
}

void Sql::build(const string & fileName)
{
	ifstream file(fileName);
	if (!file) {
		cout << fileName << "打开失败\n";
		return;
	}

	string targetFileName = getFilename(fileName);
	cout << "生成 " << targetFileName << endl;

	ofstream out(targetFileName);

	string tableName = "t1_book";
	out << "-- 创建表" << tableName << endl;
	out << "create table " << tableName << "\n(\n"
		<< "    name varchar(128),\n"
		<< "    auth varchar(16),\n"
		<< "    price number(10, 2)\n);\n\n";

	int rowNumber = 0;
	string line;
	while (getline(file, line)) {
		vector<string> arr;
		split(line, arr);
		if (!arr.empty()) {
			out << "insert into " << tableName
				<< " values('"
				<< arr[0] << "','"
				<< arr[1] << "',"
				<< arr[2] << ");\n";
			++rowNumber;
		}
	}

	cout << "生成" << targetFileName << "完成, 导入"
		<< rowNumber  << "条记录." << endl;
}

string Sql::getFilename(const string & fileName) const
{
	size_t pos = fileName.rfind(".");
	if (pos != string::npos) {
		return fileName.substr(0, pos) + ".sql";
	}

	return fileName + ".sql";
}

void Sql::split(const string & str, vector<string>& arr)
{
	size_t pos, left = 0;
	while ((pos = str.find(";", left)) != string::npos) {
		arr.push_back(str.substr(left, pos - left));
		left = pos + 1;
	}

	if (left < str.size()) {
		arr.push_back(str.substr(left));
	}
}
