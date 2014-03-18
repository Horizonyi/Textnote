#pragma once
#include "afxwin.h"


// CSeconDlg 对话框

class CSeconDlg : public CDialog
{
	DECLARE_DYNAMIC(CSeconDlg)

public:
	CSeconDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSeconDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_SECO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
public:
	CEdit m_Path;
public:
	afx_msg void OnBnClickedButtonBk();
};
