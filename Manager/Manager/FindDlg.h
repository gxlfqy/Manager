#pragma once
#include "afxmenubutton.h"
#include "EasyFound.h"


// CFindDlg 对话框

class CFindDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFindDlg)

public:
	CFindDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CFindDlg();

// 对话框数据
	enum { IDD = IDD_FOUND_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	/*DECLARE_EASYFOUND*/
	virtual BOOL OnInitDialog();
	CMFCMenuButton m_MFCMenu1Ctrl;
	CMFCMenuButton m_MFCMenu2Ctrl;

	afx_msg void OnBnClickedMfcmenu1();
};
