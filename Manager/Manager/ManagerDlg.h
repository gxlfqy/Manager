
// ManagerDlg.h : 头文件
//

#pragma once
#include "EasySize.h"
#include "afxmenubutton.h"
#include "EasyStaticCtrlConnect.h"

// CManagerDlg 对话框
class CManagerDlg : public CDialogEx
{
	DECLARE_EASYSIZE
// 构造
public:
	CManagerDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MANAGER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	DECLARE_EASYSTATICCTRLCONNECT
public:
	// 初始化腺癌树的相关信息
	void InitAdenocarcinomaTree();
	//初始化初始滚动条
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
