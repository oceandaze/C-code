#pragma once
class Dir
{
public:
	static bool remove(const char* name); //删除文件 
	static bool mkdir(const char* name); //创建文件夹 
	//打印指定目录下的文件列表，并返回文件个数
	static int list(const char* name, int level = 0);

private:
	static const char *toBigUnit(double val);
	static const char *getPath(const char *path, const char *name);
	static const char *getAttribName(unsigned attrib);
};

