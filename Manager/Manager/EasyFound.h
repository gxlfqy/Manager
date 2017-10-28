#pragma once
#ifndef __EASYOFOUND_H__
#define __EASYOFOUND_H__
#include <vector>

#define DECLARE_EASYFOUND \
	std::vector<int> __EF__CtrlID; \
	void __EF__ConditionQueryMenuSetUp(int nID); \

#define EF_HIDEALL \
		for (int i = 0; i < __EF__CtrlID.size(); ++i) GetDlgItem(__EF__CtrlID.at(i))->ShowWindow(SW_HIDE)

#define CONTROL_ID(id) \
	__EF__CtrlID.push_back(id)


#define BEGIN_EASYFOUND_MAP(class) \
void __fastcall class::__EF__ConditionQueryMenuSetUp(int nID) \
{ \
	int i; \
	std::vector<int> vi; \
	for (i = 0; i < __EF__CtrlID.size(); ++i) GetDlgItem(__EF__CtrlID.at(i))->ShowWindow(SW_HIDE); \
	switch (nID) \
	{

#define EF_SHOW(menuID, IDs) \
	case menuID: \
		vi = IDs; \
		for (i = 0; i < vi.size(); ++i) GetDlgItem(menuID##_vi.at(i))->ShowWindow(SW_SHOW); \
		break;

#define  EF_SHOW(menuID, IDs, o) \
		case menuID: \
		vi = IDs; \
		for (i = 0; i < vi.size(); ++i) GetDlgItem(menuID##_vi.at(i))->ShowWindow(SW_SHOW); \
		vi.clear(); \
		vi = o; \
		assert(vi.size() % 2 == 0); \
		for (i = 0; i < vi.size(); i += 2) \
		{ \
			GetDlgItem(vi.at(i)))->ModifyStyle() \
		} \
		break;

#define END_EASYFOUND_MAP(id) \
	} \
	GetDlgItem(id)->ShowWindow(SW_SHOW); \
}

#define END_EASYFOUND_MAP \
	} \
}

#define EF_UPDATE(id) __EF__ConditionQueryMenuSetUp(id)

#endif // !__EASYOFOUND_H__
