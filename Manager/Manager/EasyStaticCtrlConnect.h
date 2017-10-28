#pragma once
#ifndef __EASYSTATICCTRLCONNECT_H__
#define __EASYSTATICCTRLCONNECT_H__
#include "stdafx.h"
#include "EasySize.h"

#include <vector>
#include <iostream>

struct tag_menuInfo
{
	CString data;
	std::vector<tag_menuInfo> * sub = nullptr;
	tag_menuInfo(CString _val) :data(_val){  }
	~tag_menuInfo()
	{
		if (sub != nullptr)
		{
			delete sub;
			sub = nullptr;
		}
	}
	void SetMenuInfo(CString str){ data = str; }
	std::vector<tag_menuInfo> * GetSubMenu(){ return sub; }
};

struct tag_ef_connect
{
	int staticID = 0;
	CString title;
	int ctrlID = 0;
	CString ctrlName;
	CString IDName;
	int attr = 0;
	std::vector<tag_menuInfo> MenuInfo;
	tag_ef_connect() { }
	tag_ef_connect(int _staticID, int _ctrlID, CString _ctrlName) :staticID(_staticID), ctrlID(_ctrlID), ctrlName(_ctrlName) { }
	void SetData(int _staticID, int _ctrlID, CString _ctrlName){ staticID = _staticID, ctrlID = _ctrlID, ctrlName = _ctrlName; }
	void SetTitle(CString _title){ title = _title; }
	void SetAttr(int _attr){ attr = _attr; }
};

#define DECLARE_EASYSTATICCTRLCONNECT \
	std::vector<tag_ef_connect> __EF__StaticCtrl; \
	void __EF__ConnectStaticCtrl();

#define BEGIN_EASYSTATICCTRLCONNECT_MAP(class) \
	void class::__EF__ConnectStaticCtrl() \
{ \
	tag_ef_connect temp; \
	CString str; \
	int nCount;

#define ESCC_CONNECT(staticID, ctrlID, ctrlName, attribute) \
	temp.SetData(staticID, ctrlID, (LPCTSTR)ctrlName); \
	temp.IDName = ""#ctrlID; \
	temp.IDName.TrimLeft(_T("IDC_")); \
	temp.SetAttr(attribute); \
	GetDlgItem(staticID)->GetWindowText(str); \
	str.TrimRight(_T("£º")); \
	temp.SetTitle(str); \
	__EF__StaticCtrl.push_back(temp);

#define END_EASYSTATICCTRLCONNECT_MAP \
}

#define CONNECTSTATICCTRL __EF__ConnectStaticCtrl()

#endif // !__EASYSTATICCTRLCONNECT_H__

// 	if (ctrlName == "Combo_Box") \
	{ \
	nCount = ((CComboBox *)GetDlgItem(ctrlID))->GetCount(); \
	for (int i = 0; i < nCount; ++i) \
	{ \
	((CComboBox *)GetDlgItem(IDC_BASICINFO_SEX))->GetLBText(i, str); \
	temp.MenuInfo.push_back(str); \
	} \
	} \
	else if (ctrlName == "MFC_MenuButton_Control") \
	{ \
	if () \
	} \