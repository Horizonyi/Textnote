// LYY1Dlg.h : 头文件
//

#pragma once
#include "afxcmn.h"

#include "SeconDlg.h"
//#if_MSG_VER > 1000

// CLYY1Dlg 对话框
class CLYY1Dlg : public CDialog
{
// 构造
public:
	CLYY1Dlg(CWnd* pParent = NULL);	// 标准构造函数
	CSeconDlg dlg;

// 对话框数据
	enum { IDD = IDD_LYY1_DIALOG };

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
	afx_msg void OnBnClickedButtonYs();
public:
	CRichEditCtrl m_RichEdit;
public:
	afx_msg void OnBnClickedCancel();
public:
	afx_msg void OnBnClickedOk();
public:
	afx_msg void OnBnClickedButtonRead();
public:
	afx_msg void OnBnClickedButtonSave();

};
