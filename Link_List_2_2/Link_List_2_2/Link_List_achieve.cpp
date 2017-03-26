#include "Link_List_H.h"
#include<stdio.h>
#include"malloc.h"
#include"stdlib.h"
//������ĳ�ʼ��
Status InitList(LinkList &L) {
	//����һ��������
	L = new LNode;	//�����½ڵ���Ϊͷ�ڵ㣬��ͷָ��Lָ��ͷ�ڵ�
	L->next = NULL;	//ͷ�ڵ��ָ�����ÿ�
	return OK;
}
//������Ĵ�������巨
LinkList CreateList_Rear() {
	int len;
	int val;
	LinkList pHead = (LinkList)malloc(sizeof(LNode));	//����ͷ�ڵ�
	pHead->next = NULL;
	LinkList rear = pHead;								//β�ڵ�ָ��ͷ�ڵ�
	printf("�����봴������ĳ���:");
	scanf("%d", &len);
	for (int i = 0; i < len; i++) {
		LinkList pNew = (LinkList)malloc(sizeof(LNode));//�����½ڵ�
		printf("�������%d���ڵ�����ݣ�", i + 1);
		scanf("%d", &val);
		pNew->data = val;								//������ֵ
		pNew->next = NULL;
		rear->next = pNew;								//���½ڵ����β�ڵ�rear֮��
		rear = pNew;									//rearָ���µ�β�ڵ�pNew
	}
	return pHead;
}
//������Ĵ�����ǰ�巨
LinkList CreateList_Front() {
	int len;
	int val;
	LinkList pHead = (LinkList)malloc(sizeof(LNode));
	pHead->next = NULL;
	printf("�����봴������ĳ��ȣ�");
	scanf("%d", &len);
	for(int i = 0; i < len; i++) {
		LinkList pNew = (LinkList)malloc(sizeof(LNode));
		printf("�������%d���ڵ�����ݣ�", i + 1);
		scanf("%d", &val);
		pNew->data = val;
		pNew->next = pHead->next;
		pHead->next = pNew;
	}
	return pHead;
}
//�������ȡֵ
Status GetElem(LinkList L, int i, ElemType &e) {
	//�ڴ�ͷ�ڵ�ĵ�����L�и������i��ȡԪ�ص�ֵ����e����L�е�i������Ԫ�ص�ֵ
	LinkList p = L->next;	//��ʼ����pָ���׽ڵ�
	int j = 1;				//������j��ֵ��Ϊ1
	while (p && j < i) {
		//˳�������ɨ�裬ֱ��pΪ�������pָ���i��Ԫ��
		p = p->next;
		j++;
	}
	if (!p || j > i){
		//i��ȡֵ���Ϸ���i>n��n<=0
		printf("ERROR index!");
		return ERROR;	
	}
	e = p->data;			//ȡֵ
	return OK;
}

//������İ�ֵ����
int LocateElem(LinkList L, ElemType e) {
	//�ڴ�ͷ�ڵ�ĵ�����L�в���ֵΪe��Ԫ��
	int cout = 1;
	LinkList p = L->next;	//��ʼ����pָ��ͷ�ڵ�
	while (p && p->data != e) {
		p = p->next;
		cout++;
	}
	return cout;
}

//������ĳ���
int LinkList_Length(LinkList L) {
	int len = 0;
	LinkList p = (LinkList)malloc(sizeof(LNode));
	p = L->next;
	while (p != NULL) {
		p = p->next;
		len++;
	}
	return len;
}

//����������
void traverse_LinkList(LinkList L) {
	LinkList p = (LinkList)malloc(sizeof(LNode));
	p = L->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

//�жϵ������Ƿ�Ϊ��
Status isEmpty(LinkList L) {
	if (L->next == NULL) {
		return OK;
	}
	else return ERROR;
}

//������Ĳ���
Status ListInsert(LinkList &L, int i, ElemType e) {
	//��ͷ�ڵ�ΪL�ĵ������еĵ�i��λ�ò���ֵΪe���½ڵ�
	LinkList p = (LinkList)malloc(sizeof(LNode));
	int j = 0;
	p = L->next;
	while (p && (j < i - 1)) {
		p = p->next;
		j++;
	}
	//�ж�index�Ƿ����
	if (!p || j > i - 1)return ERROR;

	LinkList pNew = (LinkList)malloc(sizeof(LNode));
	pNew->data = e;
	pNew->next = p->next;	//�½ڵ��ָ����ָ��p����һ���ڵ�
	p->next = pNew;			//��p��ָ����ָ���½ڵ�pNew
	return OK;
}

//�������ɾ��
Status ListDelete(LinkList &L, int i, ElemType &e) {
	//��ͷ�ڵ�ΪL�������У�ɾ����i��Ԫ��
	LinkList p = (LinkList)malloc(sizeof(LNode));
	int j = 0;
	p = L;
	//���ҵ�i-1���ڵ㣬pָ��ýڵ�
	while ((p->next) && (j < i - 1)) {
		p = p->next;
		j++;
	}
	//�ж�i�Ƿ����
	if (!(p->next) || (j > i - 1))return ERROR;
	LinkList temp = (LinkList)malloc(sizeof(LNode));	//��ʼ����ʱ�ڵ㣬��ɾ�ڵ�Ϊp����һ���ڵ㡣
	e = p->next->data;
	temp = p->next;										//��ʱ���汻ɾ�ڵ�ĵ�ַ�Ա��ͷ�
	p->next = temp->next;								//�ı�ɾ���ڵ��ǰ������ָ����
	free(temp);
	return OK;
}
