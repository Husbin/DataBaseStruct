#pragma once

//
typedef char ElemType;
typedef bool Status;

#define MAXSIZE 100
#define OK true
#define ERROR false
#define OVERFLOW -1


//----------------˳��ջ�Ĵ洢�ṹ--------------------------
typedef struct Stack {
	ElemType *base;
	ElemType *top;
	int stacksize;
}STACK;


//��ʼ��˳��ջ
Status InitStack(STACK &S);
//˳��ջ����ջ
Status Push(STACK &S , ElemType e);
//˳��ջ�ĳ�ջ
Status Pop(STACK &S, ElemType &e);
//��ȡջ��Ԫ��
ElemType getTop(STACK S);
//���ŵ�ƥ��
Status Matching();
