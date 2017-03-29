#pragma once

#define MAXSIZE 100			//˳��ջ�洢�ռ�ĳ�ʼ������
#define OK true
#define ERROR false
#define OVERFLOW -1
typedef int SElemType;
typedef bool Status;

//----------------˳��ջ�Ĵ洢�ṹ----------------
typedef struct Stack {
	SElemType *base;		//ջ��ָ��
	SElemType *top;			//ջ��ָ��
	int stacksize;			//ջ�����ɵ��������
}SQ_STACK;

//˳��ջ�ĳ�ʼ��
Status InitStack(SQ_STACK &S);
//˳��ջ����ջ����ջ������һ����Ԫ��
Status Push(SQ_STACK &S , SElemType e);
//˳��ջ�ĳ�ջ����ջ��ɾ��һ��Ԫ��
Status Pop(SQ_STACK &S, SElemType &e);
//ȡջ��Ԫ��
SElemType GetTop(SQ_STACK S);
//˳��ջ�ı���
void traverse_Stack(SQ_STACK S);