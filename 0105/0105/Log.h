#pragma once
class Log
{
public:
	Log();
	~Log();
	void info(const char *fileName, int line, const char *msg);

private:
	const char *getTime() const;
private:
	FILE* fp;
};

#define LOG_INFO(msg) g_log.info(__FILE__, __LINE__, msg)