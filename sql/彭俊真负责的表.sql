create table Lungs_Other_Find  --�β���������
(  
ID int primary key not null, --ID,�����Ĺؼ���primary key,�ǿ�
Emphysema varchar(10), --������ 
Interstitial_Fibrosis varchar(10), --�����Է���ά��  
Bronchial_Dilatation varchar(10),	--֧��������
Old_Tuberculosis varchar(10),		--�¾��Էν��
Pleural_Calcification varchar(10),	--��Ĥ�ƻ�
Pleural_Effusion varchar(10),	--��ǻ��Һ
);
create table Chest_Other_Check	--�ز��������
(
ID int primary key not null,	--ID���������ǿ�
Blood_Tumor_Markers varchar(10),	--ѪҺ�����������
Respiratory_Function varchar(10),	--�������ܼ��
If_Any	varchar(10),	--����,ѡ�����������쳣
CEA varchar(10),		--���ԣ�����
CA199 varchar(10),		--���ԣ�����
Cyfra21_1 varchar(10),	--Cyfra21-1,���ԣ�����
NSE varchar(10),		--���ԣ�����
PET_CT varchar(10),		--��,��
If_Any_Text text,		--���У��ı�
Lymph_Nodes varchar(10),	--�ܰͽ�
Transference varchar(10),	--ת��
);
create table Surgery	--���������
(
ID int primary key not null, --ID���������ǿ�
Surgery_Date date,		--����
Intervals text,		--���ʱ��
Operation_Name varchar(10),	--��������
Lymph_Nodes_A varchar(10),		--�ܰͽᣬ��죬��ɨ
Lymph_Nodes_B varchar(10)		--�ܰͽᣬ���ԣ�����
);