#include"DublexLink_List_H.h"
#include"malloc.h"
#include"stdlib.h"
#include"stdio.h"

PDULNODE create_dubleLink_List() {
	int len;
	int val;
	PDULNODE pHead = (PDULNODE)malloc(sizeof(DULNODE));
	if (pHead == NULL) {
		printf("˫��������ʧ�ܣ�\n");
		exit(-1);
	}
	pHead->prior = NULL;
	printf("������Ҫ�����Ľڵ������");
	scanf("%d", &len);
	PDULNODE pTail = pHead;
	pTail->pnext = NULL;
	pTail->prior = NULL;
	for (int i = 0; i < len; i++) {
		PDULNODE pNew = (PDULNODE)malloc(sizeof(DULNODE));
		if (pNew == NULL) {
			printf("�½ڵ㴴��ʧ�ܣ�\n");
			exit(-1);
		}
		printf("�������%d���ڵ�����ݣ�", i + 1);
		scanf("%d", &val);
		pNew->data = val;
		pTail->pnext = pNew;
		pNew->prior = pTail;
		pNew->pnext = NULL;
		pTail = pNew;
	}
	return pHead;
}

void traverse_duleLink_List(PDULNODE pHead) {
	printf("˫������������£�\n");
	PDULNODE p = pHead->pnext;
	if (p == NULL) {
		printf("˫������Ϊ�ա�\n");
	}
	int i = 1;
	while (p != NULL) {
		printf("��%d���ڵ�Ľ��������%d\n", i, p->data);
		if (p->prior != pHead) {		
			printf("��%d���ڵ��ǰ�����������%d\n", i, p->prior->data);
		}
		else {
			printf("��%d���ڵ��ǰ�����������NULL\n", i);
		}
		if (p->pnext != NULL) {
			printf("��%d���ڵ�ĺ������������%d\n", i, p->pnext->data);
		}
		else {
			printf("��%d���ڵ�ĺ������������NULL\n", i);
		}
		p = p->pnext;
		i++;
	}
	printf("\n");
}

Status insertElem(PDULNODE pHead, int index, ElemType e) {
	PDULNODE p = (PDULNODE)malloc(sizeof(DULNODE));
	int count = 0;
	p = pHead->pnext;
	while (p && count < index - 1) {
		count++;
		p = p->pnext;
	}
	if (!p || count > index - 1)return ERROR;
	PDULNODE pNew = (PDULNODE)malloc(sizeof(DULNODE));
	pNew->data = e;
	/*pNew->pnext = p->pnext;
	pNew->prior = p;
	p->pnext = pNew;*/
	pNew->prior = p->prior;
	p->prior->pnext = pNew;
	pNew->pnext = p;
	p->prior = pNew;
	return OK;
}

Status deleteElem(PDULNODE &pHead, int index) {
	PDULNODE p = (PDULNODE)malloc(sizeof(DULNODE));
	int count = 0;
	p = pHead->pnext;
	while (p && count < index - 1) {
		count++;
		p = p->pnext;
	}
	if (!p || count > index - 1)return ERROR;
	p->prior->pnext = p->pnext;		//�޸ı�ɾ���ڵ��ǰ�����ĺ��ָ��
	p->pnext->prior = p->prior;		//�޸ı�ɾ���ڵ�ĺ�̽ڵ��ǰ��ָ��
	free(p);
	return OK;
}