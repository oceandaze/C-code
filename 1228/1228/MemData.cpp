#include "stdafx.h"
#include "MemData.h"


MemData::MemData()
{
	cout << "memdata����" << endl;
}


MemData::~MemData()
{
	cout << "memdata����" << endl;

}

int MemData::read(Student stu[])
{	  
	stu[0].setName("����");
	stu[0].setAge(18);
	stu[0].setSex("��");

	stu[1].setName("����");
	stu[1].setAge(19);
	stu[1].setSex("Ů");

	stu[2].setName("����");
	stu[2].setAge(12);
	stu[2].setSex("��");
	return 3;
}
