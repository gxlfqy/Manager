// PatientDirectoryDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Manager.h"
#include "PatientDirectoryDlg.h"
#include "afxdialogex.h"


// CPatientDirectoryDlg �Ի���

IMPLEMENT_DYNAMIC(CPatientDirectoryDlg, CDialogEx)

CPatientDirectoryDlg::CPatientDirectoryDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPatientDirectoryDlg::IDD, pParent)
{

}

CPatientDirectoryDlg::~CPatientDirectoryDlg()
{
}

void CPatientDirectoryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPatientDirectoryDlg, CDialogEx)
	ON_NOTIFY(HDN_ITEMDBLCLICK, 0, &CPatientDirectoryDlg::OnHdnItemdblclickList1)
END_MESSAGE_MAP()


// CPatientDirectoryDlg ��Ϣ�������


void CPatientDirectoryDlg::OnHdnItemdblclickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMHEADER phdr = reinterpret_cast<LPNMHEADER>(pNMHDR);

	*pResult = 0;
}
