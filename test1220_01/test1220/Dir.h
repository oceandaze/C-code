#pragma once
class Dir
{
public:
	static bool remove(const char* name); //ɾ���ļ� 
	static bool mkdir(const char* name); //�����ļ��� 
	//��ӡָ��Ŀ¼�µ��ļ��б��������ļ�����
	static int list(const char* name); 
};

