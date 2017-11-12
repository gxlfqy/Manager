
// ManagerDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Manager.h"
#include "ManagerDlg.h"
#include "afxdialogex.h"
#include <imm.h>
#include <stack>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CManagerDlg 对话框

CREATE_EASYSTATICCTRLCONNECT

CManagerDlg::CManagerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CManagerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PATHOLOGY_ADENOCARCINOMA, m_ADEMenuBottomCtrl);
	DDX_Control(pDX, IDC_SURGERY_GLAND, m_GLANDMenuBottomCtrl);
}

BEGIN_MESSAGE_MAP(CManagerDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_CLICK, IDC_TREE1, &CManagerDlg::OnNMClickTree1)
	ON_WM_VSCROLL()
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
	ON_WM_SIZING()
	ON_COMMAND(ID_CONDITION_QUERY_MENU, &CManagerDlg::OnConditionQueryMenu)
	ON_COMMAND(ID_OUTPUT_DATAID, &CManagerDlg::OnOutputDataid)
	ON_BN_CLICKED(IDC_PATHOLOGY_ADENOCARCINOMA, &CManagerDlg::OnBnClickedPathologyMfcmenubutton)
	ON_BN_CLICKED(IDC_SURGERY_GLAND, &CManagerDlg::OnBnClickedSurgeryGland)
	ON_EN_CHANGE(IDC_CTCHECK_CTNO, &CManagerDlg::OnEnChangeCtcheckCtno)
	ON_EN_CHANGE(IDC_PATHOLOGY_NO, &CManagerDlg::OnEnChangePathologyNo)
	ON_EN_CHANGE(IDC_FOLLOW_UP_RECORDS_CT_NO, &CManagerDlg::OnEnChangeFollowUpRecordsCtNo)
END_MESSAGE_MAP()

// ES_BORDER代表控件与边框的距离保持不变
// ES_KEEPSIZE代表控件的宽度和高度保持不变，left / right只能设置其中一个为ES_KEEPSIZE, top / bottom亦然。
// Control  ID代表以另一个空间为参照
// 具体注释如下，待设置控件记为ID1，参照控件记为ID2
// i left = ID2  ID1左边到ID2右边的距离保持不变（不管ID2如何变化）
// ii right = ID2 ID1右边到ID2左边的距离保持不变（不管ID2如何变化）
// iii top = ID2  ID1上边到ID2下边的距离保持不变（不管ID2如何变化）
// iv bottom = ID2 ID1下边到ID2上边的距离保持不变（不管ID2如何变化）
// options-- - 特别操作ES_HCENTER, ES_VCENTER and 0的结合。
// 0代表没有任何操作；
// ES_HCENTER代表控件在left / right之间水平居中，此时left / right都不能设置成ES_KEEPSIZE，控件的宽度保持不变；
// ES_VCENTER同理ES_HCENTER

