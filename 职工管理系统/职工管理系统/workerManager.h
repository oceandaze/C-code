#pragma once
#include<iostream>
#include "worker.h"
using namespace std;


class workerManager
{
public:
	workerManager();
	~workerManager();

	void Show_Menu();
	//����ְ��
	void Add_Emp();

private:
	//��¼�ļ��е���������
	int m_EmpNum;
	//Ա�������ָ��
	Worker **m_EmpArray;
};

