#include "Matching_H.h"
#include "stdio.h"
#include "stdlib.h"

Status InitStack(STACK &S) {
	S.base = new ElemType[MAXSIZE];
	if (S.base == NULL) {
		printf("�ڴ����ʧ�ܣ�\n");
		exit(OVERFLOW);
	}
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}

Status Push(STACK &S , ElemType e) {
	if (S.top - S.base == MAXSIZE) {
		printf("ջ����\n");
		return ERROR;
	}
	*S.top = e;
	S.top++;
	return OK;
}

Status Pop(STACK &S, ElemType& e) {
	if (S.top == S.base) {
		printf("ջ�գ�\n");
		return ERROR;
	}
	S.top--;
	e = *S.top;
	return OK;
}

ElemType getTop(STACK S) {
	//ȡջ��Ԫ��
	if (S.top != S.base) {
		return *(S.top - 1);
	}
}

Status Matching() {
	//������ʽ�������������Ƿ���ȷƥ�䣬���ƥ�䣬����true�����򷵻�false
	//���ʽ�� # ����
	STACK S;
	char ch ;					//�����ַ�
	char x;
	InitStack(S);
	int flag = 1;					//���ƥ�����Կ���ѭ�������ؽ��
	scanf("%c", &ch);
	while (ch != '#' && flag == 1) {		//���ʽ�� # ��β
		switch (ch) {
		case '(':					//���������ţ�����ѹ��ջ
		case '[':
			Push(S, ch);
			break;
		case ')':					//���ǡ�����������ݵ�ǰջ��Ԫ�ص�ֵ���������
			if (S.base != S.top && getTop(S) == '(') {
				Pop(S, x);			//��ջ�ǿ���ջ��Ԫ���ǡ�����������ȷƥ��
				//printf("%c", getTop(S));
				//printf("%c\n", x);
			}
			else flag = 0;			//��ջ�ջ�ջ��Ԫ�ز��ǡ������������ƥ��
			break;
		case ']':					//���ǡ�]��������ݵ�ǰվ��Ԫ�ص�ֵ���������
			if (S.base != S.top && getTop(S) == '[') {
				Pop(S, x);			//��ջ�ǿ���ջ��Ԫ���ǡ�[��������ȷƥ��
				//printf("%c", getTop(S));
				//printf("%c\n", x);
			}
			else flag = 0;			//��ջ�ջ�ջ��Ԫ�ز��ǡ�[���������ƥ��
			break;
		}
		scanf("%c", &ch);
	}
	if (S.base == S.top && flag == 1) {
		printf("ƥ��ɹ���\n");
		return true; 
	}
	else {
		printf("ƥ��ʧ�ܣ�\n");
		return false;
	}
}