#pragma once

#define OK true
#define ERROR false
#define OVERFLOW -1
#define MAXSIZE 100

typedef bool Status;

//--------------------�����ߵĸ�����Ϣ--------------

typedef struct {
	char name[20];			//����
	char sex;				//�Ա�F��ʾŮ�ԣ�M��ʾ����
}Person;


//---------------------���е�˳��洢�ṹ--------------
typedef struct{
	Person *base;			//����������Ԫ�ص�����ΪPerson
	int front;				//��ͷָ��
	int rear;				//��βָ��
}SqQueue;

//SqQueue Mdancers, Fdancers;	//�ֱ�����ʿ��Ůʿ����߶���

Status InitQueue(SqQueue &Q);	//��ʼ��ջ

Status EnQueue(SqQueue &Q , Person p);		//���

Status DeQueue(SqQueue &Q , Person &p);		//����

Status QueueEmpty(SqQueue Q);				//�ж϶����Ƿ�Ϊ��

Person GetHead(SqQueue Q);					//ȡ��ͷԪ��

void DancePartner(Person dancer[], int num);//�ṹ����dancer�д���������Ů��num�������������

