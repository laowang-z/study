#include <afxwin.h>

// Ӧ�ó�����CWinApp��������(����)
class MyApp :public CWinApp
{
public:
	// ������麯������д
	//MFC������ڵ�ַ
	virtual BOOL InitInstance();
};

// ����� CFrameWnd��������(����)
class MyFrame:public CFrameWnd
{
public:
	MyFrame(); // ���캯��

	//�����꣬�ṩ��Ϣӳ�����
	DECLARE_MESSAGE_MAP();

	afx_msg void OnLButtonDown(UINT, CPoint);
	afx_msg void OnChar(UINT, UINT, UINT);
	afx_msg void OnPaint();
};