#pragma once
class Dir
{
public:
	static bool remove(const char* name); //ɾ���ļ� 
	static bool mkdir(const char* name); //�����ļ��� 
	//��ӡָ��Ŀ¼�µ��ļ��б��������ļ�����
	static int list(const char* name, int level = 0);

private:
	static const char *toBigUnit(double val);
	static const char *getPath(const char *path, const char *name);
	static const char *getAttribName(unsigned attrib);
};

