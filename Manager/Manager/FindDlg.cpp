// FindDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Manager.h"
#include "FindDlg.h"
#include "afxdialogex.h"


// CFindDlg 对话框

IMPLEMENT_DYNAMIC(CFindDlg, CDialogEx)

CFindDlg::CFindDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFindDlg::IDD, pParent)
{
}

CFindDlg::~CFindDlg()
{
}

void CFindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCMENU1, m_MFCMenu1Ctrl);
	DDX_Control(pDX, IDC_MFCMENU2, m_MFCMenu2Ctrl);
}


BEGIN_MESSAGE_MAP(CFindDlg, CDialogEx)
	ON_BN_CLICKED(IDC_MFCMENU1, &CFindDlg::OnBnClickedMfcmenu1)
END_MESSAGE_MAP()


// CFindDlg 消息处理程序


BOOL CFindDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CMenu * pMenu1 = new CMenu;
	pMenu1->LoadMenu(IDR_MENU2);
	m_MFCMenu1Ctrl.m_hMenu = pMenu1->GetSubMenu(1)->GetSafeHmenu();
	CMenu * pMenu2 = new CMenu;
	//m_MFCMenu2Ctrl.m_hMenu = pMenu2->GetSubMenu(0)->GetSafeHmenu();
// 	CONTROL_ID(IDC_MFCMENU2);
// 	CONTROL_ID(IDC_TIME1);
// 	CONTROL_ID(IDC_TIME2);
// 	CONTROL_ID(IDC_COMBO);
// 	CONTROL_ID(IDC_EDIT1);
// 	CONTROL_ID(IDC_FOUND_STATIC);
// 	CONTROL_ID(IDC_EDIT2);
// 	EF_HIDEALL;
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}

// BEGIN_EASYFOUND_MAP(CFindDlg)
// 	EF_SHOW(0, {IDC})
// 	EF_INITSHOW(IDC_EDIT1)
// END_EASYFOUND_MAP

void CFindDlg::OnBnClickedMfcmenu1()
{
//	EF_UPDATE(m_MFCMenu1Ctrl.m_nMenuResult);
	CMenu menu;
}
