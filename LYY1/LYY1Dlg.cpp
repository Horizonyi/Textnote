// LYY1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LYY1.h"
#include "LYY1Dlg.h"
#include "SeconDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CLYY1Dlg 对话框





CLYY1Dlg::CLYY1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLYY1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
}

void CLYY1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RICHEDIT21, m_RichEdit);
}

BEGIN_MESSAGE_MAP(CLYY1Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_YS, &CLYY1Dlg::OnBnClickedButtonYs)
	ON_BN_CLICKED(IDCANCEL, &CLYY1Dlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CLYY1Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_READ, &CLYY1Dlg::OnBnClickedButtonRead)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CLYY1Dlg::OnBnClickedButtonSave)
	//ON_WM_CTLCOLOR()
	//ON_EN_CHANGE(IDC_EDIT1, &CLYY1Dlg::OnEnChangeEdit1)
	
END_MESSAGE_MAP()


// CLYY1Dlg 消息处理程序

BOOL CLYY1Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。
   
	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CLYY1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CLYY1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作矩形中居中
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
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
//
HCURSOR CLYY1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CLYY1Dlg::OnBnClickedButtonYs()
{
 	// TODO: 在此添加控件通知处理程序代码
    CFontDialog dlg;
	if(dlg.DoModal()==IDOK)
	{
	  LOGFONT temp;
	  dlg.GetCurrentFont(&temp);
	  CHARFORMAT cf;  
	  memset(&cf,0,sizeof(CHARFORMAT));
	  m_RichEdit.GetDefaultCharFormat(cf);
	  cf.yHeight = temp.lfWeight;
	  cf.dwMask = CFM_COLOR|CFM_SIZE|CFM_FACE;
	  cf.dwEffects = CFE_BOLD;
	  cf.crTextColor = dlg.GetColor();
	  strcpy((char*)cf.szFaceName,(char*)temp.lfFaceName);
	  m_RichEdit.SetWordCharFormat(cf);
	  m_RichEdit.SetSel(-1,-1);
	  m_RichEdit.ReplaceSel((LPCTSTR)"\n");
	  m_RichEdit.SetSel(-1,-1);
	}
	
	

}

void CLYY1Dlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	OnCancel();
}

void CLYY1Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//this->ShowWindow(SW_HIDE);
	//CSeconDlg dlg;
	//dlg.DoModal();
    
	if(!IsWindow(dlg.m_hWnd))
	{
	 dlg.Create(IDD_DIALOG_SECO,this);
	
	}
	dlg.ShowWindow(SW_SHOW);

}
void CLYY1Dlg::OnBnClickedButtonRead()
{
	// TODO: 在此添加控件通知处理程序代码
    //打开文件
	//正确的写法（读英文）
	CStdioFile file;
	CString str;

    CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,_T("Txt Files (*.txt)|*.txt"),NULL );

   if(dlg.DoModal()!=IDOK)
   { return;  }

   CString filename;
   filename=dlg.GetPathName();

   //CFile f;

   if(NULL==file.Open(filename,CFile::modeNoTruncate|CFile::modeRead))
   {
	 return;

   }
 
   file.ReadString(str.GetBuffer(file.GetLength()), file.GetLength());
   str.ReleaseBuffer();
   file.Close();
     //设置文本
     
	m_RichEdit.SetWindowText(str);

}

void CLYY1Dlg::OnBnClickedButtonSave()
{
	// TODO: 在此添加控件通知处理程序代码
   CStdioFile file;
   CFileDialog* dlg;
   CString filepathname;
  
   dlg = new CFileDialog(FALSE,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,_T("Txt Files (*.txt)|*.txt"),NULL );

   if(dlg->DoModal()!=IDOK)
   { return;  }

  
   CString str;
   GetDlgItem(IDC_RICHEDIT21)->GetWindowText(str);

   filepathname = dlg->GetPathName();
   file.Open(filepathname, CFile::modeCreate | CFile::modeWrite | CFile::typeText); 
   file.WriteString(str);
   str.Empty();
   m_RichEdit.SetWindowText(str);
  
}


