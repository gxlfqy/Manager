#pragma once


// CPathologyDlg 对话框

class CPathologyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPathologyDlg)

public:
	CPathologyDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPathologyDlg();

// 对话框数据
	enum { IDD = IDD_PATHOLOGY_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	void InitAdenocarcinomaTree();
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
