
// Manager.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "Manager.h"
#include "ManagerDlg.h"
#include "FindDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "BinaryTree.h"

// CManagerApp

BEGIN_MESSAGE_MAP(CManagerApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CManagerApp ����

CManagerApp::CManagerApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO:  �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CManagerApp ����

CManagerApp theApp;

void TestTemplate()
{
	CBinaryTree<CString> BTree(L"���꣬�ж�");
	BTree.Right();
	BTree.Set(L"�Բ�");
	const CString * temp = BTree.Get();
	return;
}

// CManagerApp ��ʼ��

BOOL CManagerApp::InitInstance()
{
#if defined(_SKIN_)
	skinppLoadSkin(_T("avfone.ssk"));
#endif
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()��  ���򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ���Windows Native���Ӿ����������Ա��� MFC �ؼ�����������
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO:  Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));
	//TestTemplate();
	CManagerDlg dlg;
	INT_PTR nResponse;
	//goto End;
	m_pMainWnd = &dlg;
	nResponse = dlg.DoModal();
// 	CBasicInfoDlg dlg1;
// 	INT_PTR nResponse = dlg1.DoModal();
// 	CBodyCheckDlg dlg2;
// 	nResponse = dlg2.DoModal();
// 	CPathologyDlg dlg3;
// 	nResponse = dlg3.DoModal();
	nResponse = IDOK;
	if (nResponse == IDOK)
	{
		// TODO:  �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO:  �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "����: �Ի��򴴽�ʧ�ܣ�Ӧ�ó���������ֹ��\n");
		TRACE(traceAppMsg, 0, "����: ������ڶԻ�����ʹ�� MFC �ؼ������޷� #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS��\n");
	}

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}



int CManagerApp::ExitInstance()
{
	// TODO:  �ڴ����ר�ô����/����û���
#if defined(_SKIN_)
	skinppExitSkin();
#endif

	return CWinApp::ExitInstance();
}
