#pragma once
#include "afxmenubutton.h"
#include "EasyStaticCtrlConnect.h"
#include "MyMFCMenuButton.h"
#include "afxvslistbox.h"
#include "afxcmn.h"

// CFindDlg �Ի���

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
	CFindDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFindDlg();

// �Ի�������
	enum { IDD = IDD_FOUND_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CMyMFCMenuButton m_OptionsMenuCtrl;
	CMyMFCMenuButton m_MFCMenu2Ctrl;
	std::vector<tag_ef_connect> * ControlInfo;
	std::vector<_FindInfo> m_FindInfo;
	CMenu * m_pFineMenu;
	CListCtrl m_FoundListCtrl;
public:
	/*DECLARE_EASYFOUND*/
	virtual BOOL OnInitDialog();
	
	void SetControlInfo(std::vector<tag_ef_connect> * _controlInfo);
	afx_msg void OnBnClickedMfcmenu1();
	void InitOptionsMenu();
	void OnlyAgreeNo(int nID);
	void BanInputMethod(int nID);
	
};
