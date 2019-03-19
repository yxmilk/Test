#pragma once
#include <UIlib.h>
#include"PictureManager.h"
#include"Utility.h"
#include<shlobj.h>

using namespace DuiLib;

#ifdef _DEBUG
#   ifdef _UNICODE
#       pragma comment(lib, "DuiLib_ud.lib")
#   else
#       pragma comment(lib, "DuiLib_d.lib")
#   endif
#else
#   ifdef _UNICODE
#       pragma comment(lib, "DuiLib_u.lib")
#   else
#       pragma comment(lib, "DuiLib.lib")
#   endif
#endif

class CMainWindow :public WindowImplBase {

public:
	virtual LPCTSTR GetWindowClassName() const { return _T("DUIMainWnd"); }
	virtual CDuiString GetSkinFile() { return _T("MainWnd.xml"); }
	virtual CDuiString GetSkinFolder() { return _T(""); }
	
	//时间处理
	virtual void    Notify(TNotifyUI& msg);

private:
	//点击事件
	void clickEvent(TNotifyUI&);
	//窗口加载完成事件
	void wndInitEvent(TNotifyUI &);

	//上一张
	void prePicture();
	//下一张
	void nextPicture();

	//目录选择对话框
	wstring selectPath();

	int curPic = 0;
	//图片管理
	PictureManager *pm;

};