// PictureBrowser.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "PictureBrowser.h"

#include "MainWnd.h"

int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)

{

	CPaintManagerUI::SetInstance(hInstance);// ����XML��ʱ����Ҫʹ�øþ��ȥ��λEXE��·�������ܼ���XML��·��
											//����XML��·��
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath()); //�˴�����Ϊ��exe��ͬһĿ¼

	CMainWindow mainWnd;
	mainWnd.Create(NULL, _T("DUIWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	mainWnd.CenterWindow();
	mainWnd.ShowModal();

	//CPaintManagerUI::MessageLoop();

	delete mainWnd;

	return 0;


}
