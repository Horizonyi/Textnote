// LYY1Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"

#include "SeconDlg.h"
//#if_MSG_VER > 1000

// CLYY1Dlg �Ի���
class CLYY1Dlg : public CDialog
{
// ����
public:
	CLYY1Dlg(CWnd* pParent = NULL);	// ��׼���캯��
	CSeconDlg dlg;

// �Ի�������
	enum { IDD = IDD_LYY1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
    

	// ���ɵ���Ϣӳ�亯��
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
