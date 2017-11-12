// FindDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Manager.h"
#include "ManagerDlg.h"
#include "FindDlg.h"
#include "afxdialogex.h"
#include <imm.h>

// CFindDlg �Ի���

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
	DDX_Control(pDX, IDC_MFCMENU1, m_MFCMenu1Ctrl);
	DDX_Control(pDX, IDC_MFCMENU2, m_MFCMenu2Ctrl);
	DDX_Control(pDX, IDC_MFCVSLISTBOX1, m_ListBoxCtrl);
}


BEGIN_MESSAGE_MAP(CFindDlg, CDialogEx)
	ON_BN_CLICKED(IDC_MFCMENU1, &CFindDlg::OnBnClickedMfcmenu1)
END_MESSAGE_MAP()


// CFindDlg ��Ϣ�������


BOOL CFindDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	InitMenuInfo();
	m_MFCMenu1Ctrl.m_hMenu = m_pFineMenu->GetSubMenu(0)->GetSafeHmenu();
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}

void CFindDlg::SetControlInfo(std::vector<tag_ef_connect> * _controlInfo)
{
	ControlInfo = _controlInfo;
}

void CFindDlg::OnBnClickedMfcmenu1()
{
	int MenuRet = m_MFCMenu1Ctrl.m_nMenuResult;
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
	GetDlgItem(IDC_EDIT1)->ShowWindow(SW_HIDE);
	int j;
	//Reset the content of the control
	((CComboBox *)GetDlgItem(IDC_COMBO))->ResetContent();
	SetDlgItemText(IDC_EDIT1, L"");
	//Show the control in the order
	switch (ControlInfo->at(i).ctrlName)
	{
	case ControlType::Edit:
		GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);
		break;
	case ControlType::ComboBox:
		for (j = 0; j < ControlInfo->at(i).MenuInfo.size(); ++j)
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

void CFindDlg::InitMenuInfo()
{
	CMenu * pMenu = new CMenu;
	CMenu * pP = new CMenu;
	CMenu * pPopupMenu = new CMenu[10];
	pP->CreatePopupMenu();
	pMenu->CreateMenu();
	pMenu->AppendMenu(MF_POPUP, (UINT)pP->m_hMenu, L"Find");
	int i;
	for (i = 0; i < 10; ++i)
		(pPopupMenu[i]).CreatePopupMenu();
	int nCountor = ControlInfo->size();
	for (i = 0; i < nCountor; ++i)
		(pPopupMenu[ControlInfo->at(i).nTable]).AppendMenu(MF_STRING, ControlInfo->at(i).ctrlID, ControlInfo->at(i).title);
	for (i = 0; i < 10; ++i)
		pP->AppendMenu(MF_POPUP, (UINT)(pPopupMenu[i]).m_hMenu, g_DataType.TableName[i]);
	m_pFineMenu = pMenu;
}

void CFindDlg::OnlyAgreeNo(int nID)
{
	EC_OnlyAgreeNo(nID);
}

void CFindDlg::BanInputMethod(int nID)
{
	EC_BanInputMethod(nID);
}