#pragma once


// CPathologyDlg �Ի���

class CPathologyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPathologyDlg)

public:
	CPathologyDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPathologyDlg();

// �Ի�������
	enum { IDD = IDD_PATHOLOGY_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	void InitAdenocarcinomaTree();
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
