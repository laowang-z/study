#include "MFC_study_1.h"

MyApp app; // ����ֻ��һ��ȫ�ֵ�Ӧ�ó��������

BOOL MyApp::InitInstance() //������ڵ�ַ
{
	MyFrame* frame = new MyFrame; // ������������

	frame->ShowWindow(SW_SHOWNORMAL); // ��ʾ����
	frame->UpdateWindow(); // ���´���

	m_pMainWnd = frame; // �����������ָ��

	return TRUE; // ��ʼ�������򷵻�TRUE
}

//�ֽ��
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd) // ��ʼ��Ϣӳ��Ķ���
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR() 
	ON_WM_PAINT() 
END_MESSAGE_MAP() // ������Ϣӳ��Ķ���


MyFrame::MyFrame()
{
	Create(NULL, TEXT("MFC")); // �������� 
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
	str.Format(TEXT("������ %c ��"), key);
	int num = wcslen(str);
	str.Format(TEXT("%s, �ַ�������Ϊ %d"), str, num);
	MessageBox(str);
}

void MyFrame::OnPaint()
{
	CPaintDC dc(this);
	dc.Ellipse(0, 0, 200, 200);
	dc.TextOutW(100, 100, TEXT("Ϊ������"));
}


