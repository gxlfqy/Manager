// DataIDDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Manager.h"
#include "DataIDDlg.h"
#include "afxdialogex.h"


// CDataIDDlg �Ի���

IMPLEMENT_DYNAMIC(CDataIDDlg, CDialogEx)

CDataIDDlg::CDataIDDlg(CWnd* pParent /*=NULL*/)
: CDialogEx(CDataIDDlg::IDD, pParent), __EF__StaticCtrl(nullptr)
{

}

CDataIDDlg::~CDataIDDlg()
{
}

void CDataIDDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listCtrl);
}


BEGIN_MESSAGE_MAP(CDataIDDlg, CDialogEx)
	ON_BN_CLICKED(IDC_OUTTXT, &CDataIDDlg::OnBnClickedOuttxt)
	ON_WM_HOTKEY()
END_MESSAGE_MAP()

void CDataIDDlg::SetDataID(std::vector<tag_ef_connect> * _list)
{
	__EF__StaticCtrl = _list;
}

// CDataIDDlg ��Ϣ�������


BOOL CDataIDDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	::RegisterHotKey(GetSafeHwnd(), IDC_OUTTXT, MOD_ALT, 'O');
	CString IDTitle;
	CString IDName;
	for (int i = 0; i < __EF__StaticCtrl->size(); ++i)
	{
		IDTitle = __EF__StaticCtrl->at(i).title;
		IDName = __EF__StaticCtrl->at(i).IDName;
		m_listCtrl.AddString(_T("IDTitle�� \t") + IDTitle);
		m_listCtrl.AddString(_T("IDName��\t\t") + IDName);
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CDataIDDlg::OnBnClickedOuttxt()
{
	int nCount = 0;
	nCount = m_listCtrl.GetCount();
	CStdioFile file(_T("out.txt"), CStdioFile::modeWrite);
	CString str;
	for (int i = 0; i < nCount; ++i)
	{
		m_listCtrl.GetText(i, str);
		str += "\n";
		file.WriteString(str);
	}
	file.Close();
}


void CDataIDDlg::OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	switch (nHotKeyId)
	{
	case IDC_OUTTXT:
		OnBnClickedOuttxt();
		break;
	default:
		break;
	}
	CDialogEx::OnHotKey(nHotKeyId, nKey1, nKey2);
}

void CDataIDDlg::OnOK()
{
	// TODO:  �ڴ����ר�ô����/����û���

	//CDialogEx::OnOK();
}
