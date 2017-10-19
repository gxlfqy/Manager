// BodyCheckDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Manager.h"
#include "BodyCheckDlg.h"
#include "afxdialogex.h"


// CBodyCheckDlg 对话框

IMPLEMENT_DYNAMIC(CBodyCheckDlg, CDialogEx)

CBodyCheckDlg::CBodyCheckDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBodyCheckDlg::IDD, pParent)
{

}

CBodyCheckDlg::~CBodyCheckDlg()
{
}

void CBodyCheckDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CBodyCheckDlg, CDialogEx)
END_MESSAGE_MAP()


// CBodyCheckDlg 消息处理程序
