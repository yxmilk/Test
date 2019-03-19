#include"MainWnd.h"

void CMainWindow::Notify(TNotifyUI& msg) {

	if (msg.sType == _T("click")) {

		clickEvent(msg);

	}
	else if (msg.sType == _T("windowinit")) {
	
		wndInitEvent(msg);
	}

}

void CMainWindow::clickEvent(TNotifyUI &msg) {

	if (msg.pSender->GetName() == _T("minBtn")) {

		::ShowWindow(GetActiveWindow(), SW_MINIMIZE);

	}
	else if (msg.pSender->GetName() == _T("closeBtn")) {

		exit(0);

	}
	else if (msg.pSender->GetName() == _T("maxBtn")) {

		::ShowWindow(GetActiveWindow(), SW_MAXIMIZE);

	}
	else if (msg.pSender->GetName() == _T("preBtn")) {
	
		prePicture();
	}
	else if (msg.pSender->GetName() == _T("nextBtn")) {

		nextPicture();
	}
	else if (msg.pSender->GetName() == _T("pathBtn")) {

		if (pm->setFolder(selectPath() + L"\\*")) {
		
			//显示图片
			CControlUI *imgLabel = m_PaintManager.FindControl(_T("labelImg"));
			imgLabel->SetBkImage(pm->getPic(0).c_str());
			curPic = 0;
		}
		else {
		
			MessageBox(NULL, _T("该目录没有PNG图片！"), _T("信息"), 0);

		}
		
	}
}

void CMainWindow::wndInitEvent(TNotifyUI &msg) {

	//显示图片
	CControlUI *imgLabel = m_PaintManager.FindControl(_T("labelImg"));
	pm = new PictureManager(Utility::getPwd() + L"\\*");
	//pm = new PictureManager(L"G:\\DuiLibTest\\DuiLibTest\\Debug\\*");
	if (pm->getPicNum() > 0) {

		imgLabel->SetBkImage(pm->getPic(0).c_str());
		curPic = 0;
	}
	else {

		MessageBox(NULL, _T("当前目录下未找到PNG图片！"), _T("信息"), 0);
	}

	//显示路径
	CEditUI *pathEd = (CEditUI *)m_PaintManager.FindControl(_T("pathEdit"));
	pathEd->SetText(Utility::getPwd().c_str());
	pathEd->SetReadOnly(TRUE);

}

void CMainWindow::prePicture() {

	if (curPic == 0) {
	
		MessageBox(NULL, _T("已经是第一张图片！"), _T("信息"), 0);
	}
	else {
	
		--curPic;
		CControlUI *imgLabel = m_PaintManager.FindControl(_T("labelImg"));
		imgLabel->SetBkImage(pm->getPic(curPic).c_str());

	}
}

void CMainWindow::nextPicture() {

	if (curPic == pm->getPicNum() - 1) {

		MessageBox(NULL, _T("已经是最后图片！"), _T("信息"), 0);
	}
	else {
	
		++curPic;
		CControlUI *imgLabel = m_PaintManager.FindControl(_T("labelImg"));
		imgLabel->SetBkImage(pm->getPic(curPic).c_str());
	}

}

wstring CMainWindow::selectPath() {

	wchar_t szFolderPath[MAX_PATH] = { 0 };
	wstring strFolderPath = TEXT("");

	BROWSEINFO sInfo;
	ZeroMemory(&sInfo, sizeof(BROWSEINFO));
	sInfo.pidlRoot = 0;
	sInfo.lpszTitle = _T("请选择一个文件夹：");
	sInfo.ulFlags = BIF_DONTGOBELOWDOMAIN | BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE | BIF_EDITBOX;
	sInfo.lpfn = NULL;

	// 显示文件夹选择对话框  
	LPITEMIDLIST lpidlBrowse = ::SHBrowseForFolder(&sInfo);
	if (lpidlBrowse != NULL)
	{
		// 取得文件夹名  
		if (::SHGetPathFromIDList(lpidlBrowse, szFolderPath))
		{
			strFolderPath = szFolderPath;
		}
	}
	if (lpidlBrowse != NULL)
	{
		::CoTaskMemFree(lpidlBrowse);
	}

	return strFolderPath;

}