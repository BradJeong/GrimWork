
// BitmapBtnDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "BitmapBtn.h"
#include "BitmapBtnDlg.h"
#include "afxdialogex.h"

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


// CBitmapBtnDlg dialog



CBitmapBtnDlg::CBitmapBtnDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BITMAPBTN_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBitmapBtnDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CBitmapBtnDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_ERASEBKGND()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_ON_OFF, &CBitmapBtnDlg::OnBnClickedBtnOnOff)
	ON_WM_GETMINMAXINFO()
END_MESSAGE_MAP()


// CBitmapBtnDlg message handlers

BOOL CBitmapBtnDlg::OnInitDialog()
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
	// 동적 레이아웃 설정.
	//SetupForDynamicLayout();
	//GetWindowRect(&m_rect);
	//CalcWindowRect(m_rect);

	//Initialize Image Button
	InitButtons();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBitmapBtnDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CBitmapBtnDlg::OnPaint()
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
HCURSOR CBitmapBtnDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



BOOL CBitmapBtnDlg::OnEraseBkgnd(CDC* pDC)
{
	CDialogEx::OnEraseBkgnd(pDC);

	CPngImage bgdImg;
	bgdImg.Load(IDB_BASE, nullptr);
	CRect rect;
	this->GetClientRect(&rect);

	CDC dc;
	dc.CreateCompatibleDC(pDC);
	CBitmap* pOldBitmap = dc.SelectObject(&bgdImg);
	pDC->BitBlt(0, 0, rect.Width(), rect.Height()
			, &dc, 0, 0, SRCCOPY);
	dc.SelectObject(pOldBitmap);
	return TRUE;
}
void CBitmapBtnDlg::InitButtons()
{
	//m_rect.SetRect(0, 0, 100, 50);
	CRect rect(0, 0, 100, 50);
	GetDlgItem(IDC_BTN_ON_OFF)->GetWindowRect(&rect);
	//GetDlgItem(IDC_BTN_ON_OFF)->GetClientRect(&rect);
	m_pBtnOnOff = new CBitmapButton;
	m_pBtnOnOff->Create(NULL, WS_CHILD | WS_VISIBLE | BS_OWNERDRAW, rect, this, IDC_BTN_ON_OFF);
	m_pBtnOnOff->LoadBitmaps(IDB_ON, IDB_OFF);
	m_pBtnOnOff->SizeToContent();
}


void CBitmapBtnDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: Add your message handler code here
	//m_pBtnOnOff->DestroyWindow();
	if (m_pBtnOnOff) 
		delete m_pBtnOnOff;
}


void CBitmapBtnDlg::OnBnClickedBtnOnOff()
{
	// Toggle Switch
	static bool bOn = false;
	if (bOn) {
		m_pBtnOnOff->LoadBitmaps(IDB_ON);
	}
	else {
		m_pBtnOnOff->LoadBitmaps(IDB_OFF);
	}
	bOn = !bOn;
}

