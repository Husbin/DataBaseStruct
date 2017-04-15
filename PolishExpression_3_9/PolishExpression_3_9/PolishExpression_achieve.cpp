#include "PolishExpression_H.h"
#include<stdio.h>
#include<stdlib.h>


Status InitStack(STACK &S) {
	S.base = new ElemType[MAXSIZE];
	if (!S.base) {
		printf("�ڴ����ʧ�ܣ�\n");
		exit(OVERFLOW);
	}
	S.top = S.base;
	return OK;
}

Status StackFull(STACK S) {
	if (S.top - S.base == MAXSIZE) {
		return OK;
	}
	else return ERROR;
}

Status Push(STACK &S, ElemType e) {
	if (StackFull(S)) {
		printf("ջ����\n");
		return ERROR;
	}
	*S.top = e;
	S.top++;
	return OK;
}

Status StackEmpty(STACK S) {
	if (S.base == S.top) {
		return OK;
	}
	else return ERROR;
}

ElemType Pop(STACK &S) {
	if (StackEmpty(S)) {
		return ERROR;
	}
	ElemType e;
	S.top--;
	e = *S.top;
	return e;
}
//�沨�����ʽ(����׺���ʽ)��ֵ�������£�����������ջOPND, �Ա��ʽ������ɨ��(����)�������ʽ��ɨ�赽��ʱ��ѹ��OPNDջ��
//��ɨ�赽�����ʱ����OPND�˳���������������Ӧ���㣬�����ѹ��OPNDջ���������һֱ���е��������ʽ������$����ʱOPNDջ��ֻ��һ���������ǽ����
//��$����Ϊ���������������֮���ÿո�ָ�,
//������ֻ������ + �� - ��*�� / �������㡣���磺234 34 + 2 * $��
void PolishExpression() {
	static int i = 0;
	STACK OPND;
	InitStack(OPND);
	static char ch[30];
	printf("��������ʽ����$����Ϊ���������������֮���ÿո�ָ�����\n");
	scanf("%c", &ch[i]);

	float num = 0.00;
	float scale = 0.00;
	float x1 = 0.00, x2 = 0.00;
	while (ch[i] != '$') {
		while ((ch[i] >= '0' && ch[i] <= '9') || ch[i] == '.') {  //ƴ��
			if (ch[i] != '.' && ch[i] != ' ') {				//��������
				num = num * 10 + (ch[i] - '0');
				i++;
				scanf("%c", &ch[i]);
			}
			if (ch[i] == '.') {									//����С�����֡�
				scale = 10.0;
				i++;
				scanf("%c", &ch[i]);
				while (ch[i] >= '0' && ch[i] <= '9') {
					num = num + (ch[i] - '0') / scale;
					scale = scale * 10;
					i++;
					scanf("%c", &ch[i]);
				}
			}
		}
		Push(OPND, num);
		num = 0.0;//��ѹ��ջ���¸�����ʼ��
		scale = 10.0;
		if (ch[i] == '+') {
			Push(OPND, Pop(OPND) + Pop(OPND));
		}
		if (ch[i] == '-') {
			x1 = Pop(OPND); x2 = Pop(OPND); Push(OPND, x2 - x1);
		}
		if (ch[i] == '*') {
			Push(OPND, Pop(OPND)* Pop(OPND));
		}
		if (ch[i] == '/') {
			x1 = Pop(OPND); x2 = Pop(OPND); Push(OPND, x2 / x1);
		}
		i++;
		scanf("%c", &ch[i]);//������ʽ����һ���ַ���
	}
	printf("��׺���ʽ��ֵΪ: %.2f", Pop(OPND));
	printf("\n");
}

