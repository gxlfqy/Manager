// FindDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Manager.h"
#include "ManagerDlg.h"
#include "FindDlg.h"
#include "afxdialogex.h"
#include <imm.h>

// CFindDlg 对话框

IMPLEMENT_DYNAMIC(CFindDlg, CDialogEx)

CFindDlg::CFindDlg(CWnd* pParent /*=NULL*/)
: CDialogEx(CFindDlg::IDD, pParent), m_pFineMenu(nullptr)
{

}

CFindDlg::~CFindDlg()
{
}

void CFindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCMENU1, m_OptionsMenuCtrl);
	DDX_Control(pDX, IDC_MFCMENU2, m_MFCMenu2Ctrl);
	DDX_Control(pDX, IDC_FOUND_LIST, m_FoundListCtrl);
}


BEGIN_MESSAGE_MAP(CFindDlg, CDialogEx)
	ON_BN_CLICKED(IDC_MFCMENU1, &CFindDlg::OnBnClickedMfcmenu1)
END_MESSAGE_MAP()


// CFindDlg 消息处理程序


BOOL CFindDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	InitOptionsMenu();
	m_OptionsMenuCtrl.m_hMenu = m_pFineMenu->GetSubMenu(0)->GetSafeHmenu();
	BanInputMethod(IDC_BIM_EDIT);
	OnlyAgreeNo(IDC_BIM_EDIT);
	DWORD Style = m_FoundListCtrl.GetExtendedStyle();
	Style |= LVS_EX_FULLROWSELECT;
	Style |= LVS_EX_GRIDLINES;
	m_FoundListCtrl.SetExtendedStyle(Style);
	m_FoundListCtrl.InsertColumn(0, L"筛选条件", LVCFMT_LEFT, 180);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}

void CFindDlg::SetControlInfo(std::vector<tag_ef_connect> * _controlInfo)
{
	ControlInfo = _controlInfo;
}

void CFindDlg::OnBnClickedMfcmenu1()
{
	int MenuRet = m_OptionsMenuCtrl.m_nMenuResult;
	if (MenuRet == 0)
		return;
	int nCountor = ControlInfo->size();
	int i;
	for (i = 0; i < nCountor; ++i)
	{
		if (MenuRet == ControlInfo->at(i).ctrlID)
		{
			SetDlgItemText(IDC_MFCMENU1, ControlInfo->at(i).title);
			goto Next;
		}
	}
	assert(0);
	return;
Next:
	GetDlgItem(IDC_MFCMENU2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TIME1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMBO)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BIM_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_NUMBER_EDIT)->ShowWindow(SW_HIDE);
	int j;
	//Reset the content of the control
	((CComboBox *)GetDlgItem(IDC_COMBO))->ResetContent();
	SetDlgItemText(IDC_EDIT1, L"");
	SetDlgItemText(IDC_BIM_EDIT, L"");
	SetDlgItemText(IDC_NUMBER_EDIT, L"");
	//Show the control in the order
	int ControlInfo_i_MenuInfo_len = 0;
	switch (ControlInfo->at(i).ctrlName)
	{
	case ControlType::Edit:
		switch (ControlInfo->at(i).attr)
		{
		case ES_ONLYINPUTNO:
			GetDlgItem(IDC_BIM_EDIT)->ShowWindow(SW_SHOW);
			break;
		case ES_NUMBER:
			GetDlgItem(IDC_NUMBER_EDIT)->ShowWindow(SW_SHOW);
			break;
		case 0:
			GetDlgItem(IDC_EDIT)->ShowWindow(SW_SHOW);
			break;
		}
		break;
	case ControlType::ComboBox:
		ControlInfo_i_MenuInfo_len = ControlInfo->at(i).MenuInfo.size();
		for (j = 0; j < ControlInfo_i_MenuInfo_len; ++j)
			((CComboBox *)GetDlgItem(IDC_COMBO))->InsertString(j, ControlInfo->at(i).MenuInfo.at(j));
		GetDlgItem(IDC_COMBO)->ShowWindow(SW_SHOW);
		break;
	case ControlType::DateTimePicker:
		GetDlgItem(IDC_TIME1)->ShowWindow(SW_SHOW);
		break;
	case ControlType::MFCMenuButtonControl:
		GetDlgItem(IDC_MFCMENU2)->ShowWindow(SW_SHOW);
		m_MFCMenu2Ctrl.m_hMenu = ControlInfo->at(i).hMenu;
		break;
	}
	return;
}

void CFindDlg::InitOptionsMenu()
{
	CMenu * pMenu = new CMenu;
	CMenu * pP = new CMenu;
	CMenu * pPopupMenu = new CMenu[10];
	pP->CreatePopupMenu();
	pMenu->CreateMenu();
	pMenu->AppendMenu(MF_POPUP, (UINT)pP->m_hMenu, L"Find");
	int i;
	for (i = 0; i < 10; ++i)
	{
		(pPopupMenu[i]).CreatePopupMenu();
		pP->AppendMenu(MF_POPUP, (UINT)(pPopupMenu[i]).m_hMenu, g_DataType.TableName[i]);
	}
	int nCountor = ControlInfo->size();
	for (i = 0; i < nCountor; ++i)
		(pPopupMenu[ControlInfo->at(i).nTable]).AppendMenu(MF_STRING, ControlInfo->at(i).ctrlID, ControlInfo->at(i).title);
	m_pFineMenu = pMenu;
// 	CBinaryTree<_menuInfo> * menuInfoBTree = &m_OptionsMenuCtrl.m_menuInfobTree;
// 	menuInfoBTree->Root();
// 	void * menuInfoBTree_mark = nullptr;
// 	_menuInfo term;
// 	int i = 0;
// 	for (i = 1; i <= 10; ++i)
// 	{
// 		term.title = g_DataType.TableName[i];
// 		term.nID = i + 1;
// 		menuInfoBTree->Set(term);
// 		menuInfoBTree->Left();
// 	}
}

void CFindDlg::OnlyAgreeNo(int nID)
{
	EC_OnlyAgreeNo(nID);
}

void CFindDlg::BanInputMethod(int nID)
{
	EC_BanInputMethod(nID);
}