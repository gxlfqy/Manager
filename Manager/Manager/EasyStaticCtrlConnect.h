#pragma once
#ifndef __EASYSTATICCTRLCONNECT_H__
#define __EASYSTATICCTRLCONNECT_H__
#include "stdafx.h"
#include "DynamicMenu.h"

#include <vector>
#include <iostream>
#include <assert.h>

#define ES_ONLYINPUTNO 0x4000L
#define ES_NOINTABLE 0x8000L

namespace ControlType
{
	enum C
	{
		Edit = 1,
		ComboBox,
		DateTimePicker,
		MFCMenuButtonControl
	};
	enum D
	{
		NONE = 0,
		BASICINFO = 1,
		CTCHECK,
		PNR,
		OLD,
		EXCHECK,
		SURGERY,
		PATHOLOGY,
		IMMUNOHISTOCHEMISTRY,
		GENETIC,
		FOLLOW_UP_RECORDS
	};
}

struct tag_dataType
{
	CString TableID[10];
	CString TableName[10];
	tag_dataType()
	{
		TableName[0] = L"患者基本信息";
		TableID[0] = L"BASICINFO";
		TableName[1] = L"CT检查";
		TableID[1] = L"CTCHECK";
		TableName[2] = L"肺结节记录";
		TableID[2] = L"PNR";
		TableName[3] = L"肺部其他发现";
		TableID[3] = L"OLD";
		TableName[4] = L"胸部其他检查";
		TableID[4] = L"EXCHECK";
		TableName[5] = L"外科手术";
		TableID[5] = L"SURGERY";
		TableName[6] = L"病理结果";
		TableID[6] = L"PATHOLOGY";
		TableName[7] = L"免疫组化";
		TableID[7] = L"IMMUNOHISTOCHEMISTRY";
		TableName[8] = L"基因检测";
		TableID[8] = L"GENETIC";
		TableName[9] = L"随访记录";
		TableID[9] = L"FOLLOW_UP_RECORDS";
	}
	CString operator[](int _i)const
	{
		return TableID[_i];
	}
	int GetTableIndex(CString str)
	{
		int len = 0;
		CString temp;
		CString term;
		for (int i = 0; i < 10; ++i)
		{
			temp = (*this)[i];
			len = temp.GetLength();
			term = str.Mid(0, len);
			if (temp == term)
				return i;
		}
		return -1;
	}
};

extern struct tag_dataType g_DataType;

struct tag_ef_connect
{
	int staticID = 0;
	CString title;
	int ctrlID = 0;
	int ctrlName;
	CString IDName;
	int attr = 0;
	std::vector<CString> MenuInfo;
	int nTable = 0;
	HMENU hMenu = NULL;
	CDynamicMenu * MFCMenuInfo = nullptr;
	tag_ef_connect() { }
	tag_ef_connect(int _staticID, int _ctrlID, int _ctrlName) :staticID(_staticID), ctrlID(_ctrlID), ctrlName(_ctrlName) { }
	void SetData(int _staticID, int _ctrlID, int _ctrlName){ staticID = _staticID, ctrlID = _ctrlID, ctrlName = _ctrlName; }
	void SetTitle(CString _title){ title = _title; }
	void SetAttr(int _attr){ attr = _attr; }
};

//EasyStaticCtrlConnect 类的迭代器
class Iterator
{
private:
	int Iterator_index;
public:
	Iterator() :Iterator_index(0)
	{

	}
};

class EasyStaticCtrlConnect
{
private:
	EasyStaticCtrlConnect()
	{
		m_StaticCtrlList.clear();
	}
	EasyStaticCtrlConnect(const EasyStaticCtrlConnect &){ }
	EasyStaticCtrlConnect & operator = (const EasyStaticCtrlConnect &);
	static tag_dataType m_TableInfo;
	std::vector<tag_ef_connect> m_StaticCtrlList;
public:
	friend class ManagerDlg;
	static EasyStaticCtrlConnect & GetInstance()
	{
		static EasyStaticCtrlConnect instance;
		return instance;
	}
	static tag_dataType GetTableData()
	{
		return m_TableInfo;
	}
private:
	void AddSub(tag_ef_connect staticCtrlInfo)
	{
		m_StaticCtrlList.push_back(staticCtrlInfo);
	}
public:
	tag_ef_connect GetAt(int index)
	{
		return m_StaticCtrlList.at(index);
	}
};

#define CREATE_EASYSTATICCTRLCONNECT struct tag_dataType g_DataType;

#define DECLARE_EASYSTATICCTRLCONNECT \
	std::vector<tag_ef_connect> __EF__StaticCtrl; \
	void __EF__ConnectStaticCtrl(); \
	void __EF__UpdateControlPosition(bool bFlag);

