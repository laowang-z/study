#include <afxwin.h>

// 应用程序类CWinApp，派生类(子类)
class MyApp :public CWinApp
{
public:
	// 基类的虚函数，重写
	//MFC程序入口地址
	virtual BOOL InitInstance();
};

// 框架类 CFrameWnd，派生类(子类)
class MyFrame:public CFrameWnd
{
public:
	MyFrame(); // 构造函数

	//声明宏，提供消息映射机制
	DECLARE_MESSAGE_MAP();

	afx_msg void OnLButtonDown(UINT, CPoint);
	afx_msg void OnChar(UINT, UINT, UINT);
	afx_msg void OnPaint();
};