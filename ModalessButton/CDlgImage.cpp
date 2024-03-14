// CDlgImage.cpp : implementation file
//

#include "pch.h"
#include "ModalessButton.h"
#include "afxdialogex.h"
#include "CDlgImage.h"
#include "ModalessButtonDlg.h"

// CDlgImage dialog

IMPLEMENT_DYNAMIC(CDlgImage, CDialogEx)

CDlgImage::CDlgImage(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CDlgImage, pParent)
{
	m_pParent = pParent;
}

CDlgImage::~CDlgImage()
{
}

void CDlgImage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgImage, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_PARENT, &CDlgImage::OnBnClickedBtnParent)
END_MESSAGE_MAP()


// CDlgImage message handlers


void CDlgImage::OnBnClickedBtnParent()
{
	// TODO: Add your control notification handler code here
	static int n = 100;
	CModalessButtonDlg* pDlg = (CModalessButtonDlg*) m_pParent;
	pDlg->CallFunc(n++);
}
