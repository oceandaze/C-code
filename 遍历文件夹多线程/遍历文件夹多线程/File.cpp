#include "stdafx.h"
#include "File.h"





File::File(const string & name, uint64_t size)
	:filename(name),filesize(size)
{
}

File::~File()
{
}

bool File::operator<(const File & other)
{
	return filesize > other.filesize;
}

ostream &operator<< (ostream &out, const File &other)
{
	out << other.filename << "\t"
		<< other.filesize << endl;
	return out;
}