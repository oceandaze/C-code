#include "stdafx.h"
#include "Upload.h"


Upload::Upload()
{
}


Upload::~Upload()
{
}

void Upload::info()
{
	cout << "请输入保存路径和作者" << endl;
	cin >> str >> uploader;
}

void Upload::show()
{
	cout << "任务类型: 上传文件		保存路径:" << str << "		上传者:" << uploader<< endl;
	 		
}
