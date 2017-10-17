
// ManagerDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Manager.h"
#include "ManagerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CManagerDlg 对话框



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


// CManagerDlg 消息处理程序

BOOL CManagerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	InitAdenocarcinomaTree();
	initScrollbar();
	//MoveWindow()

	//////////////////////////////////////////////////////////////////////////
	CRect rect;
	GetClientRect(&rect);     //取客户区大小    
	old.x = rect.right - rect.left;
	old.y = rect.bottom - rect.top;
	//////////////////////////////////////////////////////////////////////////

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CManagerDlg::OnPaint()
{
	CRect   rect;
	CPaintDC   dc(this);
	GetClientRect(rect);
	dc.FillSolidRect(rect, RGB(199, 237, 204));   //设置为绿色背景

	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);

	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CManagerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 初始化腺癌树的相关信息
void CManagerDlg::InitAdenocarcinomaTree()
{
	CTreeCtrl * pTreeCtrl = (CTreeCtrl *)GetDlgItem(IDC_TREE1);
	HTREEITEM T001 = pTreeCtrl->InsertItem(_T("浸润前病变"));
	HTREEITEM T011 = pTreeCtrl->InsertItem(_T("非典型腺瘤样增生"), T001);
	HTREEITEM T012 = pTreeCtrl->InsertItem(_T("原位腺癌"), T001);
	HTREEITEM T121 = pTreeCtrl->InsertItem(_T("非黏液性"), T012);
	HTREEITEM T122 = pTreeCtrl->InsertItem(_T("黏液性"), T012);
	HTREEITEM T123 = pTreeCtrl->InsertItem(_T("混合性"), T012);
	HTREEITEM T002 = pTreeCtrl->InsertItem(_T("微浸润腺癌"));
	pTreeCtrl->InsertItem(_T("非黏液性"), T002);
	pTreeCtrl->InsertItem(_T("黏液性"), T002);
	pTreeCtrl->InsertItem(_T("混合性"), T002);
	HTREEITEM T3 = pTreeCtrl->InsertItem(_T("浸润性腺癌"));
	pTreeCtrl->InsertItem(_T("伏壁生长为主"), T3);
	pTreeCtrl->InsertItem(_T("腺泡为主"), T3);
	pTreeCtrl->InsertItem(_T("乳头状"), T3);
	pTreeCtrl->InsertItem(_T("微小乳头为主"), T3);
	pTreeCtrl->InsertItem(_T("实体为主伴粘液蛋白分泌"), T3);
	HTREEITEM T4 = pTreeCtrl->InsertItem(_T("浸润性变异"));
	pTreeCtrl->InsertItem(_T("黏液性"), T4);
	pTreeCtrl->InsertItem(_T("胶质样"), T4);
	pTreeCtrl->InsertItem(_T("胎儿型"), T4);
	pTreeCtrl->InsertItem(_T("肠腺癌"), T4);
}


void CManagerDlg::initScrollbar()
{
	SCROLLINFO scrollinfo;
	GetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
	scrollinfo.nPage = 10;    //设置滑块大小
	scrollinfo.nMax = 75;     //设置滚动条的最大位置0--75
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
	// TODO:  在此添加消息处理程序代码和/或调用默认值
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
		if (scrollinfo.nPos + scrollinfo.nPage>scrollinfo.nMax)  //此处一定要注意加上滑块的长度，再作判断
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
		if (scrollinfo.nPos + scrollinfo.nPage >= scrollinfo.nMax)  //此处一定要注意加上滑块的长度，再作判断
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
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CRect rc;
	CDC dcMem;
	GetClientRect(&rc);
	CBitmap bmp; //内存中承载临时图象的位图


	dcMem.CreateCompatibleDC(pDC); //依附窗口DC创建兼容内存DC
	//创建兼容位图(必须用pDC创建，否则画出的图形变成黑色)
	bmp.CreateCompatibleBitmap(pDC, rc.Width(), rc.Height());
	CBitmap *pOldBit = dcMem.SelectObject(&bmp);
	//按原来背景填充客户区，不然会是黑色
	dcMem.FillSolidRect(rc, RGB(255, 255, 255));

	//画图，添加你要画图的代码，不过用dcMem画，而不是pDC

	pDC->BitBlt(0, 0, rc.Width(), rc.Height(), &dcMem, 0, 0, SRCCOPY);

	//将内存DC上的图象拷贝到前台
	//绘图完成后的清理
	dcMem.DeleteDC();		//删除DC
	bmp.DeleteObject();		//删除位图
	return true;
	//这里一定要用return true，如果用自动生成的，会调用基类，把画出来的覆盖，就什     么结果也没有了

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
	POINT Newp; //获取现在对话框的大小  
	CRect recta;
	GetClientRect(&recta);     //取客户区大小    
	Newp.x = recta.right - recta.left;
	Newp.y = recta.bottom - recta.top;
	fsp[0] = (float)Newp.x / old.x;
	fsp[1] = (float)Newp.y / old.y;
	CRect Rect;
	int woc;
	CPoint OldTLPoint, TLPoint; //左上角  
	CPoint OldBRPoint, BRPoint; //右下角  
	HWND  hwndChild = ::GetWindow(m_hWnd, GW_CHILD);  //列出所有控件 
	bool isExID = false;
	int i;
	while (hwndChild)
	{
		woc = ::GetDlgCtrlID(hwndChild);//取得ID
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
// 	if (change_flag)//如果OninitDlg已经调用完毕  
// 	{
// 		MyReSize(IDC_STATIC);
// 		m_Multiple_width = float(1) / m_Multiple_width;
// 		m_Multiple_height = float(1) / m_Multiple_height;
// 	}
}
