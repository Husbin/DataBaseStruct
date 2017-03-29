#pragma once
typedef int ElemType;
typedef bool Status;
#define OK true
#define ERROR false
#define OVERFLOW -1
//-------------��ջ�Ĵ洢�ṹ---------------
typedef struct StackNode {
	ElemType data;
	struct StackNode *pNext;
}StackNode , *LinkStackNode;

//��ջ�ĳ�ʼ��
Status InitLinkStack(LinkStackNode &S);

//��ջ��ѹջ
Status Link_Push(LinkStackNode &S, ElemType e);

//��ջ�ĳ�ջ
Status Link_Pop(LinkStackNode &S, ElemType &e);

//ȡ��ջ��ջ��Ԫ��
ElemType GetTop(LinkStackNode S);

//��ջ�ı���
void traverse_LinkStack(LinkStackNode S);