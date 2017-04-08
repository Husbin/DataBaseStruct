#include "LinkQueue_H.h"
#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"


//���г�ʼ��
Status InitQueue(LinkQueue &Q) {
	//����һ���ն���
	Q.front = Q.rear = new QNode;		//�����½ڵ���Ϊͷ�ڵ㣬��ͷ�Ͷ�βָ��ָ��νڵ�
	Q.front->next = NULL;				//ͷ�ڵ��ָ�����ÿ�
	return OK;
}

//���
Status EnQueue(LinkQueue &Q, ElemType e) {
	//��ʽ������Ӳ���Ҫ�ж��Ƿ�������ֻ��Ҫ����һ���ڵ㡣
	//����Ԫ��eΪQ���µĶ�βԪ�ء�
	//QNode p;
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));//Ϊ���Ԫ�ط���ڵ�ռ䣬��ָ��pָ��
	p->data = e;								//���½ڵ����������Ϊe
	p->next = NULL;								//���½ڵ�����β
	Q.rear->next = p;
	Q.rear = p;									//�޸Ķ�βָ��
	return OK;
}

//����
Status DeQueue(LinkQueue &Q, ElemType &e) {
	if (Q.front == Q.rear) {
		printf("�ӿ�!\n");
		return ERROR;
	}
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	p = Q.front->next;							//pָ���ͷԪ��
	e = p->data;								//e�����ͷԪ�ص�ֵ
	Q.front->next = p->next;					//�޸�ͷָ��
	if (Q.rear == p)Q.rear = Q.front;			//���һ��Ԫ�ر�ɾ����βָ��ָ��ͷ�ڵ�
	free(p);									//�ͷ�ԭ��ͷԪ�ؿռ�
	return OK;
}
//ȡ��ͷԪ��
ElemType GetHead(LinkQueue Q) {
	//���ض�ͷԪ�أ����޸Ķ�ͷָ��
	if (Q.front != Q.rear)
		return Q.front->next->data;
}
//����
Status traverse_LinkQueue(LinkQueue Q) {
	printf("��ʽ���б���������£�\n");
	if (Q.front == Q.rear) {
		printf("�ӿգ�\n");
		return ERROR;
	}
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	p = Q.front;
	while (p != Q.rear) {
		printf("%d ", p->next->data);
		p = p->next;
	}
	printf("\n");
}