BEGIN_EASYSTATICCTRLCONNECT_MAP(CManagerDlg)
	//Basic Info Static 
	ESCC_CONNECT(IDC_NAME_STATIC, IDC_BASICINFO_NAME, ControlType::Edit, 0)
	ESCC_CONNECT(IDC_SEX_STATIC, IDC_BASICINFO_SEX,  ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_AGE_STATIC, IDC_BASICINFO_AGE, ControlType::Edit, 0)
	ESCC_CONNECT(IDC_SMOKEYEAR_STATIC, IDC_BASICINFO_SMOKEYEAR,  ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_SMOKENUM_STATIC, IDC_BASICINFO_SMOKENUM, ControlType::Edit, ES_NUMBER)
	ESCC_CONNECT(IDC_SYMPTOM_STATIC, IDC_BASICINFO_SYMPTOM, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_COUGH_STATIC, IDC_BASICINFO_COUGH, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_HEMOPTYSIS_STATIC, IDC_BASICINFO_HEMOPTYSIS, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_FHOC_STATIC, IDC_BASICINFO_FHOC, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_FHOLC_STATIC, IDC_BASICINFO_FHOLC, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_OMTH_STATIC, IDC_BASICINFO_OMTH, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_EMPHYSEMA1_STATIC, IDC_BASICINFO_EMPHYSEMA1, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_TUBERCULOSIS_STATIC, IDC_BASICINFO_TUBERCULOSIS, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_SILICOSIS_STATIC, IDC_BASICINFO_SILICOSIS, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_HBP_STATIC, IDC_BASICINFO_HBP, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_CARDIOPATHY_STATIC, IDC_BASICINFO_CARDIOPATHY, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_CEREBROVASCULAR_DISEASE_STATIC, IDC_BASICINFO_CEREBROVASCULAR_DISEASE, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_DIABETES_STATIC, IDC_BASICINFO_DIABETES, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_NEPHROPATHY_STATIC, IDC_BASICINFO_NEPHROPATHY, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_OSMH_STATIC, IDC_BASICINFO_OSMH, ControlType::Edit, 0)

	//CT check Static
	ESCC_CONNECT(IDC_CTNO_STATIC, IDC_CTCHECK_CTNO, ControlType::Edit, ES_ONLYINPUTNO)
	ESCC_CONNECT(IDC_CTDATE_STATIC, IDC_CTCHECK_CTDATE, ControlType::DateTimePicker, 0)
	ESCC_CONNECT(IDC_CTRAISE_STATIC, IDC_CTCHECK_CTRAISE, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_MACHINENAME_STATIC, IDC_CTCHECK_MACHINENAME, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_SCANNING_SLICE_STATIC, IDC_CTCHECK_SCANNING_SLICE, ControlType::Edit, ES_NUMBER)

	//PNR Static
	ESCC_CONNECT(IDC_MAJOR_AXIS_STATIC, IDC_PNR_MAJOR_AXIS, ControlType::Edit, ES_NUMBER)
	ESCC_CONNECT(IDC_MINOR_AXIS_STATIC, IDC_PNR_MINOR_AXIS, ControlType::Edit, ES_NUMBER)
	ESCC_CONNECT(IDC_SIZE_STATIC, IDC_PNR_SIZE, ControlType::Edit, ES_NUMBER)
	ESCC_CONNECT(IDC_DENSITY_STATIC, IDC_PNR_DENSITY, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_SHAPE_STATIC, IDC_PNR_SHAPE, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_PART_STATIC, IDC_PNR_PART, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_PERIACINAR_EMPHYSEMA_STATIC, IDC_PNR_PERIACINAR_EMPHYSEMA, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_MULTIPLE_NODES_STATIC, IDC_PNR_MULTIPLE_NODES, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_PLEURAL_CONTACT_STATIC, IDC_PNR_PLEURAL_CONTACT, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_RAG_STATIC, IDC_PNR_RAG, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_LEAFLET_STATIC, IDC_PNR_LEAFLET, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_PRE_STATIC, IDC_PNR_PRE, ControlType::Edit, 0)

	//OLD Static 
	ESCC_CONNECT(IDC_EMPHYSEMA2_STATIC, IDC_OLD_EMPHYSEMA2, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_IPF_STATIC, IDC_OLD_IPF, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_BRONCHIECTASIA_STATIC, IDC_OLD_BRONCHIECTASIA, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_OPTUBE_STATIC, IDC_OLD_OPTUBE, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_CAOFTHEP_STATIC, IDC_OLD_CAOFTHEP, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_PLEURAL_EFFUSION_STATIC, IDC_OLD_PLEURAL_EFFUSION, ControlType::ComboBox, 0)

	//EXCHECK Static 
	ESCC_CONNECT(IDC_BTMWE_STATIC, IDC_EXCHECK_BTMWE, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_PFE_STATIC, IDC_EXCHECK_PFE, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_EX1_STATIC, IDC_EXCHECK_EX1, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_CEA1_STATIC, IDC_EXCHECK_CEA1, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_CA1991_STATIC, IDC_EXCHECK_CA1991, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_CYFRA21_1_1_STATIC, IDC_EXCHECK_CYFRA21_1_1, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_NSE_1_STATIC, IDC_EXCHECK_NSE_1, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_PET_CT_1_STATIC, IDC_EXCHECK_PET_CT_1, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_EX2_STATIC, IDC_EXCHECK_EX2, ControlType::Edit, 0)
	ESCC_CONNECT(IDC_LYMPH_GLAND_STATIC, IDC_EXCHECK_LYMPH_GLAND, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_TRANSFER_STATIC, IDC_EXCHECK_TRANSFER, ControlType::ComboBox, 0)

	//SURGERY Static
	ESCC_CONNECT(IDC_SURGERY_DATE_STATIC, IDC_SURGERY_DATE, ControlType::DateTimePicker, 0)
	ESCC_CONNECT(IDC_SURGERY_TIME_STATIC, IDC_SURGERY_TIME, ControlType::Edit, ES_NUMBER)
	ESCC_CONNECT(IDC_SURGERY_NAME_STATIC, IDC_SURGERY_NAME, ControlType::ComboBox, 0)
	ESCC_CONNECT_MFCMENU(IDC_LYMPH_GLAND_2_STATIC, IDC_SURGERY_GLAND, ControlType::MFCMenuButtonControl, m_GLANDMenuBottomCtrl)

	//PATHOLOGY Static
	ESCC_CONNECT(IDC_PATHOLOGY_NO_STATIC, IDC_PATHOLOGY_NO, ControlType::Edit, ES_ONLYINPUTNO)
	ESCC_CONNECT(IDC_PATHOLOGY_DATE_STATIC, IDC_PATHOLOGY_DATE, ControlType::DateTimePicker, 0)
	ESCC_CONNECT(IDC_PATHOLOGY_PART_STATIC, IDC_PATHOLOGY_PART, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_PATHOLOGY_SIZE_STATIC, IDC_PATHOLOGY_SIZE, ControlType::Edit, ES_NUMBER)
	ESCC_CONNECT(IDC_PATHOLOGY_MAJOR_AXIS_STATIC, IDC_PATHOLOGY_MAJOR_AXIS, ControlType::Edit, ES_NUMBER)
	ESCC_CONNECT(IDC_PATHOLOGY_TYPES_STATIC, IDC_PATHOLOGY_TYPES, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_PATHOLOGY_TDOP_STATIC, IDC_PATHOLOGY_TDOP, ControlType::ComboBox, 0)
	//
	ESCC_CONNECT(IDC_PATHOLOGY_BIM_STATIC, IDC_PATHOLOGY_BIM, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_PATHOLOGY_VCE_STATIC, IDC_PATHOLOGY_VCE, ControlType::ComboBox, 0)
	ESCC_CONNECT_MFCMENU(IDC_PATHOLOGY_ADENOCARCINOMA_STATIC, IDC_PATHOLOGY_ADENOCARCINOMA, ControlType::MFCMenuButtonControl, m_ADEMenuBottomCtrl)
	ESCC_CONNECT(IDC_PATHOLOGY_VLD_STATIC, IDC_PATHOLOGY_VLD, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_PATHOLOGY_LIGAMENT_STATIC, IDC_PATHOLOGY_LIGAMENT, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_PATHOLOGY_NERVE_STATIC, IDC_PATHOLOGY_NERVE, ControlType::ComboBox, 0)
	//
	ESCC_CONNECT(IDC_PATHOLOGY_EMPHYSEMA_STATIC, IDC_PATHOLOGY_EMPHYSEMA, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_PATHOLOGY_PIF_STATIC, IDC_PATHOLOGY_PIF, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_PATHOLOGY_LNM_STATIC, IDC_PATHOLOGY_LNM, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_PATHOLOGY_INFLAMMATION_STATIC, IDC_PATHOLOGY_INFLAMMATION, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_PATHOLOGY_INFO1_STATIC, IDC_PATHOLOGY_INFO1, ControlType::Edit, 0)
	ESCC_CONNECT(IDC_PATHOLOGY_PATHOLOGICAL_STAGE_STATIC, IDC_PATHOLOGY_PATHOLOGICAL_STAGE, ControlType::Edit, 0)
	//

	//IMMUNOHISTOCHEMISTRY Static
	ESCC_CONNECT(IDC_IMMUNOHISTOCHEMISTRY_EGFR_STATIC, IDC_IMMUNOHISTOCHEMISTRY_EGFR, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_IMMUNOHISTOCHEMISTRY_CK7_STATIC, IDC_IMMUNOHISTOCHEMISTRY_CK7, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_IMMUNOHISTOCHEMISTRY_TTF_1_STATIC, IDC_IMMUNOHISTOCHEMISTRY_TTF_1, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_IMMUNOHISTOCHEMISTRY_CEA_STATIC, IDC_IMMUNOHISTOCHEMISTRY_CEA, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_IMMUNOHISTOCHEMISTRY_VIM_STATIC, IDC_IMMUNOHISTOCHEMISTRY_VIM, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_IMMUNOHISTOCHEMISTRY_CD34_STATIC, IDC_IMMUNOHISTOCHEMISTRY_CD34, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_IMMUNOHISTOCHEMISTRY_KI67_STATIC, IDC_IMMUNOHISTOCHEMISTRY_KI67, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_IMMUNOHISTOCHEMISTRY_NASPIN_A_STATIC, IDC_IMMUNOHISTOCHEMISTRY_NASPIN_A, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_IMMUNOHISTOCHEMISTRY_P63_STATIC, IDC_IMMUNOHISTOCHEMISTRY_P63, ControlType::ComboBox, 0)
	
	//GENETIC_TESTING Static
	ESCC_CONNECT(IDC_GENETIC_TESTING_1_STATIC, IDC_GENETIC_TESTING, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_GENETIC_TESTING_BML4_ALK_STATIC, IDC_GENETIC_TESTING_BML4_ALK, ControlType::ComboBox, 0)

	//FOLLOW_UP_RECORDS Static
	ESCC_CONNECT(IDC_FOLLOW_UP_RECORDS_CT_NO_STATIC, IDC_FOLLOW_UP_RECORDS_CT_NO, ControlType::Edit, ES_ONLYINPUTNO)
	ESCC_CONNECT(IDC_FOLLOW_UP_RECORDS_DATE_STATIC, IDC_FOLLOW_UP_RECORDS_DATE, ControlType::DateTimePicker, 0)
	ESCC_CONNECT(IDC_FOLLOW_UP_RECORDS_TIME_STATIC, IDC_FOLLOW_UP_RECORDS_TIME, ControlType::Edit, ES_NUMBER)
	ESCC_CONNECT(IDC_FOLLOW_UP_RECORDS_SITUATION_STATIC, IDC_FOLLOW_UP_RECORDS_SITUATION, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_FOLLOW_UP_RECORDS_AFTERTREATMENT_STATIC, IDC_FOLLOW_UP_RECORDS_AFTERTREATMENT, ControlType::ComboBox, 0)
	ESCC_CONNECT(IDC_FOLLOW_UP_RECORDS_CHEMOTHERAPY_STATIC, IDC_FOLLOW_UP_RECORDS_CHEMOTHERAPY, ControlType::ComboBox, 0)

