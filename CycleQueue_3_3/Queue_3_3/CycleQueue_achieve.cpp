#include "CycleQueue_H.h"
#include<stdio.h>
#include<stdlib.h>

Status InitQueue(SqQueue &Q) {
	Q.base = new QElemType[MAXQSIZE];		//Ϊ���з���һ���������ΪMAXQSIZE������ռ�
	if (!Q.base) {
		printf("�ڴ����ʧ�ܣ�\n");
		exit(OVERFLOW);
	}
	Q.front = Q.rear = 0;					//ͷָ���βָ����Ϊ�㣬����Ϊ��
	return OK;
}

int QueueLength(SqQueue Q) {
	//����Q��Ԫ�ظ����������еĳ���
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

Status EnQueue(SqQueue &Q, QElemType e) {
	//����Ԫ��eΪQ���µĶ�βԪ��
	if ((Q.rear + 1) % MAXQSIZE == Q.front) {
		printf("ѭ������������\n");
		return ERROR;
	}
	Q.base[Q.rear] = e;						//��Ԫ�ز����β
	Q.rear = (Q.rear + 1) % MAXQSIZE;		//��βָ���һ
	return OK;
}

Status DeQueu(SqQueue &Q, QElemType &e) {
	//ɾ��Q�Ķ�ͷԪ�أ���e����
	if (Q.front == Q.rear) {
		printf("�ӿգ�\n");
		return ERROR;
	}
	e = Q.base[Q.front];					//�����ͷԪ��
	Q.front = (Q.front + 1) % MAXQSIZE;		//��ͷָ���һ
	return OK;
}

QElemType getHead(SqQueue Q) {
	//����Q�Ķ�ͷԪ�أ����޸Ķ�ͷָ��
	if (Q.front != Q.rear)			//���зǿ�
		return Q.base[Q.front];		//���ض�ͷԪ�ص�ֵ����ͷָ�벻��
}

Status traverse_Queue(SqQueue Q) {
	printf("ѭ�����б����������:\n");
	if (Q.front == Q.rear) {
		printf("�ӿգ�\n");
		return ERROR;
	}
	int count = Q.front;
	while (count != Q.rear) {
		printf("%d  ", Q.base[count]);
		count = (count + 1) % MAXQSIZE;
	}
	printf("\n");
}