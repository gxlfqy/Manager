#pragma once


// CBodyCheckDlg �Ի���

class CBodyCheckDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBodyCheckDlg)

public:
	CBodyCheckDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CBodyCheckDlg();

// �Ի�������
	enum { IDD = IDD_BODYCHECK_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
