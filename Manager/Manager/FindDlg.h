#pragma once
#include "afxmenubutton.h"
#include "EasyFound.h"


// CFindDlg �Ի���

class CFindDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFindDlg)

public:
	CFindDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFindDlg();

// �Ի�������
	enum { IDD = IDD_FOUND_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	/*DECLARE_EASYFOUND*/
	virtual BOOL OnInitDialog();
	CMFCMenuButton m_MFCMenu1Ctrl;
	CMFCMenuButton m_MFCMenu2Ctrl;

	afx_msg void OnBnClickedMfcmenu1();
};
