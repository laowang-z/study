#include "MFC_study_1.h"

MyApp app; // 有且只有一个全局的应用程序类对象

BOOL MyApp::InitInstance() //程序入口地址
{
	MyFrame* frame = new MyFrame; // 创建框架类对象

	frame->ShowWindow(SW_SHOWNORMAL); // 显示窗口
	frame->UpdateWindow(); // 更新窗口

	m_pMainWnd = frame; // 保存框架类对象指针

	return TRUE; // 初始化正常则返回TRUE
}

//分界宏
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd) // 开始消息映射的定义
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR() 
	ON_WM_PAINT() 
END_MESSAGE_MAP() // 结束消息映射的定义


MyFrame::MyFrame()
{
	Create(NULL, TEXT("MFC")); // 创建窗口 
}

void MyFrame::OnLButtonDown(UINT, CPoint point)
{
	CString str;
	str.Format(TEXT("x = %d, y = %d"), point.x, point.y);
	MessageBox(str);
}

void MyFrame::OnChar(UINT key, UINT, UINT)
{
	CString str;
	str.Format(TEXT("按下了 %c 键"), key);
	int num = wcslen(str);
	str.Format(TEXT("%s, 字符串长度为 %d"), str, num);
	MessageBox(str);
}

void MyFrame::OnPaint()
{
	CPaintDC dc(this);
	dc.Ellipse(0, 0, 200, 200);
	dc.TextOutW(100, 100, TEXT("为了联盟"));
}


