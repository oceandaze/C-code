#include "stdafx.h"
#include "PackFile.h"

#include <iostream>


PackFile::PackFile(const string &fileName)
{
	this->m_fileName = fileName;
}


PackFile::~PackFile()
{
}

void PackFile::add(const string & filePath)
{
	m_fileList.push_back(filePath);
}

/*
标记		4字节     0118
文件个数    4字节
文件1
	文件名信息
		文件名长度  2字节
		文件名内容  N
	文件数据
		数据长度	8字节
		数据		N
文件2
文件3
文件N
*/
void PackFile::save()
{
	ofstream file(m_fileName, ios::binary);
	if (!file.is_open()) {
		cout << m_fileName << "打开失败\n";
		return;
	}

	file.write("0118", 4);

	int fileCnt = (int)m_fileList.size();
	file.write((const char*)&fileCnt, 4);

	for (const auto &i : m_fileList) {
		write(i, file);
	}

	cout << "生成" << m_fileName << "完成\n";
}

string PackFile::getFileName(const string & filePath) const
{
	size_t pos = filePath.rfind("\\");
	if (pos != string::npos) {
		return filePath.substr(pos + 1);
	}
	
	return filePath;
}

void PackFile::write(const string & filePath, ofstream & file)
{
	string fileName = getFileName(filePath);
	cout << "打包 " << fileName << endl;

	uint64_t fileSize = fileName.size();
	file.write((const char*)&fileSize, 2);
	file.write(fileName.c_str(), fileName.size());

	ifstream inFile(filePath, ios::binary);
	inFile.seekg(0, ios::end);
	fileSize = inFile.tellg();
	file.write((const char*)&fileSize, sizeof(fileSize));

	const int MAX_BUFFER = 1024 * 1024 * 4;
	char *buffer = new char[MAX_BUFFER];
	inFile.seekg(0, ios::beg);
	while (!inFile.eof()) {
		streamsize bytes = inFile.read(buffer, MAX_BUFFER).gcount();
		file.write(buffer, bytes);
	}
	delete[] buffer;
}
