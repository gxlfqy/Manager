
// ManagerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Manager.h"
#include "ManagerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CManagerDlg �Ի���



CManagerDlg::CManagerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CManagerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CManagerDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_CLICK, IDC_TREE1, &CManagerDlg::OnNMClickTree1)
	ON_WM_VSCROLL()
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CManagerDlg ��Ϣ�������

BOOL CManagerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	InitAdenocarcinomaTree();
	initScrollbar();
	//MoveWindow()

	//////////////////////////////////////////////////////////////////////////
	CRect rect;
	GetClientRect(&rect);     //ȡ�ͻ�����С    
	old.x = rect.right - rect.left;
	old.y = rect.bottom - rect.top;
	//////////////////////////////////////////////////////////////////////////

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CManagerDlg::OnPaint()
{
	CRect   rect;
	CPaintDC   dc(this);
	GetClientRect(rect);
	dc.FillSolidRect(rect, RGB(199, 237, 204));   //����Ϊ��ɫ����

	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);

	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CManagerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// ��ʼ���ٰ����������Ϣ
void CManagerDlg::InitAdenocarcinomaTree()
{
	CTreeCtrl * pTreeCtrl = (CTreeCtrl *)GetDlgItem(IDC_TREE1);
	HTREEITEM T001 = pTreeCtrl->InsertItem(_T("����ǰ����"));
	HTREEITEM T011 = pTreeCtrl->InsertItem(_T("�ǵ�������������"), T001);
	HTREEITEM T012 = pTreeCtrl->InsertItem(_T("ԭλ�ٰ�"), T001);
	HTREEITEM T121 = pTreeCtrl->InsertItem(_T("���Һ��"), T012);
	HTREEITEM T122 = pTreeCtrl->InsertItem(_T("�Һ��"), T012);
	HTREEITEM T123 = pTreeCtrl->InsertItem(_T("�����"), T012);
	HTREEITEM T002 = pTreeCtrl->InsertItem(_T("΢�����ٰ�"));
	pTreeCtrl->InsertItem(_T("���Һ��"), T002);
	pTreeCtrl->InsertItem(_T("�Һ��"), T002);
	pTreeCtrl->InsertItem(_T("�����"), T002);
	HTREEITEM T3 = pTreeCtrl->InsertItem(_T("�������ٰ�"));
	pTreeCtrl->InsertItem(_T("��������Ϊ��"), T3);
	pTreeCtrl->InsertItem(_T("����Ϊ��"), T3);
	pTreeCtrl->InsertItem(_T("��ͷ״"), T3);
	pTreeCtrl->InsertItem(_T("΢С��ͷΪ��"), T3);
	pTreeCtrl->InsertItem(_T("ʵ��Ϊ����ճҺ���׷���"), T3);
	HTREEITEM T4 = pTreeCtrl->InsertItem(_T("�����Ա���"));
	pTreeCtrl->InsertItem(_T("�Һ��"), T4);
	pTreeCtrl->InsertItem(_T("������"), T4);
	pTreeCtrl->InsertItem(_T("̥����"), T4);
	pTreeCtrl->InsertItem(_T("���ٰ�"), T4);
}


void CManagerDlg::initScrollbar()
{
	SCROLLINFO scrollinfo;
	GetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
	scrollinfo.nPage = 10;    //���û����С
	scrollinfo.nMax = 75;     //���ù����������λ��0--75
	SetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
}

void CManagerDlg::OnNMClickTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	*pResult = 0;
	CTreeCtrl * pTreeCtrl = (CTreeCtrl *)GetDlgItem(IDC_TREE1);
	pTreeCtrl->GetSelectedItem();
}


void CManagerDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	SCROLLINFO scrollinfo;
	GetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
	int unit = 6;
	switch (nSBCode)
	{
	case SB_LINEUP:          //Scroll one line up
		scrollinfo.nPos -= 1;
		if (scrollinfo.nPos<scrollinfo.nMin)
		{
			scrollinfo.nPos = scrollinfo.nMin;
			break;
		}
		SetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
		ScrollWindow(0, unit);
		break;
	case SB_LINEDOWN:           //Scroll one line down
		scrollinfo.nPos += 1;
		if (scrollinfo.nPos + scrollinfo.nPage>scrollinfo.nMax)  //�˴�һ��Ҫע����ϻ���ĳ��ȣ������ж�
		{
			scrollinfo.nPos = scrollinfo.nMax;
			break;
		}
		SetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
		ScrollWindow(0, -unit);
		break;
	case SB_PAGEUP:            //Scroll one page up.
		scrollinfo.nPos -= 5;
		if (scrollinfo.nPos <= scrollinfo.nMin)
		{
			scrollinfo.nPos = scrollinfo.nMin;
			break;
		}
		SetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
		ScrollWindow(0, unit * 5);
		break;
	case SB_PAGEDOWN:        //Scroll one page down        
		scrollinfo.nPos += 5;
		if (scrollinfo.nPos + scrollinfo.nPage >= scrollinfo.nMax)  //�˴�һ��Ҫע����ϻ���ĳ��ȣ������ж�
		{
			scrollinfo.nPos = scrollinfo.nMax;
			break;
		}
		SetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
		ScrollWindow(0, -unit * 5);
		break;
	case SB_ENDSCROLL:      //End scroll     
		break;
	case SB_THUMBPOSITION:  //Scroll to the absolute position. The current position is provided in nPos
		break;
	case SB_THUMBTRACK:                  //Drag scroll box to specified position. The current position is provided in nPos
		ScrollWindow(0, (scrollinfo.nPos - nPos)*unit);
		scrollinfo.nPos = nPos;
		SetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
		break;
	}

	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}