END_EASYSTATICCTRLCONNECT_MAP

// BEGIN_EASYSIZE_MAP(CManagerDlg)
// 	//Basic Info Static 
// 	EASYSIZE(IDC_NAME_STATIC, IDC_BASICINFO_NAME, ES_KEEPSIZE, ES_KEEPSIZE, IDC_BASICINFO_NAME, 0)
// 	EASYSIZE(IDC_SEX_STATIC, IDC_BASICINFO_SEX, ES_KEEPSIZE, ES_KEEPSIZE, IDC_BASICINFO_SEX, 0)
// 	EASYSIZE(IDC_AGE_STATIC, IDC_BASICINFO_AGE, ES_KEEPSIZE, ES_KEEPSIZE, IDC_BASICINFO_AGE, 0)
// 	EASYSIZE(IDC_SMOKEYEAR_STATIC, IDC_BASICINFO_SMOKEYEAR, ES_KEEPSIZE, ES_KEEPSIZE, IDC_BASICINFO_SMOKEYEAR, 0)
// 	EASYSIZE(IDC_SMOKENUM_STATIC, IDC_BASICINFO_SMOKENUM, ES_KEEPSIZE, ES_KEEPSIZE, IDC_BASICINFO_SMOKENUM, 0)
// 	EASYSIZE(IDC_SYMPTOM_STATIC, IDC_BASICINFO_SYMPTOM, ES_KEEPSIZE, ES_KEEPSIZE, IDC_BASICINFO_SYMPTOM, 0)
// 	EASYSIZE(IDC_COUGH_STATIC, IDC_BASICINFO_COUGH, ES_KEEPSIZE, ES_KEEPSIZE, IDC_BASICINFO_COUGH, 0)
// 	EASYSIZE(IDC_HEMOPTYSIS_STATIC, IDC_BASICINFO_HEMOPTYSIS, ES_KEEPSIZE, ES_KEEPSIZE, IDC_BASICINFO_HEMOPTYSIS, 0)
// 	EASYSIZE(IDC_FHOC_STATIC, IDC_BASICINFO_FHOC, ES_KEEPSIZE, ES_KEEPSIZE, IDC_BASICINFO_FHOC, 0)
// 	EASYSIZE(IDC_FHOLC_STATIC, IDC_BASICINFO_FHOLC, ES_KEEPSIZE, ES_KEEPSIZE, IDC_BASICINFO_FHOLC, 0)
// 	EASYSIZE(IDC_OMTH_STATIC, IDC_BASICINFO_OMTH, ES_KEEPSIZE, ES_KEEPSIZE, IDC_BASICINFO_OMTH, 0)
// 	EASYSIZE(IDC_EMPHYSEMA1_STATIC, IDC_BASICINFO_EMPHYSEMA1, ES_KEEPSIZE, ES_KEEPSIZE, IDC_BASICINFO_EMPHYSEMA1, 0)
// 	EASYSIZE(IDC_TUBERCULOSIS_STATIC, IDC_BASICINFO_TUBERCULOSIS, ES_KEEPSIZE, ES_KEEPSIZE, IDC_BASICINFO_TUBERCULOSIS, 0)
// 	EASYSIZE(IDC_SILICOSIS_STATIC, IDC_BASICINFO_SILICOSIS, ES_KEEPSIZE, ES_KEEPSIZE, IDC_BASICINFO_SILICOSIS, 0)
// 	EASYSIZE(IDC_HBP_STATIC, IDC_BASICINFO_HBP, ES_KEEPSIZE, ES_KEEPSIZE, IDC_BASICINFO_HBP, 0)
// 	EASYSIZE(IDC_CARDIOPATHY_STATIC, IDC_BASICINFO_CARDIOPATHY, ES_KEEPSIZE, ES_KEEPSIZE, IDC_BASICINFO_CARDIOPATHY, 0)
// 	EASYSIZE(IDC_CEREBROVASCULAR_DISEASE_STATIC, IDC_BASICINFO_CEREBROVASCULAR_DISEASE, ES_KEEPSIZE, ES_KEEPSIZE, IDC_BASICINFO_CEREBROVASCULAR_DISEASE, 0)
// 	EASYSIZE(IDC_DIABETES_STATIC, IDC_BASICINFO_DIABETES, ES_KEEPSIZE, ES_KEEPSIZE, IDC_BASICINFO_DIABETES, 0)
// 	EASYSIZE(IDC_NEPHROPATHY_STATIC, IDC_BASICINFO_NEPHROPATHY, ES_KEEPSIZE, ES_KEEPSIZE, IDC_BASICINFO_NEPHROPATHY, 0)
// 	EASYSIZE(IDC_OSMH_STATIC, IDC_BASICINFO_OSMH, ES_KEEPSIZE, ES_KEEPSIZE, IDC_BASICINFO_OSMH, 0)
// 
// 	//CT check Static
// 	EASYSIZE(IDC_CTNO_STATIC, IDC_CTCHECK_CTNO, ES_KEEPSIZE, ES_KEEPSIZE, IDC_CTCHECK_CTNO, 0)
// 	EASYSIZE(IDC_CTDATE_STATIC, IDC_CTCHECK_CTDATE, ES_KEEPSIZE, ES_KEEPSIZE, IDC_CTCHECK_CTDATE, 0)
// 	EASYSIZE(IDC_CTRAISE_STATIC, IDC_CTCHECK_CTRAISE, ES_KEEPSIZE, ES_KEEPSIZE, IDC_CTCHECK_CTRAISE, 0)
// 	EASYSIZE(IDC_MACHINENAME_STATIC, IDC_CTCHECK_MACHINENAME, ES_KEEPSIZE, ES_KEEPSIZE, IDC_CTCHECK_MACHINENAME, 0)
// 	EASYSIZE(IDC_SCANNING_SLICE_STATIC, IDC_CTCHECK_SCANNING_SLICE, ES_KEEPSIZE, ES_KEEPSIZE, IDC_CTCHECK_SCANNING_SLICE, 0)
// 
// 	//PNR Static
// 	EASYSIZE(IDC_MAJOR_AXIS_STATIC, IDC_PNR_MAJOR_AXIS, ES_KEEPSIZE, ES_KEEPSIZE, IDC_PNR_MAJOR_AXIS, 0)
// 	EASYSIZE(IDC_MINOR_AXIS_STATIC, IDC_PNR_MINOR_AXIS, ES_KEEPSIZE, ES_KEEPSIZE, IDC_PNR_MINOR_AXIS, 0)
// 	EASYSIZE(IDC_SIZE_STATIC, IDC_PNR_SIZE, ES_KEEPSIZE, ES_KEEPSIZE, IDC_PNR_SIZE, 0)
// 	EASYSIZE(IDC_DENSITY_STATIC, IDC_PNR_DENSITY, ES_KEEPSIZE, ES_KEEPSIZE, IDC_PNR_DENSITY, 0)
// 	EASYSIZE(IDC_SHAPE_STATIC, IDC_PNR_SHAPE, ES_KEEPSIZE, ES_KEEPSIZE, IDC_PNR_SHAPE, 0)
// 	EASYSIZE(IDC_PART_STATIC, IDC_PNR_PART, ES_KEEPSIZE, ES_KEEPSIZE, IDC_PNR_PART, 0)
// 	EASYSIZE(IDC_PERIACINAR_EMPHYSEMA_STATIC, IDC_PNR_PERIACINAR_EMPHYSEMA, ES_KEEPSIZE, ES_KEEPSIZE, IDC_PNR_PERIACINAR_EMPHYSEMA, 0)
// 	EASYSIZE(IDC_MULTIPLE_NODES_STATIC, IDC_PNR_MULTIPLE_NODES, ES_KEEPSIZE, ES_KEEPSIZE, IDC_PNR_MULTIPLE_NODES, 0)
// 	EASYSIZE(IDC_PLEURAL_CONTACT_STATIC, IDC_PNR_PLEURAL_CONTACT, ES_KEEPSIZE, ES_KEEPSIZE, IDC_PNR_PLEURAL_CONTACT, 0)
// 	EASYSIZE(IDC_RAG_STATIC, IDC_PNR_RAG, ES_KEEPSIZE, ES_KEEPSIZE, IDC_PNR_RAG, 0)
// 	EASYSIZE(IDC_LEAFLET_STATIC, IDC_PNR_LEAFLET, ES_KEEPSIZE, ES_KEEPSIZE, IDC_PNR_LEAFLET, 0)
// 	EASYSIZE(IDC_PRE_STATIC, IDC_PNR_PRE, ES_KEEPSIZE, ES_KEEPSIZE, IDC_PNR_PRE, 0)
// 
// 	//OLD Static 
// 	EASYSIZE(IDC_EMPHYSEMA2_STATIC, IDC_OLD_EMPHYSEMA2, ES_KEEPSIZE, ES_KEEPSIZE, IDC_OLD_EMPHYSEMA2, 0)
// 	EASYSIZE(IDC_IPF_STATIC, IDC_OLD_IPF, ES_KEEPSIZE, ES_KEEPSIZE, IDC_OLD_IPF, 0)
// 	EASYSIZE(IDC_BRONCHIECTASIA_STATIC, IDC_OLD_BRONCHIECTASIA, ES_KEEPSIZE, ES_KEEPSIZE, IDC_OLD_BRONCHIECTASIA, 0)
// 	EASYSIZE(IDC_OPTUBE_STATIC, IDC_OLD_OPTUBE, ES_KEEPSIZE, ES_KEEPSIZE, IDC_OLD_OPTUBE, 0)
// 	EASYSIZE(IDC_CAOFTHEP_STATIC, IDC_OLD_CAOFTHEP, ES_KEEPSIZE, ES_KEEPSIZE, IDC_OLD_CAOFTHEP, 0)
// 	EASYSIZE(IDC_PLEURAL_EFFUSION_STATIC, IDC_OLD_PLEURAL_EFFUSION, ES_KEEPSIZE, ES_KEEPSIZE, IDC_OLD_PLEURAL_EFFUSION, 0)
// 
// 	//EXCHECK Static 
// 	EASYSIZE(IDC_BTMWE_STATIC, IDC_EXCHECK_BTMWE, ES_KEEPSIZE, ES_KEEPSIZE, IDC_EXCHECK_BTMWE, 0)
// 	EASYSIZE(IDC_PFE_STATIC, IDC_EXCHECK_PFE, ES_KEEPSIZE, ES_KEEPSIZE, IDC_EXCHECK_PFE, 0)
// 	EASYSIZE(IDC_EX1_STATIC, IDC_EXCHECK_EX1, ES_KEEPSIZE, ES_KEEPSIZE, IDC_EXCHECK_EX1, 0)
// 	EASYSIZE(IDC_CEA1_STATIC, IDC_EXCHECK_CEA1, ES_KEEPSIZE, ES_KEEPSIZE, IDC_EXCHECK_CEA1, 0)
// 	EASYSIZE(IDC_CA1991_STATIC, IDC_EXCHECK_CA1991, ES_KEEPSIZE, ES_KEEPSIZE, IDC_EXCHECK_CA1991, 0)
// 	EASYSIZE(IDC_CYFRA21_1_1_STATIC, IDC_EXCHECK_CYFRA21_1_1, ES_KEEPSIZE, ES_KEEPSIZE, IDC_EXCHECK_CYFRA21_1_1, 0)
// 	EASYSIZE(IDC_NSE_1_STATIC, IDC_EXCHECK_NSE_1, ES_KEEPSIZE, ES_KEEPSIZE, IDC_EXCHECK_NSE_1, 0)
// 	EASYSIZE(IDC_PET_CT_1_STATIC, IDC_EXCHECK_PET_CT_1, ES_KEEPSIZE, ES_KEEPSIZE, IDC_EXCHECK_PET_CT_1, 0)
// 	EASYSIZE(IDC_EX2_STATIC, IDC_EXCHECK_EX2, ES_KEEPSIZE, ES_KEEPSIZE, IDC_EXCHECK_EX2, 0)
// 	EASYSIZE(IDC_LYMPH_GLAND_STATIC, IDC_EXCHECK_LYMPH_GLAND, ES_KEEPSIZE, ES_KEEPSIZE, IDC_EXCHECK_LYMPH_GLAND, 0)
// 	EASYSIZE(IDC_TRANSFER_STATIC, IDC_EXCHECK_TRANSFER, ES_KEEPSIZE, ES_KEEPSIZE, IDC_EXCHECK_TRANSFER, 0)
// 
// 	//SURGERY Static
// 	EASYSIZE(IDC_SURGERY_DATE_STATIC, IDC_SURGERY_DATE, ES_KEEPSIZE, ES_KEEPSIZE, IDC_SURGERY_DATE, 0)
// 	EASYSIZE(IDC_SURGERY_TIME_STATIC, IDC_SURGERY_TIME, ES_KEEPSIZE, ES_KEEPSIZE, IDC_SURGERY_TIME, 0)
// 	EASYSIZE(IDC_SURGERY_NAME_STATIC, IDC_SURGERY_NAME, ES_KEEPSIZE, ES_KEEPSIZE, IDC_SURGERY_NAME, 0)
// 	EASYSIZE(IDC_LYMPH_GLAND_2_STATIC, IDC_SURGERY_GLAND, ES_KEEPSIZE, ES_KEEPSIZE, IDC_SURGERY_GLAND, 0)
// 
// 	//PATHOLOGY Static
// 	EASYSIZE(IDC_PATHOLOGY_NO_STATIC, IDC_PATHOLOGY_NO, ES_KEEPSIZE, ES_KEEPSIZE, IDC_PATHOLOGY_NO, 0)
// 	EASYSIZE(IDC_PATHOLOGY_DATE_STATIC, IDC_PATHOLOGY_DATE, ES_KEEPSIZE, ES_KEEPSIZE, IDC_PATHOLOGY_DATE, 0)
// 	EASYSIZE(IDC_PATHOLOGY_PART_STATIC, IDC_PATHOLOGY_PART, ES_KEEPSIZE, ES_KEEPSIZE, IDC_PATHOLOGY_PART, 0)
// 	EASYSIZE(IDC_PATHOLOGY_SIZE_STATIC, IDC_PATHOLOGY_SIZE, ES_KEEPSIZE, ES_KEEPSIZE, IDC_PATHOLOGY_SIZE, 0)
// 	EASYSIZE(IDC_PATHOLOGY_MAJOR_AXIS_STATIC, IDC_PATHOLOGY_MAJOR_AXIS, ES_KEEPSIZE, ES_KEEPSIZE, IDC_PATHOLOGY_MAJOR_AXIS, 0)
// 	EASYSIZE(IDC_PATHOLOGY_TYPES_STATIC, IDC_PATHOLOGY_TYPES, ES_KEEPSIZE, ES_KEEPSIZE, IDC_PATHOLOGY_TYPES, 0)
// 	EASYSIZE(IDC_PATHOLOGY_TDOP_STATIC, IDC_PATHOLOGY_TDOP, ES_KEEPSIZE, ES_KEEPSIZE, IDC_PATHOLOGY_TDOP, 0)
// 	//
// 	EASYSIZE(IDC_PATHOLOGY_BIM_STATIC, IDC_PATHOLOGY_BIM, ES_KEEPSIZE, ES_KEEPSIZE, IDC_PATHOLOGY_BIM, 0)
// 	EASYSIZE(IDC_PATHOLOGY_VCE_STATIC, IDC_PATHOLOGY_VCE, ES_KEEPSIZE, ES_KEEPSIZE, IDC_PATHOLOGY_VCE, 0)
// 	EASYSIZE(IDC_PATHOLOGY_ADENOCARCINOMA_STATIC, IDC_PATHOLOGY_ADENOCARCINOMA, ES_KEEPSIZE, ES_KEEPSIZE, IDC_PATHOLOGY_ADENOCARCINOMA, 0)
// 	EASYSIZE(IDC_PATHOLOGY_VLD_STATIC, IDC_PATHOLOGY_VLD, ES_KEEPSIZE, ES_KEEPSIZE, IDC_PATHOLOGY_VLD, 0)
// 	EASYSIZE(IDC_PATHOLOGY_LIGAMENT_STATIC, IDC_PATHOLOGY_LIGAMENT, ES_KEEPSIZE, ES_KEEPSIZE, IDC_PATHOLOGY_LIGAMENT, 0)
// 	EASYSIZE(IDC_PATHOLOGY_NERVE_STATIC, IDC_PATHOLOGY_NERVE, ES_KEEPSIZE, ES_KEEPSIZE, IDC_PATHOLOGY_NERVE, 0)
// 	//
// 	EASYSIZE(IDC_PATHOLOGY_EMPHYSEMA_STATIC, IDC_PATHOLOGY_EMPHYSEMA, ES_KEEPSIZE, ES_KEEPSIZE, IDC_PATHOLOGY_EMPHYSEMA, 0)
// 	EASYSIZE(IDC_PATHOLOGY_PIF_STATIC, IDC_PATHOLOGY_PIF, ES_KEEPSIZE, ES_KEEPSIZE, IDC_PATHOLOGY_PIF, 0)
// 	EASYSIZE(IDC_PATHOLOGY_LNM_STATIC, IDC_PATHOLOGY_LNM, ES_KEEPSIZE, ES_KEEPSIZE, IDC_PATHOLOGY_LNM, 0)
// 	EASYSIZE(IDC_PATHOLOGY_INFLAMMATION_STATIC, IDC_PATHOLOGY_INFLAMMATION, ES_KEEPSIZE, ES_KEEPSIZE, IDC_PATHOLOGY_INFLAMMATION, 0)
// 	EASYSIZE(IDC_PATHOLOGY_INFO1_STATIC, IDC_PATHOLOGY_INFO1, ES_KEEPSIZE, ES_KEEPSIZE, IDC_PATHOLOGY_INFO1, 0)
// 	EASYSIZE(IDC_PATHOLOGY_PATHOLOGICAL_STAGE_STATIC, IDC_PATHOLOGY_PATHOLOGICAL_STAGE, ES_KEEPSIZE, ES_KEEPSIZE, IDC_PATHOLOGY_PATHOLOGICAL_STAGE, 0)
// 	//
// 
// 	//IMMUNOHISTOCHEMISTRY Static
// 	EASYSIZE(IDC_IMMUNOHISTOCHEMISTRY_EGFR_STATIC, IDC_IMMUNOHISTOCHEMISTRY_EGFR, ES_KEEPSIZE, ES_KEEPSIZE, IDC_IMMUNOHISTOCHEMISTRY_EGFR, 0)
// 	EASYSIZE(IDC_IMMUNOHISTOCHEMISTRY_CK7_STATIC, IDC_IMMUNOHISTOCHEMISTRY_CK7, ES_KEEPSIZE, ES_KEEPSIZE, IDC_IMMUNOHISTOCHEMISTRY_CK7, 0)
// 	EASYSIZE(IDC_IMMUNOHISTOCHEMISTRY_TTF_1_STATIC, IDC_IMMUNOHISTOCHEMISTRY_TTF_1, ES_KEEPSIZE, ES_KEEPSIZE, IDC_IMMUNOHISTOCHEMISTRY_TTF_1, 0)
// 	EASYSIZE(IDC_IMMUNOHISTOCHEMISTRY_CEA_STATIC, IDC_IMMUNOHISTOCHEMISTRY_CEA, ES_KEEPSIZE, ES_KEEPSIZE, IDC_IMMUNOHISTOCHEMISTRY_CEA, 0)
// 	EASYSIZE(IDC_IMMUNOHISTOCHEMISTRY_VIM_STATIC, IDC_IMMUNOHISTOCHEMISTRY_VIM, ES_KEEPSIZE, ES_KEEPSIZE, IDC_IMMUNOHISTOCHEMISTRY_VIM, 0)
// 	EASYSIZE(IDC_IMMUNOHISTOCHEMISTRY_CD34_STATIC, IDC_IMMUNOHISTOCHEMISTRY_CD34, ES_KEEPSIZE, ES_KEEPSIZE, IDC_IMMUNOHISTOCHEMISTRY_CD34, 0)
// 	EASYSIZE(IDC_IMMUNOHISTOCHEMISTRY_KI67_STATIC, IDC_IMMUNOHISTOCHEMISTRY_KI67, ES_KEEPSIZE, ES_KEEPSIZE, IDC_IMMUNOHISTOCHEMISTRY_KI67, 0)
// 	EASYSIZE(IDC_IMMUNOHISTOCHEMISTRY_NASPIN_A_STATIC, IDC_IMMUNOHISTOCHEMISTRY_NASPIN_A, ES_KEEPSIZE, ES_KEEPSIZE, IDC_IMMUNOHISTOCHEMISTRY_NASPIN_A, 0)
// 	EASYSIZE(IDC_IMMUNOHISTOCHEMISTRY_P63_STATIC, IDC_IMMUNOHISTOCHEMISTRY_P63, ES_KEEPSIZE, ES_KEEPSIZE, IDC_IMMUNOHISTOCHEMISTRY_P63, 0)
// 
// 	//GENETIC_TESTING Static
// 	EASYSIZE(IDC_GENETIC_TESTING_1_STATIC, IDC_GENETIC_TESTING, ES_KEEPSIZE, ES_KEEPSIZE, IDC_GENETIC_TESTING, 0)
// 	EASYSIZE(IDC_GENETIC_TESTING_BML4_ALK_STATIC, IDC_GENETIC_TESTING_BML4_ALK, ES_KEEPSIZE, ES_KEEPSIZE, IDC_GENETIC_TESTING_BML4_ALK, 0)
// 
// 	//FOLLOW_UP_RECORDS Static
// 	EASYSIZE(IDC_FOLLOW_UP_RECORDS_CT_NO_STATIC, IDC_FOLLOW_UP_RECORDS_CT_NO, ES_KEEPSIZE, ES_KEEPSIZE, IDC_FOLLOW_UP_RECORDS_CT_NO, 0)
// 	EASYSIZE(IDC_FOLLOW_UP_RECORDS_DATE_STATIC, IDC_FOLLOW_UP_RECORDS_DATE, ES_KEEPSIZE, ES_KEEPSIZE, IDC_FOLLOW_UP_RECORDS_DATE, 0)
// 	EASYSIZE(IDC_FOLLOW_UP_RECORDS_TIME_STATIC, IDC_FOLLOW_UP_RECORDS_TIME, ES_KEEPSIZE, ES_KEEPSIZE, IDC_FOLLOW_UP_RECORDS_TIME, 0)
// 	EASYSIZE(IDC_FOLLOW_UP_RECORDS_SITUATION_STATIC, IDC_FOLLOW_UP_RECORDS_SITUATION, ES_KEEPSIZE, ES_KEEPSIZE, IDC_FOLLOW_UP_RECORDS_SITUATION, 0)
// 	EASYSIZE(IDC_FOLLOW_UP_RECORDS_AFTERTREATMENT_STATIC, IDC_FOLLOW_UP_RECORDS_AFTERTREATMENT, ES_KEEPSIZE, ES_KEEPSIZE, IDC_FOLLOW_UP_RECORDS_AFTERTREATMENT, 0)
// 	EASYSIZE(IDC_FOLLOW_UP_RECORDS_CHEMOTHERAPY_STATIC, IDC_FOLLOW_UP_RECORDS_CHEMOTHERAPY, ES_KEEPSIZE, ES_KEEPSIZE, IDC_FOLLOW_UP_RECORDS_CHEMOTHERAPY, 0)
// END_EASYSIZE_MAP

