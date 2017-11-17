
// ManagerDlg.h : 头文件
//

#pragma once
#include "Manager.h"
#include "EasySize.h"
#include "afxmenubutton.h"
#include "EasyStaticCtrlConnect.h"
#include "DynamicMenu.h"
#include "MyMFCMenuButton.h"
#include <imm.h>
#include <stack>

typedef struct ManagerData
{
	CString data;
	CString title;
	CString IDName;
}manadata;

// CManagerDlg 对话框
class CManagerDlg : public CDialogEx
{
	//DECLARE_EASYSIZE
// 构造
public:
	CManagerDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MANAGER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
public:
	HICON m_hIcon; 
	POINT old;
	CMyMFCMenuButton m_ADEMenuBottomCtrl;
	CMyMFCMenuButton m_GLANDMenuBottomCtrl;
	std::vector<manadata> m_ManagerData;
// 实现
protected:
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	DECLARE_EASYSTATICCTRLCONNECT
	// 初始化腺癌树的相关信息
	void InitAdenocarcinomaTree();
	//初始化初始滚动条
	void initScrollbar();
	afx_msg void OnNMClickTree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	void RestoreGroup();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
	afx_msg void OnConditionQueryMenu();
	afx_msg void OnOutputDataid();
	afx_msg void OnBnClickedPathologyMfcmenubutton();
	void InitADEMenuBottomCtrl();
	void InitGLANDMenuBottomCtrl();
	afx_msg void OnBnClickedSurgeryGland();
	void BanInputMethod(int nID);
	afx_msg void OnEnChangeCtcheckCtno();
	void OnlyAgreeNo(int nID);
	afx_msg void OnEnChangePathologyNo();
	afx_msg void OnEnChangeFollowUpRecordsCtNo();
	afx_msg void OnSavedataMenu();
	afx_msg void OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2);
};

#define EC_OnlyAgreeNo(id) \
	CString temp; \
	static CString record = L""; \
	GetDlgItemText(nID, temp); \
	int temp_len = temp.GetLength(); \
	wchar_t c; \
	int n; \
	for (int i = 0; i < temp_len; ++i) \
	{ \
		c = temp.GetAt(i); \
		n = int(c); \
		if (n > 256 || !isdigit(c) && !isalpha(c)) \
		{ \
			SetDlgItemText(IDC_CTCHECK_CTNO, record); \
			((CEdit *)GetDlgItem(IDC_CTCHECK_CTNO))->SetSel(record.GetLength(), record.GetLength(), TRUE); \
			return; \
		} \
	} \
	record = temp

#define EC_BanInputMethod(id) \
	HWND hWnd = GetDlgItem(nID)->m_hWnd; \
	if (hWnd && IsWindow(hWnd)) \
	{ \
		HIMC m_hImc = ImmGetContext(hWnd); \
		if (m_hImc) \
			ImmAssociateContext(hWnd, NULL); \
		ImmReleaseContext(hWnd, m_hImc); \
		::SetFocus(hWnd); \
	}

