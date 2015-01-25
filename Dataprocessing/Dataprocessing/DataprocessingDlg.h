
// DataprocessingDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CDataprocessingDlg dialog
class CDataprocessingDlg : public CDialogEx
{
// Construction
public:
	CDataprocessingDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_DATAPROCESSING_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBq1();
	CEdit m_QOIn;
	CStatic m_QOOut;
	afx_msg void OnBnClickedBq2();
	afx_msg void OnBnClickedBq4();
	afx_msg void OnBnClickedBq6();
	afx_msg void OnBnClickedBq3();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedBq5();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedBq7();
	afx_msg void OnBnClickedBq8();
	afx_msg void OnBnClickedBq9();
	afx_msg void OnBnClickedBq10();
	afx_msg void OnBnClickedBq11();
	afx_msg void OnBnClickedBq12();
	afx_msg void OnBnClickedBq12show();
};
