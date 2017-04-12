#include "DancePartner_H.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

Status InitQueue(SqQueue &Q) {
	Q.base = new Person[MAXSIZE];
	if (!Q.base) {
		printf("�ڴ����ʧ�ܣ�\n");
		exit(OVERFLOW);
	}
	Q.front = Q.rear = 0;
	return OK;
}

Status EnQueue(SqQueue &Q , Person p) {
	//�ж��Ƿ����
	if ((Q.rear + 1) % MAXSIZE == Q.front) {
		printf("������\n");
		return ERROR;
	}

	strcpy(Q.base[Q.rear].name, p.name);
	Q.base[Q.rear].sex = p.sex;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return OK;
}

Status DeQueue(SqQueue &Q, Person &p) {
	//�ж��Ƿ�ӿ�
	if (Q.rear == Q.front) {
		printf("�ӿգ�\n");
		return ERROR;
	}
	strcpy(p.name , Q.base[Q.front].name);
	p.sex = Q.base[Q.front].sex;
	Q.front = (Q.front + 1) % MAXSIZE;
	return OK;
}

Status QueueEmpty(SqQueue Q) {
	if (Q.front == Q.rear)
		return OK;
	else return ERROR;
}

Person GetHead(SqQueue Q) {
	if (Q.front != Q.rear)
		return Q.base[Q.front];
}

void DancePartner(Person dancer[], int num) {
	//�ṹ����dancer�д���������Ů��num�������������
	SqQueue Mdancers, Fdancers;	//�ֱ�����ʿ��Ůʿ����߶���
	InitQueue(Mdancers);
	InitQueue(Fdancers);
	Person p;
	for (int i = 0; i < num; i++) {
		p = dancer[i];
		if (p.sex == 'F') {
			//����Ů��
			EnQueue(Fdancers, p);
		}
		else {
			//�����ж�
			EnQueue(Mdancers, p);
		}

		//printf("The dancing partners are : \n");
		while (!QueueEmpty(Fdancers) && !QueueEmpty(Mdancers)) {
			//���������Ů��������
			DeQueue(Fdancers, p);
			printf("Ů�� �� %s ", p.name);
			DeQueue(Mdancers, p);
			printf("�а� �� %s ", p.name);
			printf("\n");
		}
	}
	if (!QueueEmpty(Mdancers)) {
		p = GetHead(Mdancers);
		printf("The first man is %s!\n", p.name);
	}
	if (!QueueEmpty(Fdancers)) {
		p = GetHead(Fdancers);
		printf("The first female is %s!\n", p.name);
	}
}