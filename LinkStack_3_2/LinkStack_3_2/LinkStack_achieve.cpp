#include"LinkStack_H.h"
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


//��ջ�ĳ�ʼ��
Status InitLinkStack(LinkStackNode &S) {
	//����һ����ջS��ջ��ָ���ÿ�
	S = NULL;
	return OK;
}

//��ջ��ѹջ
Status Link_Push(LinkStackNode &S, ElemType e) {
	//��ջ������Ԫ��e
	LinkStackNode pNew = (LinkStackNode)malloc(sizeof(StackNode));//�����½ڵ�
	pNew->data = e;
	pNew->pNext = S;	//���½ڵ����ջ��
	S = pNew;			//�޸�ջ��ָ��ΪpNew
	return OK;
}

//��ջ�ĳ�ջ
Status Link_Pop(LinkStackNode &S, ElemType &e) {
	//ɾ��S��ջ��Ԫ�أ���e������ֵ
	if (S == NULL) {
		printf("ջ�գ�\n");
		return ERROR;
	}
	e = S->data;			//����ջ������
	LinkStackNode p = S;	//��p��ʱ����ջ��Ԫ�ؿռ䣬�Ա��ͷ�
	S = S->pNext;			//�޸�ջ��ָ��
	free(p);				//�ͷ�ԭջ��Ԫ�صĿռ�
	return OK;
}

//ȡ��ջ��ջ��Ԫ��
ElemType GetTop(LinkStackNode S) {
	if (S != NULL) {
		return S->data;
	}
	printf("ջ�գ�\n");
}

//��ջ�ı���
void traverse_LinkStack(LinkStackNode S) {
	if (S == NULL) {
		printf("ջ�գ�\n");
		return ;
	}
	LinkStackNode p;
	p = S->pNext;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->pNext;
	}
	printf("\n");
}