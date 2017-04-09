#pragma once
//˳��ջʵ�ֽ���ת��
#define MAXSIZE 100		//˳��ջ�洢�ռ�ĳ�ʼ��������
#define OK true
#define ERROR false
#define OVERFLOW -1
typedef int ElemType;
typedef bool Status;


//-----------------------˳��ջ�Ĵ洢�ṹ---------------------
typedef struct Stack {
	ElemType *base;			//ջ��ָ��
	ElemType *top;			//ջ��ָ��
	int stacksize;			//ջ�����ɵ��������
}SQ_STACK;

//˳��ջ�ĳ�ʼ��
Status InitStack(SQ_STACK &S);
//˳��ջ����ջ����ջ������һ����Ԫ��
Status Push(SQ_STACK &S, ElemType e);
//˳��ջ�ĳ�ջ����ջ��ɾ��һ��Ԫ��
Status Pop(SQ_STACK &S, ElemType &e);
//����ת��,ʮ����ת��Ϊ�˽���
void conversion(int N);