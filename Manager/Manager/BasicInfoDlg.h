#pragma once


// CBasicInfoDlg �Ի���

class CBasicInfoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBasicInfoDlg)

public:
	CBasicInfoDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CBasicInfoDlg();

// �Ի�������
	enum { IDD = IDD_BASICINFO_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
