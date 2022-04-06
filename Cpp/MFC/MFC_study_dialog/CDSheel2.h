#pragma once
#include "afxdialogex.h"


// CDSheel2 dialog

class CDSheel2 : public CDialogEx
{
	DECLARE_DYNAMIC(CDSheel2)

public:
	CDSheel2(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDSheel2();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHEEL2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