void SetMenuInfoBTree(_menuInfo temp, CBinaryTree<_menuInfo> * pMenuInfo)
{
	static std::stack<int> data;
	int nID = temp.nID;
	int term = 0;
	while (nID)
	{
		term = nID % 256;
		data.push(term);
		nID >>= 8;
	}
	int a = 0;
	int i = 0;
	void * mark = pMenuInfo->GetMark();
	while (!data.empty())
	{
		a = data.top() - 1;
		data.pop();
		for (i = 0; i < a; ++i)
			pMenuInfo->Left();
		if (data.empty() || data.top() == 0)
			break;
		pMenuInfo->Right();
	}
	pMenuInfo->Set(temp);
	pMenuInfo->GotoMark(mark);
}

// CManagerDlg 消息处理程序

BOOL CManagerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	int a = 0;
	//INIT_EASYSIZE;
	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	//初始化树
	//InitAdenocarcinomaTree();
	//对话框滚动条
	//initScrollbar();

	//////////////////////////////////////////////////////////////////////////
	//获取对话框开始时的高度和宽度
	CRect rect;
	GetClientRect(&rect);     //取客户区大小    
	old.x = rect.right - rect.left;
	old.y = rect.bottom - rect.top;
	//////////////////////////////////////////////////////////////////////////
	//CMenu* pMenu = new CMenu;
	//pMenu->LoadMenu(IDR_MENU2); //载入菜单资源
	//m_ADEMenuBottomCtrl.m_hMenu = pMenu->GetSubMenu(0)->GetSafeHmenu();
	//m_GLANDMenuBottomCtrl.m_hMenu = pMenu->GetSubMenu(1)->GetSafeHmenu();
	//Init the Dynamic Menu
	InitADEMenuBottomCtrl();
	InitGLANDMenuBottomCtrl();
	//////////////////////////////////////////////////////////////////////////
	CONNECTSTATICCTRL;
	//////////////////////////////////////////////////////////////////////////
	BanInputMethod(IDC_CTCHECK_CTNO);
	BanInputMethod(IDC_PATHOLOGY_NO);
	BanInputMethod(IDC_FOLLOW_UP_RECORDS_CT_NO);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CManagerDlg::OnPaint()
{
// 	CRect   rect;
// 	CPaintDC   dc(this);
// 	GetClientRect(rect);
// 	dc.FillSolidRect(rect, RGB(199, 237, 204));   //设置为绿色背景

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
	//对话框滚动条
// 	SCROLLINFO scrollinfo;
// 	GetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
// 	int unit = 6;
// 	switch (nSBCode)
// 	{
// 	case SB_LINEUP:          //Scroll one line up
// 		scrollinfo.nPos -= 1;
// 		if (scrollinfo.nPos<scrollinfo.nMin)
// 		{
// 			scrollinfo.nPos = scrollinfo.nMin;
// 			break;
// 		}
// 		SetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
// 		ScrollWindow(0, unit);
// 		break;
// 	case SB_LINEDOWN:           //Scroll one line down
// 		scrollinfo.nPos += 1;
// 		if (scrollinfo.nPos + scrollinfo.nPage>scrollinfo.nMax)  //此处一定要注意加上滑块的长度，再作判断
// 		{
// 			scrollinfo.nPos = scrollinfo.nMax;
// 			break;
// 		}
// 		SetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
// 		ScrollWindow(0, -unit);
// 		break;
// 	case SB_PAGEUP:            //Scroll one page up.
// 		scrollinfo.nPos -= 5;
// 		if (scrollinfo.nPos <= scrollinfo.nMin)
// 		{
// 			scrollinfo.nPos = scrollinfo.nMin;
// 			break;
// 		}
// 		SetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
// 		ScrollWindow(0, unit * 5);
// 		break;
// 	case SB_PAGEDOWN:        //Scroll one page down        
// 		scrollinfo.nPos += 5;
// 		if (scrollinfo.nPos + scrollinfo.nPage >= scrollinfo.nMax)  //此处一定要注意加上滑块的长度，再作判断
// 		{
// 			scrollinfo.nPos = scrollinfo.nMax;
// 			break;
// 		}
// 		SetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
// 		ScrollWindow(0, -unit * 5);
// 		break;
// 	case SB_ENDSCROLL:      //End scroll     
// 		break;
// 	case SB_THUMBPOSITION:  //Scroll to the absolute position. The current position is provided in nPos
// 		break;
// 	case SB_THUMBTRACK:                  //Drag scroll box to specified position. The current position is provided in nPos
// 		ScrollWindow(0, (scrollinfo.nPos - nPos)*unit);
// 		scrollinfo.nPos = nPos;
// 		SetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
// 		break;
// 	}
	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}


