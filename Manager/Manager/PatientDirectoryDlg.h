#pragma once


// CPatientDirectoryDlg �Ի���

class CPatientDirectoryDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPatientDirectoryDlg)

public:
	CPatientDirectoryDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPatientDirectoryDlg();

// �Ի�������
	enum { IDD = IDD_PATIENT_DIRECTORY_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnHdnItemdblclickList1(NMHDR *pNMHDR, LRESULT *pResult);
};
