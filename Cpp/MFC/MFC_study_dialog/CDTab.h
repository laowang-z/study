#pragma once
#include "afxdialogex.h"


// CDTab dialog

class CDTab : public CDialogEx
{
	DECLARE_DYNAMIC(CDTab)

public:
	CDTab(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDTab();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_STUDY_DIALOG_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
