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
���		4�ֽ�     0118
�ļ�����    4�ֽ�
�ļ�1
	�ļ�����Ϣ
		�ļ�������  2�ֽ�
		�ļ�������  N
	�ļ�����
		���ݳ���	8�ֽ�
		����		N
�ļ�2
�ļ�3
�ļ�N
*/
void PackFile::save()
{
	ofstream file(m_fileName, ios::binary);
	if (!file.is_open()) {
		cout << m_fileName << "��ʧ��\n";
		return;
	}

	file.write("0118", 4);

	int fileCnt = (int)m_fileList.size();
	file.write((const char*)&fileCnt, 4);

	for (const auto &i : m_fileList) {
		write(i, file);
	}

	cout << "����" << m_fileName << "���\n";
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
	cout << "��� " << fileName << endl;

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
