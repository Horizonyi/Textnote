// SeconDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LYY1.h"
#include "SeconDlg.h"


// CSeconDlg �Ի���

IMPLEMENT_DYNAMIC(CSeconDlg, CDialog)

CSeconDlg::CSeconDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSeconDlg::IDD, pParent)
{

}

CSeconDlg::~CSeconDlg()
{
}

void CSeconDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Path);
}


BEGIN_MESSAGE_MAP(CSeconDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CSeconDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_BK, &CSeconDlg::OnBnClickedButtonBk)
END_MESSAGE_MAP()


// CSeconDlg ��Ϣ�������

void CSeconDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		_T("All Files(*.*)|*.*||"),AfxGetMainWnd());//�����ļ��򿪶Ի���
	CString strPath;
	if(dlg.DoModal()==IDOK)
	{
	  strPath=dlg.GetPathName();
	  m_Path.SetWindowText(strPath);
	
	}
  // MessageBox(_TEXT("aa"));
   
}

void CSeconDlg::OnBnClickedButtonBk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
    OnCancel();
}
