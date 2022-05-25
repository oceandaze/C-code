#include "stdafx.h"
#include "Txtdata.h"


TxtData::TxtData()
{
	cout << "TxtData构造" << endl;

	errno_t err;
	err = fopen_s(&p, "1.txt", "r");
	if (err==0)
	{
		cout << "文件打开成功" << endl;
	}
	else
	{
		cout << "文件打开失败" << endl;
	}
}


TxtData::~TxtData()
{
	cout << "TxtData析构" << endl;
	fclose(p);
}

int TxtData::read(Student stu[])
{
	char t[100] ={0};
	int i = 0;
	char t_name[32] = {0};
	char t_sex[4] = {0};
	int t_age = 0;
	fgets(t,100,p);
	while (!feof(p))
	{
		fscanf_s(p, "%s\t%d\t%s",t_name,32,&t_age,t_sex,4);
		stu[i].setName(t_name);
		stu[i].setAge(t_age);
		stu[i].setSex(t_sex);
		memset(t_name, 0, sizeof(t_name));
		memset(t_sex, 0, sizeof(t_sex));
		++i;
	}
	return i;
}
