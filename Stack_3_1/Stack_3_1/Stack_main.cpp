#include"Stack_H.h"
#include<stdio.h>

int main() {
	SQ_STACK S;
	int val;
	int topVal;
	InitStack(S);
	Push(S, 1);
	Push(S, 2);
	Push(S, 3);
	Push(S, 4);
	Push(S, 5);
	Push(S, 6);
	topVal = GetTop(S);
	printf("ջ����Ԫ����%d\n", topVal);
	traverse_Stack(S);
	Pop(S , val);
	printf("ִ�г�ջ��������ջ��Ԫ���ǣ�%d\n", val);
	traverse_Stack(S);
	topVal = GetTop(S);
	printf("ջ����Ԫ����%d\n", topVal);
	return 0;
}