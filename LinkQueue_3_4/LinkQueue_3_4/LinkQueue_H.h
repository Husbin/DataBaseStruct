#pragma once
typedef int ElemType;
typedef bool Status;

#define OK true;
#define ERROR false;
#define OVERFLOW -1;

//------------------���е���ʽ�洢�ṹ-------------------------
typedef struct QNode {
	ElemType data;
	struct QNode *next;
}QNode , *QueuePtr;

typedef struct {
	QueuePtr front;			//����ͷָ��
	QueuePtr rear;			//����βָ��
}LinkQueue;

//��ʼ����ʽ����
Status InitQueue(LinkQueue &Q);
//��ʽ���е����
Status EnQueue(LinkQueue &Q, ElemType e);
//��ʽ���еĳ���
Status DeQueue(LinkQueue &Q, ElemType &e);
//ȡ��ʽ���е�ͷԪ��
ElemType GetHead(LinkQueue Q);
//��ʽ���еı���
Status traverse_LinkQueue(LinkQueue Q);



