#pragma once

#define MAXQSIZE 100		//���п��ܿ��ܴﵽ����󳤶�
#define OK true
#define ERROR false
#define OVERFLOW -1
typedef bool Status;
typedef int QElemType;

//------------���е�˳��洢�ṹ--------------
typedef struct {
	QElemType *base;		//�洢�ռ�Ļ���ַ
	int front;				//ͷָ��
	int rear;				//βָ��
}SqQueue;

//ѭ�����еĳ�ʼ��
Status InitQueue(SqQueue &Q);

//��ѭ�����еĳ���
int QueueLength(SqQueue Q);

//���
Status EnQueue(SqQueue &Q, QElemType e);

//����
Status DeQueu(SqQueue &Q, QElemType &e);

//ȡѭ�����ж�ͷԪ��
QElemType getHead(SqQueue Q);

//����ѭ������
Status traverse_Queue(SqQueue Q);
