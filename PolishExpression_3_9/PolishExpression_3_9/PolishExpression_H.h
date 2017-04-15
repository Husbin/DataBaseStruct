#pragma once
//��ջʵ���������ʽ��ֵ
#define OK true
#define ERROR false
#define OVERFLOW -1
#define MAXSIZE 100

typedef float ElemType;
typedef bool Status;



typedef struct Stack {
	ElemType *base;
	ElemType *top;
	int stacksize;
}STACK;

Status InitStack(STACK &S);
Status StackFull(STACK S);
Status Push(STACK &S, ElemType e);
Status StackEmpty(STACK S);
ElemType Pop(STACK &S);
void PolishExpression();


