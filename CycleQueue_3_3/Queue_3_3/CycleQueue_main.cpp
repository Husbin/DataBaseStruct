#include"CycleQueue_H.h"
#include<stdio.h>

int main() {
	SqQueue Q;
	int length;	
	QElemType val;
	InitQueue(Q);
	EnQueue(Q, 1);
	EnQueue(Q, 2);
	EnQueue(Q, 3);
	EnQueue(Q, 4);
	EnQueue(Q, 5);
	length = QueueLength(Q);
	traverse_Queue(Q);
	printf("ѭ�����г��ȣ�%d\n", length);
	val = getHead(Q);
	printf("���е�ͷԪ��Ϊ��%d \n" , val);

	DeQueu(Q, val);
	printf("���ӵ�Ԫ��Ϊ��%d\n", val);
	traverse_Queue(Q);
	printf("ѭ�����г��ȣ�%d", length);
	val = getHead(Q);
	return OK;
}