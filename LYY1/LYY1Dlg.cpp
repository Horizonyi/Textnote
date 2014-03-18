// LYY1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LYY1.h"
#include "LYY1Dlg.h"
#include "SeconDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CLYY1Dlg �Ի���





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


// CLYY1Dlg ��Ϣ�������

BOOL CLYY1Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�
   
	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CLYY1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ��������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
//
HCURSOR CLYY1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CLYY1Dlg::OnBnClickedButtonYs()
{
 	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnCancel();
}

void CLYY1Dlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
    //���ļ�
	//��ȷ��д������Ӣ�ģ�
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
     //�����ı�
     
	m_RichEdit.SetWindowText(str);

}

void CLYY1Dlg::OnBnClickedButtonSave()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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