BOOL CManagerDlg::OnEraseBkgnd(CDC* pDC)
{
// 	// TODO:  在此添加消息处理程序代码和/或调用默认值
	//双缓冲
// 	CRect rc;
// 	CDC dcMem;
// 	GetClientRect(&rc);
// 	CBitmap bmp; //内存中承载临时图象的位图
// 
// 
// 	dcMem.CreateCompatibleDC(pDC); //依附窗口DC创建兼容内存DC
// 	//创建兼容位图(必须用pDC创建，否则画出的图形变成黑色)
// 	bmp.CreateCompatibleBitmap(pDC, rc.Width(), rc.Height());
// 	CBitmap *pOldBit = dcMem.SelectObject(&bmp);
// 	//按原来背景填充客户区，不然会是黑色
// 	dcMem.FillSolidRect(rc, RGB(255, 255, 255));
// 
// 	//画图，添加你要画图的代码，不过用dcMem画，而不是pDC
// 
// 	pDC->BitBlt(0, 0, rc.Width(), rc.Height(), &dcMem, 0, 0, SRCCOPY);
// 
// 	//将内存DC上的图象拷贝到前台
// 	//绘图完成后的清理
// 	dcMem.DeleteDC();		//删除DC
// 	bmp.DeleteObject();		//删除位图
// 	return true;
// 	//这里一定要用return true，如果用自动生成的，会调用基类，把画出来的覆盖，就什     么结果也没有了
// 
 	return CDialogEx::OnEraseBkgnd(pDC);
}

