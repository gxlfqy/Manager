// PathologyDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Manager.h"
#include "PathologyDlg.h"
#include "afxdialogex.h"


// CPathologyDlg �Ի���

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
	DDX_Control(pDX, IDC_MFCMENUBUTTON1, m_menuBottomCtrl);
}


void CPathologyDlg::InitAdenocarcinomaTree()
{
	CTreeCtrl * pTreeCtrl = (CTreeCtrl *)GetDlgItem(IDC_TREE1);
	HTREEITEM T001 = pTreeCtrl->InsertItem(_T("����ǰ����"));
	HTREEITEM T011 = pTreeCtrl->InsertItem(_T("�ǵ�������������"), T001);
	HTREEITEM T012 = pTreeCtrl->InsertItem(_T("ԭλ�ٰ�"), T001);
	HTREEITEM T121 = pTreeCtrl->InsertItem(_T("���Һ��"), T012);
	HTREEITEM T122 = pTreeCtrl->InsertItem(_T("�Һ��"), T012);
	HTREEITEM T123 = pTreeCtrl->InsertItem(_T("�����"), T012);
	HTREEITEM T002 = pTreeCtrl->InsertItem(_T("΢�����ٰ�"));
	pTreeCtrl->InsertItem(_T("���Һ��"), T002);
	pTreeCtrl->InsertItem(_T("�Һ��"), T002);
	pTreeCtrl->InsertItem(_T("�����"), T002);
	HTREEITEM T3 = pTreeCtrl->InsertItem(_T("�������ٰ�"));
	pTreeCtrl->InsertItem(_T("��������Ϊ��"), T3);
	pTreeCtrl->InsertItem(_T("����Ϊ��"), T3);
	pTreeCtrl->InsertItem(_T("��ͷ״"), T3);
	pTreeCtrl->InsertItem(_T("΢С��ͷΪ��"), T3);
	pTreeCtrl->InsertItem(_T("ʵ��Ϊ����ճҺ���׷���"), T3);
	HTREEITEM T4 = pTreeCtrl->InsertItem(_T("�����Ա���"));
	pTreeCtrl->InsertItem(_T("�Һ��"), T4);
	pTreeCtrl->InsertItem(_T("������"), T4);
	pTreeCtrl->InsertItem(_T("̥����"), T4);
	pTreeCtrl->InsertItem(_T("���ٰ�"), T4);
}

BEGIN_MESSAGE_MAP(CPathologyDlg, CDialogEx)
	ON_BN_CLICKED(IDC_MFCMENUBUTTON1, &CPathologyDlg::OnBnClickedMfcmenubutton1)
END_MESSAGE_MAP()


// CPathologyDlg ��Ϣ�������


BOOL CPathologyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//��ʼ�� �ٰ���
	//InitAdenocarcinomaTree();
	CMenu* pMenu = new CMenu;
	pMenu->LoadMenu(IDR_MENU2); //����˵���Դ
	m_menuBottomCtrl.m_hMenu = pMenu->GetSubMenu(0)->GetSafeHmenu();
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CPathologyDlg::OnBnClickedMfcmenubutton1()
{
	if (m_menuBottomCtrl.m_nMenuResult == 0)
		return;

	CString m_szAde;
	CMenu * pMenu = new CMenu;
	pMenu->LoadMenu(IDR_MENU2);
	pMenu->GetSubMenu(0)->GetMenuStringW(m_menuBottomCtrl.m_nMenuResult, m_szAde, MF_BYCOMMAND);
	SetDlgItemText(IDC_MFCMENUBUTTON_STATIC, m_szAde);
}
