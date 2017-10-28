create table Lungs_Other_Find  --肺部其他发现
(  
ID int primary key not null, --ID,主键的关键字primary key,非空
Emphysema varchar(10), --肺气肿 
Interstitial_Fibrosis varchar(10), --间质性费纤维化  
Bronchial_Dilatation varchar(10),	--支气管扩张
Old_Tuberculosis varchar(10),		--陈旧性肺结核
Pleural_Calcification varchar(10),	--胸膜钙化
Pleural_Effusion varchar(10),	--胸腔积液
);
create table Chest_Other_Check	--胸部其他检查
(
ID int primary key not null,	--ID，主键，非空
Blood_Tumor_Markers varchar(10),	--血液肿瘤标记物检查
Respiratory_Function varchar(10),	--呼吸功能检查
If_Any	varchar(10),	--如有,选择正常或者异常
CEA varchar(10),		--阴性，阳性
CA199 varchar(10),		--阴性，阳性
Cyfra21_1 varchar(10),	--Cyfra21-1,阴性，阳性
NSE varchar(10),		--阴性，阳性
PET_CT varchar(10),		--有,无
If_Any_Text text,		--如有，文本
Lymph_Nodes varchar(10),	--淋巴结
Transference varchar(10),	--转移
);
create table Surgery	--外科手术表
(
ID int primary key not null, --ID，主键，非空
Surgery_Date date,		--日期
Intervals text,		--间隔时间
Operation_Name varchar(10),	--手术名字
Lymph_Nodes_A varchar(10),		--淋巴结，活检，清扫
Lymph_Nodes_B varchar(10)		--淋巴结，阴性，阳性
);