#pragma once
#include "afxdialogex.h"


// CDSheel1 dialog

class CDSheel1 : public CDialogEx
{
	DECLARE_DYNAMIC(CDSheel1)

public:
	CDSheel1(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDSheel1();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_sheel1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
