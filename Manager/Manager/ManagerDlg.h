
// ManagerDlg.h : ͷ�ļ�
//

#pragma once


// CManagerDlg �Ի���
class CManagerDlg : public CDialogEx
{
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
	// ��ʼ���ٰ����������Ϣ
	void InitAdenocarcinomaTree();
	afx_msg void OnNMClickTree1(NMHDR *pNMHDR, LRESULT *pResult);
};
