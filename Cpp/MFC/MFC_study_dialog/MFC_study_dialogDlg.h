
// MFC_study_dialogDlg.h: 头文件
//

#pragma once
#include "CDlgshow.h"
#include "CDlgExec.h"
#include "CDTab.h"
#include "CDSheel1.h"
#include "CDSheel2.h"


// CMFCstudydialogDlg 对话框
class CMFCstudydialogDlg : public CDialogEx
{
// 构造
public:
	CMFCstudydialogDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_STUDY_DIALOG_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();

private:
	CDlgshow dlg;
	CStatic m_text;
public:
	afx_msg void ChangeTextTowjw();
	afx_msg void OnBnClickedButton4();
private:
	CButton Button_wjw;
	CEdit l_edit;
	CEdit r_edit;
public:
	afx_msg void EditGoRight();
	afx_msg void EditGoLeft();
	afx_msg void Break_curr();
	virtual void OnOK();
	afx_msg void SelChange();
private:
	CComboBox Sex_Combo;
	CListCtrl m_list;
	CTreeCtrl m_tree;
	CImageList imagelist;
public:
	afx_msg void OnTvnSelchangingTree1(NMHDR* pNMHDR, LRESULT* pResult);
private:
	CDSheel1 m_sheel1;
	CDSheel2 m_sheel2;
	CTabCtrl m_tab;
public:
	afx_msg void OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
};
