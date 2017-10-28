create database PatientInfo
create table Base_Info(	--������Ϣ
ID int primary key not null,
Name varchar(15) not null,
Age smallint,
History_Of_Smoke varchar(5), --����ʷ
Number_PerYear smallint, --����(��/��)
Clinical_Symptoms varchar(5), --�ٴ�֢״
Caugh varchar(5), --����
Hemoptysis varchar(5), --��Ѫ
Family_History_Of_Cancer varchar(5), --��������ʷ
Family_History_Of_LungCancer varchar(5), --�ΰ�����ʷ
History_Of_Other_Malignancies varchar(5), --��������������ʷ
Emphysema varchar(5), --������
Pulmonary_Tuberculosis varchar(5), --�ν��
Sand_Lung varchar(5), --ɰ��
Hypertension varchar(5), --��Ѫѹ
Heart_Disease varchar(5), --���ಡ
Cerebrovascular_Diseases varchar(5), --��Ѫ�ܼ���
Diabetes varchar(5), --����
Nephropathy varchar(5), --����
Other_Special_cases varchar(100) --�������ⲡ��
);
select* from Base_Info;


create table CT_Check(	--CT���
ID int primary key not null,
CT_Number varchar(30) not null, --CT����
Check_Date Date not null, --CT����
CT_Enhance varchar(5), --CT��ǿ
Machine_Name varchar(20), --��������
Scanning_Thickness float --ɨ����(mm)
);
select* from CT_Check;


create table Pulmonary_nodule_Record(	--�ν�ڼ�¼
ID int primary key not null,
Long_Path float, --����
Short_Path float, --�̾�
Size float, --��С
Density float, --�ܶ�
Shape varchar(15), --��״
Position varchar(15), --��λ
Peripheral_emphysema varchar(20), --��Χ������
Mlutiple_Nodules varchar(20), --�෢���
Pleural_Contact varchar(20), --��Ĥ�Ӵ�
Skin_Needling varchar(20), --ë��
Brancch varchar(20), --��ҳ
Partial_Solid_Input varchar(150) --����ʵ��¼��
);
select* from Pulmonary_nodule_Record;