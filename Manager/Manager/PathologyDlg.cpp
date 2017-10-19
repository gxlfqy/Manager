// PathologyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Manager.h"
#include "PathologyDlg.h"
#include "afxdialogex.h"


// CPathologyDlg 对话框

IMPLEMENT_DYNAMIC(CPathologyDlg, CDialogEx)

CPathologyDlg::CPathologyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPathologyDlg::IDD, pParent)
{

}

CPathologyDlg::~CPathologyDlg()
{
}

void CPathologyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


void CPathologyDlg::InitAdenocarcinomaTree()
{
	CTreeCtrl * pTreeCtrl = (CTreeCtrl *)GetDlgItem(IDC_TREE1);
	HTREEITEM T001 = pTreeCtrl->InsertItem(_T("浸润前病变"));
	HTREEITEM T011 = pTreeCtrl->InsertItem(_T("非典型腺瘤样增生"), T001);
	HTREEITEM T012 = pTreeCtrl->InsertItem(_T("原位腺癌"), T001);
	HTREEITEM T121 = pTreeCtrl->InsertItem(_T("非黏液性"), T012);
	HTREEITEM T122 = pTreeCtrl->InsertItem(_T("黏液性"), T012);
	HTREEITEM T123 = pTreeCtrl->InsertItem(_T("混合性"), T012);
	HTREEITEM T002 = pTreeCtrl->InsertItem(_T("微浸润腺癌"));
	pTreeCtrl->InsertItem(_T("非黏液性"), T002);
	pTreeCtrl->InsertItem(_T("黏液性"), T002);
	pTreeCtrl->InsertItem(_T("混合性"), T002);
	HTREEITEM T3 = pTreeCtrl->InsertItem(_T("浸润性腺癌"));
	pTreeCtrl->InsertItem(_T("伏壁生长为主"), T3);
	pTreeCtrl->InsertItem(_T("腺泡为主"), T3);
	pTreeCtrl->InsertItem(_T("乳头状"), T3);
	pTreeCtrl->InsertItem(_T("微小乳头为主"), T3);
	pTreeCtrl->InsertItem(_T("实体为主伴粘液蛋白分泌"), T3);
	HTREEITEM T4 = pTreeCtrl->InsertItem(_T("浸润性变异"));
	pTreeCtrl->InsertItem(_T("黏液性"), T4);
	pTreeCtrl->InsertItem(_T("胶质样"), T4);
	pTreeCtrl->InsertItem(_T("胎儿型"), T4);
	pTreeCtrl->InsertItem(_T("肠腺癌"), T4);
}

BEGIN_MESSAGE_MAP(CPathologyDlg, CDialogEx)
END_MESSAGE_MAP()


// CPathologyDlg 消息处理程序


BOOL CPathologyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//初始化 腺癌树
	InitAdenocarcinomaTree();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
