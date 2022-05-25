#pragma once
#include <string>
#include <vector>

using namespace std;
// 1、使用多线程，分别遍历多个目录获取文件列表，将汇总后的列表按文件大小降序排序，打印前10个文件。

class Dir
{
public:
	void find(const vector<string> &path);

	//打印指定目录下的文件列表，并返回文件个数
	static int list(const char* name, vector<vector<string>> &data,int level = 0);
	void output();
// private:
// 	static const char *toBigUnit(double val);
// 	static const char *getPath(const char *path, const char *name);
// 	static const char *getAttribName(unsigned attrib);
private:
	vector<vector<string>> data;
};

