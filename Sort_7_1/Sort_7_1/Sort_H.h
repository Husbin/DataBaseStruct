#pragma once


#define MAXSIZE 10		//˳������󳤶�
#define Status bool		
#define OK true
#define ERROR false
typedef struct STUDENT {
	char no[8];
	char name[20];
	int age;
	int score;
}Student , *pStudent;

typedef struct {
	Student s[MAXSIZE+1];	//s[0]���û����ڱ���Ԫ
	int length;
}SqList;
//����ѧ����Ϣ
Status InputStuMsg(SqList &SL);
//���ѧ����Ϣ
Status TraverseStuMsg(SqList SL);
//��ȡѧ�����ݳ���
Status GetLength(SqList &SL);

//���һ��������������
Status GetSortSatus(SqList SL);


//ֱ�Ӳ�������
void InsertSort(SqList &SL);


//�۰��������
void BInsertSort(SqList &SL);