BOOL CManagerDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CRect rc;
	CDC dcMem;
	GetClientRect(&rc);
	CBitmap bmp; //�ڴ��г�����ʱͼ���λͼ


	dcMem.CreateCompatibleDC(pDC); //��������DC���������ڴ�DC
	//��������λͼ(������pDC���������򻭳���ͼ�α�ɺ�ɫ)
	bmp.CreateCompatibleBitmap(pDC, rc.Width(), rc.Height());
	CBitmap *pOldBit = dcMem.SelectObject(&bmp);
	//��ԭ���������ͻ�������Ȼ���Ǻ�ɫ
	dcMem.FillSolidRect(rc, RGB(255, 255, 255));

	//��ͼ�������Ҫ��ͼ�Ĵ��룬������dcMem����������pDC

	pDC->BitBlt(0, 0, rc.Width(), rc.Height(), &dcMem, 0, 0, SRCCOPY);

	//���ڴ�DC�ϵ�ͼ�󿽱���ǰ̨
	//��ͼ��ɺ������
	dcMem.DeleteDC();		//ɾ��DC
	bmp.DeleteObject();		//ɾ��λͼ
	return true;
	//����һ��Ҫ��return true��������Զ����ɵģ�����û��࣬�ѻ������ĸ��ǣ���ʲ     ô���Ҳû����

	//return CDialogEx::OnEraseBkgnd(pDC);
}


void CManagerDlg::ReSize()
{
	float fsp[2];
	int ExID[13];
	ExID[0] = IDC_BASEINFO_STATIC;
	ExID[1] = IDC_CTCHECK_STATIC;
	ExID[2] = IDC_PNR_STATIC;
	ExID[3] = IDC_OLD_STATIC;
	ExID[4] = IDC_CHEST_EXAMINATION_STATIC;
	ExID[5] = IDC_SURGERY_STATIC;
	ExID[6] = IDC_PATHOLOGY_RESULTS_STATIC;
	ExID[7] = IDC_PATHOLOGY_ADENOCARCINOMA_STATIC;
	ExID[8] = IDC_PATHOLOGY_ISOI_STATIC;
	ExID[9] = IDC_PATHOLOGY_FOUNDIFNO_STATIC;
	ExID[10] = IDC_IMMUNOHISTOCHEMISTRY_STATIC;
	ExID[11] = IDC_GENETIC_TESTING_STATIC;
	ExID[12] = IDC_FOLLOW_UP_RECORDS_STATIC;
	POINT Newp; //��ȡ���ڶԻ���Ĵ�С  
	CRect recta;
	GetClientRect(&recta);     //ȡ�ͻ�����С    
	Newp.x = recta.right - recta.left;
	Newp.y = recta.bottom - recta.top;
	fsp[0] = (float)Newp.x / old.x;
	fsp[1] = (float)Newp.y / old.y;
	CRect Rect;
	int woc;
	CPoint OldTLPoint, TLPoint; //���Ͻ�  
	CPoint OldBRPoint, BRPoint; //���½�  
	HWND  hwndChild = ::GetWindow(m_hWnd, GW_CHILD);  //�г����пؼ� 
	bool isExID = false;
	int i;
	while (hwndChild)
	{
		woc = ::GetDlgCtrlID(hwndChild);//ȡ��ID
		for (i = 0, isExID = false; i < 13; ++i)
		{
			if (woc == ExID[i])
			{
				isExID = true;
				break;
			}
		}
		GetDlgItem(woc)->GetWindowRect(Rect);
		ScreenToClient(Rect);
		OldTLPoint = Rect.TopLeft();
		TLPoint.x = long(OldTLPoint.x*fsp[0]);
		TLPoint.y = long(OldTLPoint.y*fsp[1]);
		OldBRPoint = Rect.BottomRight();
		BRPoint.x = long(OldBRPoint.x *fsp[0]);
		//BRPoint.y = long(OldBRPoint.y *fsp[1]);
		if (isExID)
			BRPoint.y = long(OldBRPoint.y *fsp[1]);
		else
			BRPoint.y = long(TLPoint.y + OldBRPoint.y - OldTLPoint.y);
		Rect.SetRect(TLPoint, BRPoint);
		GetDlgItem(woc)->MoveWindow(Rect, TRUE);
		hwndChild = ::GetWindow(hwndChild, GW_HWNDNEXT);
	}
	old = Newp;
}

void CManagerDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here  
	if (nType == SIZE_RESTORED || nType == SIZE_MAXIMIZED)
	{
		ReSize();
	}
// 	if (change_flag)//���OninitDlg�Ѿ��������  
// 	{
// 		MyReSize(IDC_STATIC);
// 		m_Multiple_width = float(1) / m_Multiple_width;
// 		m_Multiple_height = float(1) / m_Multiple_height;
// 	}
}
