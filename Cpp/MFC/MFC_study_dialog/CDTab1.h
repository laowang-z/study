#pragma once
#include "afxdialogex.h"
#include "CDSheel1.h"
#include "CDSheel2.h"


// CDTab1 dialog

class CDTab1 : public CDialogEx
{
	DECLARE_DYNAMIC(CDTab1)

public:
	CDTab1(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDTab1();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_STUDY_DIALOG_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:

};
