#include"BruteForce_H.h"
#include<stdio.h>
#include<stdlib.h>

int Index_BF(SSTRING S, SSTRING T, int &pos) {
	//����ģʽT������S�е�pos���ַ���ʼ��һ�γ��ֵ�λ�á��������ڣ�����ֵΪ0
	int i = 1;
	int j = 1;

	while (i <= S.length && j <= T.length) {	//��������δ�Ƚϵ���β
		if (S.ch[i] == T.ch[j]) {
			//�����ȽϺ�̵��ַ�
			i++;
			j++;
		}
		else {
			//ָ��������¿�ʼƥ��
			i = i - j + 2;
			j = 1;
		}
	}
	if (j > T.length) {
		pos = i - T.length;
		return pos;	//ƥ��ɹ�
	}
	else return 0;							//ƥ��ʧ��
}