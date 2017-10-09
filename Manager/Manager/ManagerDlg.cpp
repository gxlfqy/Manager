
// ManagerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Manager.h"
#include "ManagerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CManagerDlg �Ի���



CManagerDlg::CManagerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CManagerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CManagerDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_CLICK, IDC_TREE1, &CManagerDlg::OnNMClickTree1)
END_MESSAGE_MAP()


// CManagerDlg ��Ϣ�������

BOOL CManagerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	InitAdenocarcinomaTree();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CManagerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CManagerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// ��ʼ���ٰ����������Ϣ
void CManagerDlg::InitAdenocarcinomaTree()
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


void CManagerDlg::OnNMClickTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	*pResult = 0;
	CTreeCtrl * pTreeCtrl = (CTreeCtrl *)GetDlgItem(IDC_TREE1);
	pTreeCtrl->GetSelectedItem();
}
