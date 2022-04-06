// CDlgshow.cpp: 实现文件
//

#include "pch.h"
#include "MFC_study_dialog.h"
#include "afxdialogex.h"
#include "CDlgshow.h"


// CDlgshow 对话框

IMPLEMENT_DYNAMIC(CDlgshow, CDialogEx)

CDlgshow::CDlgshow(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SHOW, pParent)
{

}

CDlgshow::~CDlgshow()
{
}

void CDlgshow::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgshow, CDialogEx)
END_MESSAGE_MAP()


// CDlgshow 消息处理程序
