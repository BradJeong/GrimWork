#pragma once
#include "afxdialogex.h"


// CDlgImage dialog

class CDlgImage : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgImage)

public:
	CDlgImage(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDlgImage();

	CWnd* m_pParent;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CDlgImage };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnParent();
};
