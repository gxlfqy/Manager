--病理结果表
create table Pathological_Results
(
ID int primary key not null,		-- 病人ID
Path_Number varchar(20) ,			--病理号码
Check_Date date ,					--日期
Parts varchar(20) ,					--部位
Size float,							--大小
The_Longest_Path float,				--最长径
ClassiFication varchar(50),			--分型
Differentiation	varchar(50),		--分化程度
Bronchial_Margin varchar(50),		--支气管切缘
Vascular_Line	varchar(50),		--脉管切缘
Adenocarcinoma	varchar(100),		--腺癌
Lymphatic varchar(50),				--血管淋巴管
Pleura	varchar(50),				--胸膜
Nerve	varchar(50),				--神经
Emphysema	varchar(50),			--肺气肿
Interstial_Fibrosis varchar(50),	--间质纤维化
Lymph_Node_Metastasis varchar(50),	--淋巴结转移
Inflammation varchar(50),			--炎症
Details	Text,						--详细信息
Case_Staging varchar(200)			--病例分期
)  

--免疫组化表
create table Immunohistochemistry
(
ID int primary key not null,		--病人ID
EGFR  varchar(50),					--EGFR
CK7   varchar(50),					--CK7
TTF_1 varchar(50),					--TTF-1
CEA	  varchar(50),					--CEA
Vim	  varchar(50),					--Vim
CD34  varchar(50),					--CD34
Ki67  varchar(50),					--Ki67
Naspin_A varchar(50),				--Naspin-A
P63		 varchar(50),				--P63
DNA_Test varchar(50),				--基因检测
EML4_ALK varchar(50)				--EML4-ALK
)
