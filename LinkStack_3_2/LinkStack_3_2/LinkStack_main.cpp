#include<stdio.h>
#include"LinkStack_H.h"
int main() {
	LinkStackNode S;
	int val;
	InitLinkStack(S);
	Link_Push(S, 1);
	Link_Push(S, 2);
	Link_Push(S, 3);
	Link_Push(S, 4);
	Link_Push(S, 5);
	traverse_LinkStack(S);
	val = GetTop(S);
	printf("ջ��Ԫ��Ϊ��%d \n" , val);
	Link_Pop(S, val);
	printf("��ջ�ɹ���ȡ����Ԫ��Ϊ��%d \n" , val);
	traverse_LinkStack(S);
	val = GetTop(S);
	printf("ջ��Ԫ��Ϊ��%d \n", val);
}