#define BEGIN_EASYSTATICCTRLCONNECT_MAP(class) \
	void class::__EF__UpdateControlPosition(bool bFlag) \
	{ \
		static std::vector<int> StaticCtrlDistance; \
		CRect StaticRect, ControlRect; \
		int nCountor = __EF__StaticCtrl.size(); \
		if (bFlag) \
		{ \
			for (int i = 0; i < nCountor; ++i) \
			{ \
				GetDlgItem(__EF__StaticCtrl.at(i).staticID)->GetWindowRect(StaticRect); \
				GetDlgItem(__EF__StaticCtrl.at(i).ctrlID)->GetWindowRect(ControlRect); \
				StaticCtrlDistance.push_back(ControlRect.left - StaticRect.left); \
			} \
		} \
		else \
		{ \
			int wide = 0; \
			for (int i = 0; i < nCountor; ++i) \
			{ \
				GetDlgItem(__EF__StaticCtrl.at(i).staticID)->GetWindowRect(StaticRect); \
				ScreenToClient(StaticRect); \
				GetDlgItem(__EF__StaticCtrl.at(i).ctrlID)->GetWindowRect(ControlRect); \
				ScreenToClient(ControlRect); \
				wide = StaticRect.right - StaticRect.left; \
				StaticRect.left = ControlRect.left - StaticCtrlDistance.at(i); \
				StaticRect.right = StaticRect.left + wide; \
				GetDlgItem(__EF__StaticCtrl.at(i).staticID)->MoveWindow(StaticRect.left, StaticRect.top, StaticRect.right - StaticRect.left, StaticRect.bottom - StaticRect.top, FALSE); \
			} \
		} \
		Invalidate(); \
		UpdateWindow(); \
	} \
	void class::__EF__ConnectStaticCtrl() \
	{ \
		tag_ef_connect temp; \
		CString str; \
		int nCount; \

#define ESCC_CONNECT(staticID, ctrlID, ctrlName, attribute) \
		temp.SetData(staticID, ctrlID, ctrlName); \
		temp.IDName.Format(L""##L#ctrlID); \
		temp.IDName = temp.IDName.Mid(4, temp.IDName.GetLength()); \
		GetDlgItem(staticID)->GetWindowText(str); \
		str.TrimRight(_T("：")); \
		temp.SetTitle(str); \
		temp.MenuInfo.clear(); \
		temp.hMenu = NULL; \
		if (ctrlName == ControlType::ComboBox) \
		{ \
			nCount = ((CComboBox *)GetDlgItem(ctrlID))->GetCount(); \
			for (int i = 0; i < nCount; ++i) \
			{ \
				((CComboBox *)GetDlgItem(ctrlID))->GetLBText(i, str); \
				temp.MenuInfo.push_back(str); \
			} \
		} \
		if (ctrlName == ControlType::MFCMenuButtonControl) \
		{ \
			temp.hMenu = HMENU(attribute); \
			temp.SetAttr(0); \
		} \
		else \
		{ \
			temp.SetAttr(int(attribute)); \
		} \
		if (temp.attr != ES_NOINTABLE) \
			temp.nTable = g_DataType.GetTableIndex(temp.IDName); \
		else \
			temp.nTable = 0; \
		assert(temp.nTable != -1); \
		__EF__StaticCtrl.push_back(temp);

#define END_EASYSTATICCTRLCONNECT_MAP \
	}

#define ESCC_CONNECT_MFCMENU(staticID, ctrlID, ctrlName, DMenuInfo, o)  \
		temp.SetData(staticID, ctrlID, ctrlName); \
		temp.IDName.Format(L""##L#ctrlID); \
		temp.IDName = temp.IDName.Mid(4, temp.IDName.GetLength()); \
		GetDlgItem(staticID)->GetWindowText(str); \
		str.TrimRight(_T("：")); \
		temp.SetTitle(str); \
		temp.MenuInfo.clear(); \
		temp.hMenu = NULL; \
		temp.MFCMenuInfo = new CDynamicMenu; \
		if (temp.MFCMenuInfo == nullptr) exit(1); \
		*(temp.MFCMenuInfo) = DMenuInfo; \
		temp.hMenu = temp.MFCMenuInfo->m_hDMenu; \
		if (o == ES_NOINTABLE) \
			temp.nTable = 0; \
		else \
			temp.nTable = g_DataType.GetTableIndex(temp.IDName); \
		assert(temp.nTable != -1); \
		__EF__StaticCtrl.push_back(temp);
	 
#define CONNECTSTATICCTRL __EF__ConnectStaticCtrl();__EF__UpdateControlPosition(TRUE)

#define UPDATECONTROLPOSITION __EF__UpdateControlPosition(FALSE)

#endif // !__EASYSTATICCTRLCONNECT_H__

