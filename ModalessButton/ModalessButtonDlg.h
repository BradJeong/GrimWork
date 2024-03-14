
// ModalessButtonDlg.h : header file
//

#include "CDlgImage.h"
#pragma once


// CModalessButtonDlg dialog
class CModalessButtonDlg : public CDialogEx
{
// Construction
public:
	CModalessButtonDlg(CWnd* pParent = nullptr);	// standard constructor
	
	CDlgImage* m_pDlgImage;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MODALESSBUTTON_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnDlg();
	afx_msg void OnDestroy();

	void CallFunc(int n);
};
