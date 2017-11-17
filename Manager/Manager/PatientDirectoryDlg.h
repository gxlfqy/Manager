#pragma once


// CPatientDirectoryDlg 对话框

class CPatientDirectoryDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPatientDirectoryDlg)

public:
	CPatientDirectoryDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPatientDirectoryDlg();

// 对话框数据
	enum { IDD = IDD_PATIENT_DIRECTORY_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnHdnItemdblclickList1(NMHDR *pNMHDR, LRESULT *pResult);
};
