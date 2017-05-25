#include"Sort_H.h"
#include<stdio.h>
#include<string.h>

//����ѧ����Ϣ
Status InputStuMsg(SqList &SL) {
	GetLength(SL);		//��SL.length��ֵ
	if (SL.s == NULL) {
		printf("ѧ����Ϊ�գ����ȳ�ʼ����");
		return ERROR;
	}
	strcpy(SL.s[1].no, "111");
	strcpy(SL.s[1].name, "qqq");
	SL.s[1].age = 11;
	SL.s[1].score = 11;

	strcpy(SL.s[2].no, "999");
	strcpy(SL.s[2].name, "ooo");
	SL.s[2].age = 99;
	SL.s[2].score = 99;

	strcpy(SL.s[3].no, "555");
	strcpy(SL.s[3].name, "ttt");
	SL.s[3].age = 55;
	SL.s[3].score = 55;

	strcpy(SL.s[4].no, "444");
	strcpy(SL.s[4].name, "rrr");
	SL.s[4].age = 44;
	SL.s[4].score = 44;

	strcpy(SL.s[5].no, "888");
	strcpy(SL.s[5].name, "iii");
	SL.s[5].age = 88;
	SL.s[5].score = 88;

	strcpy(SL.s[6].no, "666");
	strcpy(SL.s[6].name, "yyy");
	SL.s[6].age = 66;
	SL.s[6].score = 66;

	strcpy(SL.s[7].no, "222");
	strcpy(SL.s[7].name, "www");
	SL.s[7].age = 22;
	SL.s[7].score = 22;

	strcpy(SL.s[8].no, "777");
	strcpy(SL.s[8].name, "uuu");
	SL.s[8].age = 77;
	SL.s[8].score = 77;

	strcpy(SL.s[9].no, "100");
	strcpy(SL.s[9].name, "ppp");
	SL.s[9].age = 100;
	SL.s[9].score = 100;

	strcpy(SL.s[10].no, "333");
	strcpy(SL.s[10].name, "eee");
	SL.s[10].age = 33;
	SL.s[10].score = 33;

	//for (int i = 1; i < SL.length; i++) {
	//	printf("�������%d��ѧ������Ϣ��\n", i);
	//	//scanf("%*[\t\n\r]");				//���io����
	//	printf("������ѧ�ţ�");
	//	//scanf("%*[\t\n\r]");
	//	scanf("%s", SL.s[i].no);
	//	printf("������������");
	//	//scanf("%*[\t\n\r]");
	//	scanf("%s", SL.s[i].name);
	//	printf("���������䣺");
	//	//scanf("%*[\t\n\r]");
	//	scanf("%d", &SL.s[i].age);
	//	printf("������ɼ���");
	//	//scanf("%*[\t\n\r]");
	//	scanf("%d", &SL.s[i].score);
	//}
	return OK;
}
//���ѧ����Ϣ
Status TraverseStuMsg(SqList SL) {
	if (SL.s == NULL) {
		printf("ѧ����Ϊ�գ����ȳ�ʼ����");
		return ERROR;
	}
	printf("--------------------���ѧ����Ϣ����----------------------------\n");
	printf("ѧ��\t\t����\t\t����\t\t����\t\t\n");
	for (int i = 1; i < SL.length; i++) {	
		printf("%s\t\t%s\t\t%d\t\t%d\t\t\n" , SL.s[i].no,SL.s[i].name,SL.s[i].age,SL.s[i].score);
	}
}

//��ȡѧ�����ݳ���
Status GetLength(SqList &SL) {
	if (SL.s == NULL) {
		printf("ѧ����Ϊ�գ����ȳ�ʼ����");
		return ERROR;
	}
	else {
		SL.length = MAXSIZE + 1;
		//printf("%d\n", SL.length);
	}
}
//���һ��������������
Status GetSortSatus(SqList SL) {
	if (SL.s == NULL) {
		printf("ѧ����Ϊ�գ����ȳ�ʼ����");
		return ERROR;
	}
	printf("������������\n");
	for (int i = 1; i < SL.length; i++) {
		printf("%d\t", SL.s[i].score);
	}
	printf("\n");
}
//��Ϊ��������
//ֱ�Ӳ�������
void InsertSort(SqList &SL) {
	if (SL.s == NULL) {
		printf("ѧ����Ϊ�գ����ȳ�ʼ����");
		return ;
	}
	for (int i = 2; i < SL.length; i++) {
		int j;
		if (SL.s[i].score < SL.s[i - 1].score) {		//"<"���轫s[i]���������ӱ�
			SL.s[0] = SL.s[i];							//��������ļ�¼�ݴ浽��������
			SL.s[i] = SL.s[i - 1];						//��s[i - 1]����
			for (j = i - 2; SL.s[0].score < SL.s[j].score; j--) {	//�Ӻ���ǰѰ�Ҳ���λ��
				SL.s[j + 1] = SL.s[j];					//��¼������ƣ�ֱ���ҵ�����λ��
			}
			SL.s[j + 1] = SL.s[0];						//��s[0]��ԭr[i]�����뵽��ȷλ��
		}		
		GetSortSatus(SL);
	}
}

//�۰��������
void BInsertSort(SqList &SL) {
	if (SL.s == NULL) {
		printf("ѧ����Ϊ�գ����ȳ�ʼ����");
		return;
	}
	//��˳���SL���۰��������
	for (int i = 2; i < SL.length; i++) {
		SL.s[0] = SL.s[i];								//��������ļ�¼�ݴ浽��������
		int low = 1;									//�ò��������ֵ
		int high = i - 1;
		while (low <= high) {							//��r[low...high]���۰���Ҳ����λ��
			int m = (low + high) / 2;					//�۰�
			//�������ǰһ�ӱ�
			if (SL.s[0].score < SL.s[m].score)high = m - 1;
			//������ں�һ�ӱ�
			else low = m + 1;
		}
		//��¼����
		for (int j = i - 1; j >= high + 1; j--) {
			SL.s[j + 1] = SL.s[j];
		}
		//��SL.s[0]��ԭSL.s[i]�����뵽��ȷ��λ��
		SL.s[high + 1] = SL.s[0];
		GetSortSatus(SL);
	}
}
