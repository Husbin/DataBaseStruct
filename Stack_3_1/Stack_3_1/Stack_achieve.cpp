#include "Stack_H.h"
#include"stdio.h"
#include"stdlib.h"


//��ʼ��
Status InitStack(SQ_STACK &S) {
	S.base = new SElemType[MAXSIZE];		//Ϊ˳��ջ��̬����һ���������ΪMAXSIZE������ռ�
	if (!S.base) {
		printf("�ڴ����ʧ�ܣ�\n");
		exit(OVERFLOW);
	}
	S.top = S.base;						//top��ʼ��Ϊbase����ջ
	S.stacksize = MAXSIZE;				//stacksize��Ϊջ���������MAXSIZE
	return OK;
}

//��ջ
Status Push(SQ_STACK &S, SElemType e) {
	//�ж�ջ�Ƿ�Ϊ�������򷵻�ERROR
	if (S.top - S.base == S.stacksize) {
		printf("ջ����ѹջʧ�ܣ�");
		return ERROR;
	}
	//Ԫ��eѹ��ջ����ջ��ָ���1
	//*S.top++ = e;
	*S.top = e;
	S.top++;
}

//��ջ
Status Pop(SQ_STACK &S, SElemType &e) {
	//�ж�ջ�Ƿ�Ϊ�գ��շ���ERROR
	if (S.base == S.top) {
		printf("ջ����\n");
		return ERROR;
	}
	S.top--;
	e = *S.top;
	return OK;
}
//ȡջ��Ԫ��
SElemType GetTop(SQ_STACK S) {
	if (S.top != S.base) {
		return *(S.top - 1);
	}
}

//����
void traverse_Stack(SQ_STACK S) {
	printf("����������£�\n");
	if (S.top == S.base) {
		printf("ջ�գ�����ʧ�ܣ�\n");
		return;
	}
	//SQ_STACK sq;
	//sq.top = S.top;
	while (S.top != S.base) {
		S.top--;
		printf("%d ", *S.top);
		
	}
	printf("\n");
}