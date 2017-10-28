--��������
create table Pathological_Results
(
ID int primary key not null,		-- ����ID
Path_Number varchar(20) ,			--�������
Check_Date date ,					--����
Parts varchar(20) ,					--��λ
Size float,							--��С
The_Longest_Path float,				--���
ClassiFication varchar(50),			--����
Differentiation	varchar(50),		--�ֻ��̶�
Bronchial_Margin varchar(50),		--֧������Ե
Vascular_Line	varchar(50),		--������Ե
Adenocarcinoma	varchar(100),		--�ٰ�
Lymphatic varchar(50),				--Ѫ���ܰ͹�
Pleura	varchar(50),				--��Ĥ
Nerve	varchar(50),				--��
Emphysema	varchar(50),			--������
Interstial_Fibrosis varchar(50),	--������ά��
Lymph_Node_Metastasis varchar(50),	--�ܰͽ�ת��
Inflammation varchar(50),			--��֢
Details	Text,						--��ϸ��Ϣ
Case_Staging varchar(200)			--��������
)  

--�����黯��
create table Immunohistochemistry
(
ID int primary key not null,		--����ID
EGFR  varchar(50),					--EGFR
CK7   varchar(50),					--CK7
TTF_1 varchar(50),					--TTF-1
CEA	  varchar(50),					--CEA
Vim	  varchar(50),					--Vim
CD34  varchar(50),					--CD34
Ki67  varchar(50),					--Ki67
Naspin_A varchar(50),				--Naspin-A
P63		 varchar(50),				--P63
DNA_Test varchar(50),				--������
EML4_ALK varchar(50)				--EML4-ALK
)
