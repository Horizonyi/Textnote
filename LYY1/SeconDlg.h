#pragma once
#include "afxwin.h"


// CSeconDlg �Ի���

class CSeconDlg : public CDialog
{
	DECLARE_DYNAMIC(CSeconDlg)

public:
	CSeconDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSeconDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_SECO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
public:
	CEdit m_Path;
public:
	afx_msg void OnBnClickedButtonBk();
};
