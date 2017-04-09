#include"Conversion_H.h"
#include"stdlib.h"
#include"stdio.h"

Status InitStack(SQ_STACK &S) {
	S.base = new ElemType[MAXSIZE];			//Ϊ˳��ջ��̬����һ���������ΪMAXSIZE������ռ�
	if (!S.base) {
		printf("�ڴ����ʧ�ܣ�\n");
		exit(OVERFLOW);
	}
	S.top = S.base;							//top��ʼ��Ϊbase,��ջ
	S.stacksize = MAXSIZE;					//stacksize��Ϊջ���������MAXSIZE
	return OK;
}

Status Push(SQ_STACK &S, ElemType e) {
	//�ж�ջ�Ƿ�Ϊջ�����򷵻�ERROR
	if (S.top - S.base == S.stacksize) {
		printf("ջ����ѹջʧ�ܣ�\n");
			return ERROR;
	}
	//Ԫ��eѹ��ջ����ջ��ָ���1
	//*S.top ++= e;
	*S.top = e;
	S.top++;
}

Status Pop(SQ_STACK &S, ElemType &e) {
	if (S.top == S.base) {
		printf("ջ�գ�\n");
		exit(OVERFLOW);
	}
	S.top--;
	e = *S.top;
	return OK;
}

void conversion(int N) {
	SQ_STACK S;
	int e;
	InitStack(S);
	while (N) {
		Push(S, N % 2);
		N = N / 2;
	}
	while (S.base != S.top) {
		Pop(S, e);
		printf("%d ", e);
	}
	printf("\n");
}