void CManagerDlg::RestoreGroup()
{
	static int nCounter = 0;
	POINT Newp; //获取现在对话框的大小
	CRect recta;
	GetClientRect(&recta);     //取客户区大小
	float fsp[2];
	Newp.x = recta.right - recta.left;
	Newp.y = recta.bottom - recta.top;
	fsp[0] = (float)Newp.x / old.x;
	fsp[1] = (float)Newp.y / old.y;
	static int ExID[13];
	static CMyList<SCtrlInfo> list;
	if (nCounter == 0)
	{
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
		SCtrlInfo info;
		int woc;
		CRect Rect;
		HWND  hwndChild = ::GetWindow(m_hWnd, GW_CHILD);  //列出所有控件 
		if (hwndChild == NULL)
			return;
		while (hwndChild)
		{
			woc = ::GetDlgCtrlID(hwndChild);//取得ID
			info.nID = woc;
			GetDlgItem(woc)->GetWindowRect(Rect);
			ScreenToClient(Rect);
			info.rect = Rect;
			list.AddRear(info);
			hwndChild = ::GetWindow(hwndChild, GW_HWNDNEXT);
		}
		nCounter++;
	}
	SCtrlInfo * info = list.Next();
	if (info == nullptr)
		exit(1);
	int i;
	bool isExID = false;
	LONG height;
	LONG width;
	do
	{
		int nID = info->nID;

		for (i = 0, isExID = false; i < 13; ++i)
		{
			if (nID == ExID[i])
			{
				isExID = true;
				break;
			}
		}
		height = info->rect.bottom - info->rect.top;
		width = info->rect.right - info->rect.left;
		info->rect.left = LONG(info->rect.left * fsp[0]);
		info->rect.top = LONG(info->rect.top * fsp[1]);
		if (isExID)
		{
			info->rect.right = LONG(info->rect.right * fsp[0]);
			info->rect.bottom = LONG(info->rect.bottom * fsp[1]);
		}
		else
		{
			info->rect.right = info->rect.left + width;
			info->rect.bottom = info->rect.top + height;
		}
		info = list.Next();
	} while (info);
	while (info = list.Next())
		GetDlgItem(info->nID)->MoveWindow(info->rect.left, info->rect.top, info->rect.right - info->rect.left, info->rect.bottom - info->rect.top, FALSE);
	old = Newp;
	Invalidate(); UpdateWindow();
}

void CManagerDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);
	if (nType == SIZE_RESTORED || nType == SIZE_MAXIMIZED)
	{
		RestoreGroup();
		UPDATECONTROLPOSITION;
		//__ES__RepositionControls();
		//UPDATE_EASYSIZE;	//更新窗口大小

	}
}


void CManagerDlg::OnSizing(UINT fwSide, LPRECT pRect)
{
	CDialogEx::OnSizing(fwSide, pRect);
	static int nCounter = 0;
	static int width = 0, height = 0;
	if (nCounter == 0)
	{
		width = old.x;
		height = old.y;
		nCounter++;
	}
	EASYSIZE_MINSIZE(width, height, fwSide, pRect);
}


void CManagerDlg::OnConditionQueryMenu()
{
	CFindDlg dlg;
	dlg.SetControlInfo(&__EF__StaticCtrl);
	dlg.DoModal();
	CComboBox * pCom = new CComboBox;
	int nCount = ((CComboBox *)GetDlgItem(IDC_BASICINFO_SEX))->GetCount();
	/*((CComboBox *)GetDlgItem(IDC_BASICINFO_SEX))->GetLBText()*/
	return;
}


void CManagerDlg::OnOutputDataid()
{
	CDataIDDlg dlg;
	dlg.SetDataID(&__EF__StaticCtrl);
	dlg.DoModal();
}

