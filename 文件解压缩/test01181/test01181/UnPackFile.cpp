#include "stdafx.h"
#include "UnPackFile.h"
#include <iostream>

UnPackFile::UnPackFile(const string &fileName)
{
	m_fileName = fileName;
}


UnPackFile::~UnPackFile()
{
}

void UnPackFile::save(const string & path)
{
	ifstream file(m_fileName, ios::binary);
	if (!file.is_open()) {
		cout << m_fileName << "打开失败\n";
		return;
	}

	char mark[5] = { 0 };
	file.read(mark, 4);
	if (strcmp(mark, "0118") != 0) {
		cout << m_fileName << "无法处理\n";
		return;
	}

	int fileCnt = 0;
	file.read((char*)&fileCnt, 4);
	for (int i = 0; i < fileCnt; ++i) {
		read(path, file);
	}

	cout << "提取完成\n";
}

void UnPackFile::read(const string & path, ifstream & file)
{
	const int MAX_BUFFER = 1024 * 1024 * 4;
	char *buffer = new char[MAX_BUFFER];

	uint64_t fileSize = 0;
	file.read((char*)&fileSize, 2);
	file.read(buffer, fileSize);
	buffer[fileSize] = '\0';
	

	file.read((char*)&fileSize, sizeof(fileSize));

	string filePath = path;
	filePath += "\\";
	filePath += buffer;

	ofstream outFile(filePath, ios::binary);
	uint64_t readBytes = 0;
	while (readBytes < fileSize)
	{
		uint64_t bytes = fileSize - readBytes;
		bytes = bytes > MAX_BUFFER ? MAX_BUFFER : bytes;

		file.read(buffer, bytes);
		outFile.write(buffer, bytes);

		readBytes += bytes;
	}

	delete[] buffer;

	cout << "提取到 " << filePath << endl;
}
