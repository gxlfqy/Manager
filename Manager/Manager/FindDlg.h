#pragma once
#include "afxmenubutton.h"
#include "EasyStaticCtrlConnect.h"
#include "afxvslistbox.h"

// CFindDlg 对话框

struct _FindInfo
{
	CString title;
	CString data;
	int IDName;
};



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
	std::vector<tag_ef_connect> * ControlInfo;
	std::vector<_FindInfo> m_FindInfo;
	CMenu * m_pFineMenu;
	void SetControlInfo(std::vector<tag_ef_connect> * _controlInfo);
	afx_msg void OnBnClickedMfcmenu1();
	void InitMenuInfo();
	void OnlyAgreeNo(int nID);
	void BanInputMethod(int nID);
	CVSListBox m_ListBoxCtrl;
};