//腺癌按钮
void CManagerDlg::OnBnClickedPathologyMfcmenubutton()
{
	if (m_ADEMenuBottomCtrl.m_nMenuResult != 0)
	{
		CString temp = m_ADEMenuBottomCtrl.GetTreeString(m_ADEMenuBottomCtrl.m_nMenuResult, L"-");
		SetDlgItemText(IDC_MFCMENUINFO, temp);
	}
}

#define SetMenuInfoTemp(i, t) \
	temp.title = L##t; \
	temp.nID = 0x##i; \
	list.push_back(temp)

void CManagerDlg::InitADEMenuBottomCtrl()
{
	CBinaryTree<_menuInfo> * pMenuInfo = &m_ADEMenuBottomCtrl.m_menuInfobTree;
	std::vector<_menuInfo> list;
	_menuInfo temp;
	SetMenuInfoTemp(010000, "浸润前病变");
	SetMenuInfoTemp(010100, "非典型腺瘤样增生");
	SetMenuInfoTemp(010200, "原位腺癌");
	SetMenuInfoTemp(010201, "非黏液性");
	SetMenuInfoTemp(010202, "黏液性");
	SetMenuInfoTemp(010203, "混合性");
	SetMenuInfoTemp(020000, "微浸润腺癌");
	SetMenuInfoTemp(020100, "非黏液性");
	SetMenuInfoTemp(020200, "黏液性");
	SetMenuInfoTemp(020300, "混合性");
	SetMenuInfoTemp(030000, "浸润性腺癌");
	SetMenuInfoTemp(030100, "伏壁生长为主");
	SetMenuInfoTemp(030200, "腺泡为主");
	SetMenuInfoTemp(030300, "乳头状");
	SetMenuInfoTemp(030400, "微小乳头为主");
	SetMenuInfoTemp(030500, "实体为主伴粘液蛋白分泌");
	SetMenuInfoTemp(040000, "浸润性变异");
	SetMenuInfoTemp(040100, "黏液性");
	SetMenuInfoTemp(040200, "胶质样");
	SetMenuInfoTemp(040300, "胎儿型");
	SetMenuInfoTemp(040400, "肠腺癌");
	int list_len = list.size();
	for (int i = 0; i < list_len; ++i)
		SetMenuInfoBTree(list.at(i), pMenuInfo);
	m_ADEMenuBottomCtrl.CreateDynamicMenu();
}



void CManagerDlg::InitGLANDMenuBottomCtrl()
{
	CBinaryTree<_menuInfo> * pMenuInfo = &m_GLANDMenuBottomCtrl.m_menuInfobTree;
	std::vector<_menuInfo> list;
	_menuInfo temp;
	SetMenuInfoTemp(0100, "活检");
	SetMenuInfoTemp(0101, "阳性");
	SetMenuInfoTemp(0102, "阴性");
	SetMenuInfoTemp(0200, "清扫");
	SetMenuInfoTemp(0201, "阳性");
	SetMenuInfoTemp(0202, "阴性");
	int list_len = list.size();
	for (int i = 0; i < list_len; ++i)
		SetMenuInfoBTree(list.at(i), pMenuInfo);
	m_GLANDMenuBottomCtrl.CreateDynamicMenu();
}

#undef SetMenuInfoTemp

void CManagerDlg::OnBnClickedSurgeryGland()
{
	if (m_GLANDMenuBottomCtrl.m_nMenuResult != 0)
	{
		CString temp = m_GLANDMenuBottomCtrl.GetTreeString(m_GLANDMenuBottomCtrl.m_nMenuResult, L"-");
		m_GLANDMenuBottomCtrl.SetWindowText(temp);
	}
}

#define EC_BanInputMethod(id) \
	HWND hWnd = GetDlgItem(nID)->m_hWnd; \
	if (hWnd && IsWindow(hWnd)) \
	{ \
		HIMC m_hImc = ImmGetContext(hWnd); \
		if (m_hImc) \
			ImmAssociateContext(hWnd, NULL); \
		ImmReleaseContext(hWnd, m_hImc); \
		::SetFocus(hWnd); \
	}

//禁用对应ID控件的输入法
void CManagerDlg::BanInputMethod(int nID)
{
	EC_BanInputMethod(nID);
}



void CManagerDlg::OnEnChangeCtcheckCtno()
{
	OnlyAgreeNo(IDC_CTCHECK_CTNO);
}

void CManagerDlg::OnlyAgreeNo(int nID)
{
	EC_OnlyAgreeNo(nID);
}

void CManagerDlg::OnEnChangePathologyNo()
{
	OnlyAgreeNo(IDC_PATHOLOGY_NO);
}

void CManagerDlg::OnEnChangeFollowUpRecordsCtNo()
{
	OnlyAgreeNo(IDC_FOLLOW_UP_RECORDS_CT_NO);
}

