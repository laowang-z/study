
// MFC_study_dialogDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFC_study_dialog.h"
#include "MFC_study_dialogDlg.h"
#include "afxdialogex.h"
#include "CDlgExec.h"
#include "CDlgshow.h"
#include "CDSheel1.h"
#include "CDSheel2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCstudydialogDlg 对话框



CMFCstudydialogDlg::CMFCstudydialogDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_STUDY_DIALOG_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCstudydialogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TEXT, m_text);
	DDX_Control(pDX, IDC_BUTTON3, Button_wjw);
	DDX_Control(pDX, IDC_EDIT2, l_edit);
	DDX_Control(pDX, IDC_EDIT1, r_edit);
	DDX_Control(pDX, IDC_COMBO1, Sex_Combo);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_TREE1, m_tree);
	DDX_Control(pDX, IDC_TAB1, m_tab);
	DDX_Control(pDX, IDC_TAB1, m_tab);
}

BEGIN_MESSAGE_MAP(CMFCstudydialogDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCstudydialogDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCstudydialogDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCstudydialogDlg::ChangeTextTowjw)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCstudydialogDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCstudydialogDlg::EditGoRight)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCstudydialogDlg::EditGoLeft)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCstudydialogDlg::Break_curr)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMFCstudydialogDlg::SelChange)
	ON_NOTIFY(TVN_SELCHANGING, IDC_TREE1, &CMFCstudydialogDlg::OnTvnSelchangingTree1)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CMFCstudydialogDlg::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// CMFCstudydialogDlg 消息处理程序

BOOL CMFCstudydialogDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	dlg.Create(IDD_SHOW);

	Sex_Combo.AddString(_T("男")); // 添加选项
	Sex_Combo.AddString(_T("女"));
	Sex_Combo.AddString(_T("其他"));
	Sex_Combo.SetCurSel(2); // 默认选项
	Sex_Combo.InsertString(0, _T("你猜")); // 插入选项，不会影响已经设置的默认选项
	Sex_Combo.DeleteString(3); // 删除选项，会影响已经设置的默认选项

	//初始化列表
	CString str[] = { _T("name"), _T("sex"), _T("age") };

	// 设置标头
	for (int i = 0; i < 3; i ++ )
	{
		m_list.InsertColumn(i, str[i], LVCFMT_CENTER, 50);
		//插入列，参数：列索引、插入的值、对齐方式、列宽
	}

	// 设置正文，索引从0开始
	m_list.InsertItem(0, _T("wjw"));
	//插入其他列的数据
	m_list.SetItemText(0, 1, _T("man"));

	// 设置属性
	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_GRIDLINES);

	//初始化树
	//设置图标
	HICON icons[4];
	icons[0] = AfxGetApp()->LoadIconW(IDI_ICON1);
	icons[1] = AfxGetApp()->LoadIconW(IDI_ICON2);
	icons[2] = AfxGetApp()->LoadIconW(IDI_ICON3);
	icons[3] = AfxGetApp()->LoadIconW(IDI_ICON4);

	// 在.h文件中定义imagelist，以将其保留
	imagelist.Create(32, 32, ILC_COLOR32, 4, 4);
	for (int i = 0; i < 4; i++)
	{
		imagelist.Add(icons[i]);
	}
	m_tree.SetImageList(&imagelist, TVSIL_NORMAL);

	//设置节点
	HTREEITEM root = m_tree.InsertItem(_T("根节点"), 0, 0, NULL);
	HTREEITEM parent = m_tree.InsertItem(_T("父节点"), 1, 1, root);
	HTREEITEM son1 = m_tree.InsertItem(_T("子节点1"), 2, 2, parent);
	HTREEITEM son2 = m_tree.InsertItem(_T("子节点2"), 3, 3, parent);

	// 设置默认选项
	m_tree.SelectItem(son2);


	// 标签页初始化
	//添加标签页
	m_tab.InsertItem(0, _T("Sheel1"));
	m_tab.InsertItem(1, _T("Sheel2"));

	m_sheel1.Create(IDD_sheel1, GetDlgItem(IDC_TAB1));
	m_sheel2.Create(IDD_SHEEL2, GetDlgItem(IDC_TAB1));

	CRect rs;
	m_tab.GetClientRect(rs);
	rs.top += 20;
	rs.bottom -= 1;
	rs.left -= 2;
	rs.right -= 1;

	m_sheel1.SetParent(GetDlgItem(IDC_TAB1));
	m_sheel2.SetParent(GetDlgItem(IDC_TAB1));

	m_sheel1.MoveWindow(&rs);
	m_sheel2.MoveWindow(&rs);

	m_sheel2.ShowWindow(FALSE);
	m_sheel1.ShowWindow(TRUE);
	m_tab.SetCurSel(0);
	

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCstudydialogDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCstudydialogDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCstudydialogDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





void CMFCstudydialogDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CDlgExec dlg;
	dlg.DoModal();

}


void CMFCstudydialogDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	dlg.ShowWindow(SW_SHOWNORMAL);
}



void CMFCstudydialogDlg::ChangeTextTowjw()
{
	// TODO: 在此添加控件通知处理程序代码
	m_text.SetWindowTextW(_T("wjw"));
	Button_wjw.EnableWindow(FALSE); // 点击后button不可用
}




void CMFCstudydialogDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	m_text.GetWindowTextW(str);
	MessageBox(str);
}




void CMFCstudydialogDlg::EditGoRight()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	l_edit.GetWindowTextW(str);
	r_edit.SetWindowTextW(str);
}


void CMFCstudydialogDlg::EditGoLeft()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	r_edit.GetWindowTextW(str);
	l_edit.SetWindowTextW(str);
}




void CMFCstudydialogDlg::Break_curr()
{
	// TODO: 在此添加控件通知处理程序代码
	// 退出当前对话框
	CDialog::OnCancel();
}


void CMFCstudydialogDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}


void CMFCstudydialogDlg::SelChange()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	Sex_Combo.GetLBText(Sex_Combo.GetCurSel(), str);
	// 获取下拉菜单当前选项
	MessageBox(str);
}


void CMFCstudydialogDlg::OnTvnSelchangingTree1(NMHDR* pNMHDR, LRESULT* pResult)
{
	// 当在树中更换选项时触发
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;

	// 获取当前选项
	HTREEITEM item = pNMTreeView->itemOld.hItem;
	CString item_text = m_tree.GetItemText(item);

	// 获取选择的选项
	HTREEITEM next = pNMTreeView->itemNew.hItem;
	CString next_text = m_tree.GetItemText(next);

	CString output;
	if (item_text != L"" && next_text != L"")
	{
		output.Format(_T("从%s变到了%s"), item_text, next_text);
		MessageBox(output);
	}
		

}




void CMFCstudydialogDlg::OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
	switch (m_tab.GetCurSel())
	{
	case 0:
		m_sheel2.ShowWindow(FALSE);
		m_sheel1.ShowWindow(TRUE);
		break;
	case 1:
		m_sheel1.ShowWindow(FALSE);
		m_sheel2.ShowWindow(TRUE);
		break;
	}
}
