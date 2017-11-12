#pragma once
#include "afxwin.h"
#include "BinaryTree.h"

struct _menuInfo
{
	CString title;
	int nID = 0;
};

class CDynamicMenu
{
public:
	CBinaryTree<_menuInfo> m_menuInfobTree;
	HMENU m_hDMenu;
public:
	CDynamicMenu();
	~CDynamicMenu();
	virtual void CreateDynamicMenu();
	CString GetTreeString(int nID, CString connect)const;
private:
	HMENU buildMenu();
};

