#pragma once
#include "afxdialogex.h"


// CDlgshow 对话框

class CDlgshow : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgshow)

public:
	CDlgshow(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlgshow();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHOW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
