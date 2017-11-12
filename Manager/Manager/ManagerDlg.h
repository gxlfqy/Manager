
// ManagerDlg.h : ͷ�ļ�
//

#pragma once
#include "EasySize.h"
#include "afxmenubutton.h"
#include "EasyStaticCtrlConnect.h"
#include "DynamicMenu.h"
#include "MyMFCMenuButton.h"


// CManagerDlg �Ի���
class CManagerDlg : public CDialogEx
{
	//DECLARE_EASYSIZE
// ����
public:
	CManagerDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MANAGER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	DECLARE_EASYSTATICCTRLCONNECT
	// ��ʼ���ٰ����������Ϣ
	void InitAdenocarcinomaTree();
	//��ʼ����ʼ������
	void initScrollbar();
	afx_msg void OnNMClickTree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	void RestoreGroup();
	POINT old;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
	CMyMFCMenuButton m_ADEMenuBottomCtrl;
	afx_msg void OnConditionQueryMenu();
	CMyMFCMenuButton m_GLANDMenuBottomCtrl;
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