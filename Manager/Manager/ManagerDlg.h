
// ManagerDlg.h : ͷ�ļ�
//

#pragma once
#include "EasySize.h"
#include "afxmenubutton.h"
#include "EasyStaticCtrlConnect.h"

// CManagerDlg �Ի���
class CManagerDlg : public CDialogEx
{
	DECLARE_EASYSIZE
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
	DECLARE_EASYSTATICCTRLCONNECT
public:
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
	CMFCMenuButton m_menuBottomCtrl;
	afx_msg void OnConditionQueryMenu();
	CMFCMenuButton m_MFCMenuGlandCtrl;
	afx_msg void OnOutputDataid();
};
