#pragma once
typedef bool Status;

#define MAXSIZE 100		//ѧ���������
#define OK true
#define ERROR false
#define OVERFLOW -1


//ѧ����Ϣ�Ķ���
typedef struct {
	char no[8];			//8λѧ��
	char name[20];		//����
	int price;			//�ɼ�
}Student;

//˳���Ķ���
typedef struct {
	Student *elem;		//ָ������Ԫ�صĻ���ַ
	int length;			//���Ա�ĵ�ǰ����
}SqList;

//����Ķ���
typedef struct LNode{
	Student data;		//������
	struct LNode *next;	//ָ����
}LNode ,*LinkList;

//��ʼ��˳���
Status InitSqList(SqList &SL);
//¼��ѧ����Ϣ
Status InputInformation(SqList &SL);
//����ѧ����Ϣ
Status TraverseInformation(SqList SL);
//�����������в��ң����ش�ѧ����ѧ�źͳɼ�
Status SearchByName(SqList SL, char* name);
//����ָ����λ�ÿɷ�����Ӧ��ѧ����Ϣ��ѧ�ţ��������ɼ���
Status SerchByPos(SqList SL, int pos);
//����һ��ѧ����Ϣ�����뵽����ָ����λ��
Status InsertInformation(SqList &SL, int pos);
//ɾ��ָ��λ�õ�ѧ����¼(pos - 1λ)
Status DeleteInformation(SqList &SL, int pos);
//ͳ�Ʊ���ѧ������
int SqListLength(SqList SL);

//��ʼ������
Status InitLinkList(LinkList &L);