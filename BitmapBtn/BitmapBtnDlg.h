
// BitmapBtnDlg.h : header file
//

#pragma once


// CBitmapBtnDlg dialog
class CBitmapBtnDlg : public CDialogEx
{
// Construction
public:
	CBitmapBtnDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BITMAPBTN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

//Custom Data
private:
	CBitmapButton* m_pBtnOnOff;

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
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedBtnOnOff();

private:
	void InitButtons();
};
