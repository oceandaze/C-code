#pragma once
#include <string>
#include <vector>

using namespace std;
// 1��ʹ�ö��̣߳��ֱ�������Ŀ¼��ȡ�ļ��б������ܺ���б��ļ���С�������򣬴�ӡǰ10���ļ���

class Dir
{
public:
	void find(const vector<string> &path);

	//��ӡָ��Ŀ¼�µ��ļ��б��������ļ�����
	static int list(const char* name, vector<vector<string>> &data,int level = 0);
	void output();
// private:
// 	static const char *toBigUnit(double val);
// 	static const char *getPath(const char *path, const char *name);
// 	static const char *getAttribName(unsigned attrib);
private:
	vector<vector<string>> data;
};

