// BasicInfoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Manager.h"
#include "BasicInfoDlg.h"
#include "afxdialogex.h"


// CBasicInfoDlg 对话框

IMPLEMENT_DYNAMIC(CBasicInfoDlg, CDialogEx)

CBasicInfoDlg::CBasicInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBasicInfoDlg::IDD, pParent)
{

}

CBasicInfoDlg::~CBasicInfoDlg()
{
}

void CBasicInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CBasicInfoDlg, CDialogEx)
END_MESSAGE_MAP()


// CBasicInfoDlg 消息处理程序
