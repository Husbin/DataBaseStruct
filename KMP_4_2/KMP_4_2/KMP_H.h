#pragma once
//���Ĵ洢�ṹ
//---------------------���Ķ���˳��洢�ṹ-----------------
//�±�Ϊ0��Ԫ�����á�
#define MAXSIZE 255
typedef struct {
	char ch[MAXSIZE + 1];
	int length;
} SSTRING;

int Index_KMP(SSTRING S, SSTRING T, int pos);
void get_Next(SSTRING T, int next[]);