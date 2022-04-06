// CDTab.cpp : implementation file
//

#include "pch.h"
#include "MFC_study_dialog.h"
#include "afxdialogex.h"
#include "CDTab.h"


// CDTab dialog

IMPLEMENT_DYNAMIC(CDTab, CDialogEx)

CDTab::CDTab(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_STUDY_DIALOG_DIALOG, pParent)
{

}

CDTab::~CDTab()
{
}

void CDTab::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDTab, CDialogEx)
END_MESSAGE_MAP()


// CDTab message handlers
