create database PatientInfo
create table Base_Info(	--基本信息
ID int primary key not null,
Name varchar(15) not null,
Age smallint,
History_Of_Smoke varchar(5), --吸烟史
Number_PerYear smallint, --数量(包/年)
Clinical_Symptoms varchar(5), --临床症状
Caugh varchar(5), --咳嗽
Hemoptysis varchar(5), --咯血
Family_History_Of_Cancer varchar(5), --肿瘤家族史
Family_History_Of_LungCancer varchar(5), --肺癌家族史
History_Of_Other_Malignancies varchar(5), --其他恶性肿瘤病史
Emphysema varchar(5), --肺气肿
Pulmonary_Tuberculosis varchar(5), --肺结核
Sand_Lung varchar(5), --砂肺
Hypertension varchar(5), --高血压
Heart_Disease varchar(5), --心脏病
Cerebrovascular_Diseases varchar(5), --脑血管疾病
Diabetes varchar(5), --糖尿病
Nephropathy varchar(5), --肾病
Other_Special_cases varchar(100) --其他特殊病例
);
select* from Base_Info;


create table CT_Check(	--CT检查
ID int primary key not null,
CT_Number varchar(30) not null, --CT号码
Check_Date Date not null, --CT日期
CT_Enhance varchar(5), --CT增强
Machine_Name varchar(20), --机器名称
Scanning_Thickness float --扫描厚度(mm)
);
select* from CT_Check;


create table Pulmonary_nodule_Record(	--肺结节记录
ID int primary key not null,
Long_Path float, --长径
Short_Path float, --短径
Size float, --大小
Density float, --密度
Shape varchar(15), --形状
Position varchar(15), --部位
Peripheral_emphysema varchar(20), --周围肺气肿
Mlutiple_Nodules varchar(20), --多发结节
Pleural_Contact varchar(20), --胸膜接触
Skin_Needling varchar(20), --毛刺
Brancch varchar(20), --分页
Partial_Solid_Input varchar(150) --部分实性录入
);
select* from Pulmonary_nodule_Record;