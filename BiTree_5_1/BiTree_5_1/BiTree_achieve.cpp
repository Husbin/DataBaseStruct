#include"BiTree_H.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

char CreateBiTree(BiTree &T) {
	char ch;
	//printf("�������ַ�����");
	scanf("%c", &ch);
	if (ch == '#') {			//�ݹ������������(�ڵ�)
		T = NULL;	
	}
	else {
		BiTree T = (BiTree)malloc(sizeof(BiTNode));
		//T = new BiTNode;		//���ɸ��ڵ�
		T->data = ch;			//�������������Ϊch[i]
		CreateBiTree(T->lchild);//�ݹ鴴��������
		CreateBiTree(T->rchild);//�ݹ鴴��������
		return T->data;
	}
}

void InOrderTraverse(BiTree T) {
	if (T) {					//���������ǿ�
		InOrderTraverse(T->lchild);//�������������
		printf("%c", T->data);	//���ʸ��ڵ�
		InOrderTraverse(T->rchild);//�������������
	}
}