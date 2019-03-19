#pragma once
#include<vector>
#include<string>

using namespace std;

class PictureManager {

public:
	PictureManager(wstring);
	~PictureManager();

	bool setFolder(wstring);

	//按照编号取图片地址
	wstring getPic(int);

	//图片数量
	int getPicNum();

private:
	wstring picFolder;
	vector<wstring> picNames;
	bool getPicNames(wstring, vector<wstring>&);
	bool isPng(const wchar_t *);//判断是否为png文件
};