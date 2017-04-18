#include"KMP_H.h"
#include<stdio.h>

int Index_KMP(SSTRING S, SSTRING T, int pos) {
	//����ģʽ��T��next������T������S�еĵ�pos���ַ�֮���λ��
	//����T�ǿգ� 1<=pos<=S.length
	int i = 1; 
	pos = i;
	int j = 1;
	int next[30];
	while (i <= S.length && j <= S.length) {	//��������δ�Ƚϵ���β
		if (j == 0 || S.ch[i] == T.ch[j]) {
			i++; j++;
			if ((j - 1) == T.length) {
				break;
			}
		}

		else {
			get_Next(T, next);
			j = next[j];
		}
	}
	if (j > T.length) {
		printf("ƥ��ɹ���\n");
		pos = i - T.length;
		return pos;
	}
	else {
		printf("ƥ��ʧ�ܣ�\n");
		return 0;
	}
}

void get_Next(SSTRING T, int next[]) {
	//��ģʽ��T��next����ֵ����������next
	int j = 0;
	int i = 1;
	next[1] = 0;
	while (i < T.length) {
		if (j == 0 || T.ch[i] == T.ch[j]) {
			i++;
			j++;
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}
}