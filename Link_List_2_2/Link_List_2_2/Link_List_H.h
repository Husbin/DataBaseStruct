#pragma once
#define OK true;
#define ERROR false;
typedef int ElemType;
typedef bool Status;


/*---������Ĵ洢�ṹ---*/
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode , *LinkList;


/*---�������������---*/

//������ĳ�ʼ��
Status InitList(LinkList &L);
//������Ĵ�������巨����ʱ�临�Ӷ�O��n��
LinkList CreateList_Rear();
//������Ĵ�����ǰ�巨��,ʱ�临�Ӷ�O��n��
LinkList CreateList_Front();
//�������ȡֵ,ʱ�临�Ӷ�ΪO��n��
Status GetElem(LinkList L, int i, ElemType &e);
//������İ�ֵ����,ʱ�临�Ӷ�ΪO��n��
int LocateElem(LinkList L, ElemType e);
//������ĳ���
int LinkList_Length(LinkList L);
//����������
void traverse_LinkList(LinkList L);
//�жϵ������Ƿ�Ϊ��
Status isEmpty(LinkList L);
//������Ĳ���ʱ�临�Ӷ�ΪO��n��
Status ListInsert(LinkList &L, int i, ElemType e);
//�������ɾ��,ʱ�临�Ӷ�ΪO��n��
Status ListDelete(LinkList &L, int i,ElemType &e);

