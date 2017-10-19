#pragma once


// CBodyCheckDlg 对话框

class CBodyCheckDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBodyCheckDlg)

public:
	CBodyCheckDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CBodyCheckDlg();

// 对话框数据
	enum { IDD = IDD_BODYCHECK_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
