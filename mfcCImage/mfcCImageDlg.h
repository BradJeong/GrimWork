
// mfcCImageDlg.h : header file
//

#pragma once


// CmfcCImageDlg dialog
class CmfcCImageDlg : public CDialogEx
{
//Custom Data
private:
	CImage m_Image;

// Construction
public:
	CmfcCImageDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCCIMAGE_DIALOG };
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
	afx_msg void OnBnClickedBtnImg();
	afx_msg void OnBnClickedBtnAct();
	afx_msg void OnBnClickedBtnSave();
	afx_msg void OnBnClickedBtnLoad();


private:
	// Funtions
	void DrawCircle(unsigned char* fm, int x, int y, int nRadius, int nGray);
	bool IsInCircle(int x, int y, int nCenterX, int nCenterY, int nRadius);
	BOOL ValidImgPos(int x, int y);
	void UpdateDisplay();
	void MoveRect();
};
