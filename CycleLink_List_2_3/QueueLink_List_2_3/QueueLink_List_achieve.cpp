#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include"QueueLink_List_H.h"

PNODE create_QueueList() {
	int len;
	int val;
	PNODE pHead = (PNODE)malloc(sizeof(LNode));
	if (pHead == NULL) {
		printf("�ڴ����ʧ�ܣ�ѭ��������ʧ�ܡ�\n");
		exit(-1);
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;//����ڵ����Ϊ0�����������
	printf("�����봴��ѭ������Ľڵ�����");
	scanf("%d", &len);
	for (int i = 0; i < len; i++) {
		PNODE pNew = (PNODE)malloc(sizeof(LNode));
		if (pNew == NULL) {
			printf("�ڴ����ʧ�ܣ��½ڵ㴴��ʧ�ܡ�\n");
			exit(-1);
		}
		printf("�������%d���ڵ�����ݣ�", i + 1);
		scanf("%d", &val);
		pNew->data = val;
		pTail->pNext = pNew;//��巨�����½ڵ�嵽β�ڵ����
		pNew->pNext = pHead;//�½ڵ��ָ����ָ��ͷ�ڵ�
		pTail = pNew;		//�����ƶ���β�ڵ�����ָ�����һ���ڵ㡣
	}
	return pHead;
}

void traverse_QueueList(PNODE pHead) {
	int count = 0;
	printf("����������£�\n");
	if (pHead->pNext == NULL) {
		printf("ѭ������Ϊ�ա�\n");
		exit(-1);
	}
	PNODE p = pHead->pNext;
	while (p != pHead) {
		printf("%d ", p->data);
		p = p->pNext;
		count++;
	}
	printf("\n");
}