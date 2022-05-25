#include "stdafx.h"
#include "MemData.h"


MemData::MemData()
{
	cout << "memdata构造" << endl;
}


MemData::~MemData()
{
	cout << "memdata析构" << endl;

}

int MemData::read(Student stu[])
{	  
	stu[0].setName("张三");
	stu[0].setAge(18);
	stu[0].setSex("男");

	stu[1].setName("李四");
	stu[1].setAge(19);
	stu[1].setSex("女");

	stu[2].setName("王五");
	stu[2].setAge(12);
	stu[2].setSex("男");
	return 3;
}
