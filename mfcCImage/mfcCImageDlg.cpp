
// mfcCImageDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "mfcCImage.h"
#include "mfcCImageDlg.h"
#include "afxdialogex.h"
#include <future>
#include <thread>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CmfcCImageDlg dialog



CmfcCImageDlg::CmfcCImageDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCCIMAGE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmfcCImageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CmfcCImageDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_IMG, &CmfcCImageDlg::OnBnClickedBtnImg)
	ON_BN_CLICKED(IDC_BTN_ACT, &CmfcCImageDlg::OnBnClickedBtnAct)
	ON_BN_CLICKED(IDC_BTN_SAVE, &CmfcCImageDlg::OnBnClickedBtnSave)
	ON_BN_CLICKED(IDC_BTN_LOAD, &CmfcCImageDlg::OnBnClickedBtnLoad)
END_MESSAGE_MAP()


// CmfcCImageDlg message handlers

BOOL CmfcCImageDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CmfcCImageDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CmfcCImageDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CmfcCImageDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CmfcCImageDlg::OnBnClickedBtnImg()
{
	if (m_Image != NULL) {
		m_Image.Destroy();
	}

	int nWidth = 640;
	int nHeight = 480;
	int nBpp = 8;
	m_Image.Create(nWidth, -nHeight, nBpp);
	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++) {
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		}
		m_Image.SetColorTable(0, 256, rgb);
	}
	int nPitch = m_Image.GetPitch();
	unsigned char* fm = (unsigned char*)m_Image.GetBits();

	memset(fm, 0xff, (nWidth * nHeight));

	// Test Drawing
	//for (int j = 0; j < nHeight; j++) {
	//	for (int i = 0; i < nWidth; i++) {
	//		fm[j * nPitch + i] = (j % 0xff);
	//	}
	//}
	//for (int j = 0; j < nHeight/2; j++) {
	//	for (int i = 0; i < nWidth/2; i++) {
	//		fm[j * nPitch + i] = 200;
	//	}
	//}

	UpdateDisplay();
}


void CmfcCImageDlg::OnBnClickedBtnAct()
{
	int nWidth = m_Image.GetWidth();
	int nHeight = m_Image.GetHeight();
	unsigned char* fm = (unsigned char*)m_Image.GetBits();
	memset(fm, 0xff, (nWidth * nHeight));

	for(int i = 0; i < 300; i++)
	{
		MoveRect();
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}


void CmfcCImageDlg::OnBnClickedBtnSave()
{
	static TCHAR BASED_CODE szFilter[] = _T("이미지 파일(*.BMP, *.GIF, *.JPG) | *.BMP;*.GIF;*.JPG;*.bmp;*.jpg;*.gif |모든파일(*.*)|*.*||");
	CFileDialog fileDlg(FALSE, _T("*.jpg"), _T("image"), OFN_HIDEREADONLY, szFilter);
	if (fileDlg.DoModal() == IDOK)
	{
		CString pathName = fileDlg.GetPathName();

		m_Image.Save(pathName);
		MessageBox(pathName, _T("Message"));
	}
}


void CmfcCImageDlg::OnBnClickedBtnLoad()
{
	if (m_Image != NULL) {
		m_Image.Destroy();
	}

	static TCHAR BASED_CODE szFilter[] = _T("이미지 파일(*.BMP, *.GIF, *.JPG) | *.BMP;*.GIF;*.JPG;*.bmp;*.jpg;*.gif |모든파일(*.*)|*.*||");
	CFileDialog dlg(TRUE, _T("*.jpg"), _T("image"), OFN_HIDEREADONLY, szFilter);
	if (IDOK == dlg.DoModal())
	{
		CString pathName = dlg.GetPathName();

		m_Image.Load(pathName);
		MessageBox(pathName, _T("Message"));

		UpdateDisplay();
	}
}



//
//Functions
//
void CmfcCImageDlg::MoveRect()
{
	static int nSttX = 0;
	static int nSttY = 0;
	int nGray = 80;
	int nWidth = m_Image.GetWidth();
	int nHeight = m_Image.GetHeight();
	int nPitch = m_Image.GetPitch();
	int nRadius = 10;

	unsigned char* fm = (unsigned char*)m_Image.GetBits();

	// remove the previous.
	//memset(fm, 0xff, nWidth * nHeight);
	DrawCircle(fm, nSttX, nSttY, nRadius, 0xff);

	// draw circle.
	DrawCircle(fm, ++nSttX, ++nSttY, nRadius, nGray);

	UpdateDisplay();


	//CString strFile;
	//strFile.Format(_T("C:\\Images\\Image_%d.jpg"), nSttX);
	//m_Image.Save(strFile);
	// 
	//TCHAR currentDir[MAX_PATH];
	//GetCurrentDirectory(MAX_PATH, currentDir);
	//CString strFile;
	//strFile.Format(_T("%s\\Image_%d.jpg"), currentDir);
	//m_Image.Save(strFile);
}

void CmfcCImageDlg::UpdateDisplay()
{
	CClientDC dc(this);
	m_Image.Draw(dc, 0, 0);
}

void CmfcCImageDlg::DrawCircle(unsigned char* fm, int x, int y, int nRadius, int nGray)
{
	int nCenterX = x + nRadius;
	int nCenterY = y + nRadius;
	int nPitch = m_Image.GetPitch();

	for (int j = y; j < (y + nRadius * 2); j++) {
		for (int i = x; i < (x + nRadius * 2); i++) {
			if (IsInCircle(i, j, nCenterX, nCenterY, nRadius)) {
				fm[j * nPitch + i] = nGray;
			}
		}
	}
}

bool CmfcCImageDlg::IsInCircle(int x, int y, int nCenterX, int nCenterY, int nRadius)
{
	bool bRet = false;

	double dX = x - nCenterX;
	double dY = y - nCenterY;
	double dDist = (dX * dX) + (dY * dY);

	if (dDist < nRadius * nRadius) {
		bRet = true;
	}

	return bRet;
}

BOOL CmfcCImageDlg::ValidImgPos(int x, int y)
{
	int nWidth = m_Image.GetWidth();
	int nHeight = m_Image.GetHeight();
	CRect rect(0, 0, nWidth, nHeight);

	return rect.PtInRect(CPoint(x, y));
}
